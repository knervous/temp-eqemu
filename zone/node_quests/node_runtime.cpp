#include "node_snapshot_builder.h"
#include "node_runtime.h"
#include <thread>
#include "node_process.h"
#include "questinterface/questinterface_wrap.cxx"
#include "zone.h"

extern Zone *zone;

#ifdef _WINDOWS
const char libext[] = ".dll";
#elif __APPLE__
const char libext[] = ".dylib";
#else
const char libext[] = ".so";
#endif

void _Perl_switch_locale_context(void)
{
	// No operation (NOP)
	// Depending on what Perl_switch_locale_context is supposed to do, you might need to implement
	// some form of handling here. If it's critical for managing locale contexts in Perl interactions,
	// consider providing a minimal implementation that aligns with your application's needs.
}

namespace node
{
	const SnapshotData *SnapshotBuilder::GetEmbeddedSnapshotData()
	{
		return nullptr;
	}
} // namespace node

v8::Persistent<Context> context_;
v8::Isolate *isolate_;
uv_async_t async_;
uv_loop_t loop_;
node::Environment* env_ = nullptr;
std::promise<void> shutdownPromise_;

void NodeRuntime::StopExecution()
{
	if (script_running_)
	{
		struct payload* p = new payload();
		p->type = new std::string("stop");
		async_.data = (void*)p;
		uv_async_send(&async_);
	}
}

void NodeRuntime::Init()
{
	std::vector<std::string> args{"None"};
	std::vector<std::string> exec_args{};
	std::vector<std::string> errors;

	// Parse Node.js CLI options, and print any errors that have occurred while
	// trying to parse them.
	std::unique_ptr<node::InitializationResult> result =
		node::InitializeOncePerProcess(args, {node::ProcessInitializationFlags::kNoInitializeV8,
											  node::ProcessInitializationFlags::kNoInitializeNodeV8Platform});

	for (const std::string &error : result->errors())
		fprintf(stderr, "%s: %s\n", args[0].c_str(), error.c_str());
	if (result->early_return() != 0)
	{
		return;
	}

	// Create a v8::Platform instance. `MultiIsolatePlatform::Create()` is a way
	// to create a v8::Platform instance that Node.js can use when creating
	// Worker threads. When no `MultiIsolatePlatform` instance is present,
	// Worker threads are disabled.
	platform_ =
		MultiIsolatePlatform::Create(4);
	V8::InitializePlatform(platform_.get());
	V8::Initialize();
}

void NodeRuntime::Dispose()
{
	try
	{
		{
			V8::Dispose();
			platform_->~MultiIsolatePlatform();
			isolate_ = nullptr;
			halt_exec_ = nullptr;
		}
	}
	catch (...)
	{
	}
}

void NodeRuntime::ModuleLoad(const std::string &module_path)
{
	return Eval(module_path);
}

void NodeRuntime::SetRunningScript(std::string eval)
{
	running_script_ = eval;
}

void NodeRuntime::Reload()
{
	if (!script_running_)
	{
		return;
	}
	struct payload *p = new payload();
	p->type = new std::string("reload");
	async_.data = (void *)p;
	uv_async_send(&async_);
}

void NodeRuntime::OnZoneEvent(const char *type)
{
	if (!script_running_)
	{
		return;
	}
	struct payload *p = new payload();
	p->data = new std::string(type);
	p->type = new std::string("zone");
	async_.data = (void *)p;
	uv_async_send(&async_);
}

void NodeRuntime::OnNpcEvent(QuestEventID evt, NPC *npc, Mob *init, std::string data) {
	if (!script_running_)
	{
		return;
	}
	struct payload *p = new payload();
	p->data = new npc_event {
		(int)evt, npc, init, data
	};
	p->type = new std::string("npc_event");
	async_.data = (void *)p;
	uv_async_send(&async_);
}

void NodeRuntime::OnChatEvent(const char *line)
{
	if (!script_running_)
	{
		return;
	}
	struct payload *p = new payload();
	p->data = new std::string(line);
	p->type = new std::string("chat");
	async_.data = (void *)p;
	uv_async_send(&async_);
}

void DoCallback(uv_async_t *handle){
	{v8::Unlocker unlock(isolate_);
{
	Locker lock(isolate_);
	Isolate::Scope isolate_scope(isolate_);
	v8::HandleScope scope(isolate_);
	auto context = isolate_->GetCurrentContext();
	auto global = context->Global();

	struct payload *p = (struct payload *)handle->data;
	if (p == nullptr || p->type == nullptr) {
		return;
	}
	auto type = (std::string)*p->type;
	try
	{
		if (type == "stop")
		{
			if (env_) {
				uv_close((uv_handle_t*)&async_, NULL);
				uv_stop(&loop_);
			}
		}
		else if (type == "reload")
		{
			Local<Value> args[] = {};
			v8::Local<v8::Value> reload_listener;
			if (!global->Get(
						   context, GetLocalName(isolate_, "reloadListener"))
					 .ToLocal(&reload_listener))
			{
				return;
			}
			reload_listener.As<v8::Function>()->Call(context, context->Global(), 0, args);
		}	
		else if (type == "zone")
		{
			auto zone_event = (std::string *)p->data;
			Local<Value> args[] = {GetLocalName(isolate_, zone_event->c_str())};
			v8::Local<v8::Value> zone_listener;
			if (!global->Get(
						   context, GetLocalName(isolate_, "zoneListener"))
					 .ToLocal(&zone_listener))
			{
				return;
			}
			zone_listener.As<v8::Function>()->Call(context, context->Global(), 1, args);
		}
		else if (type == "chat")
		{
			auto chat_text = (std::string *)p->data;
			Local<Value> args[] = {GetLocalName(isolate_, chat_text->c_str())};
			v8::Local<v8::Value> chat_listener;
			if (!global->Get(
						   context, GetLocalName(isolate_, "chatListener"))
					 .ToLocal(&chat_listener))
			{
				return;
			}
			chat_listener.As<v8::Function>()->Call(context, context->Global(), 1, args);
		} else if (type == "npc_event") {
			auto event = (npc_event *)p->data;
			SWIGV8_HANDLESCOPE();

			Local<Value> args[] = {
				SWIG_NewPointerObj(SWIG_as_voidptr(zone), SWIGTYPE_p_Zone, 0 | 0),
				 v8::Integer::New(isolate_, (int32_t)event->event),
				SWIG_NewPointerObj(SWIG_as_voidptr(event->npc), SWIGTYPE_p_NPC, 0 | 0),
				SWIG_NewPointerObj(SWIG_as_voidptr(event->mob), SWIGTYPE_p_Mob, 0 | 0),
				GetLocalName(isolate_, (event->data).c_str())
			};
			v8::Local<v8::Value> npc_event_listener;
			if (!global->Get(
						   context, GetLocalName(isolate_, "npcEvent"))
					 .ToLocal(&npc_event_listener))
			{
			} else {
				npc_event_listener.As<v8::Function>()->Call(context, context->Global(), 5, args);

			}
		}
	}
	catch (...)
	{
	}

	delete p->data;
	p->data = nullptr;
	delete p->type;
	p->type = nullptr;
}
}
}
;

void NodeRuntime::Eval(const std::string &module_path)
{
	module_path_ = module_path;
	allow_execution_ = true;
	{
		//int ret = uv_loop_init(&loop_);

		const std::vector<std::string> &args{"", "--no-hard-abort"};
		const std::vector<std::string> &exec_args{

			};

		const std::vector<std::string> &module_args{
			"",
			module_path_,
			"--no-hard-abort"};
			
		// Setup up a libuv event loop, v8::Isolate, and Node.js Environment.
		std::vector<std::string> errors;
		std::unique_ptr<CommonEnvironmentSetup> setup =
			CommonEnvironmentSetup::Create(platform_.get(), &errors, module_args, exec_args);
		if (!setup)
		{
			for (const std::string &err : errors)
				fprintf(stderr, "%s: %s\n", args[0].c_str(), err.c_str());
			return;
		}

		isolate_ = setup->isolate();
		Environment *env = setup->env();
	
		isolate_->SetFatalErrorHandler([](const char *location, const char *message) -> void
									   { std::printf(message); });
		{
			Locker lock(isolate_);
			Isolate::Scope isolate_scope(isolate_);
			HandleScope handle_scope(isolate_);
			Local<Context> context = setup->context();
			Context::Scope context_scope(context);
			v8::TryCatch try_catch(isolate_);

			// Prepend local require
			std::string inject = "";
			std::string global_require("");
			std::replace(global_require.begin(), global_require.end(), '\\', '/');
			global_require += "/";
			inject =
				inject + "const publicRequire = require('module').createRequire(`" +
				global_require.c_str() + "`); globalThis.require = publicRequire;";

			inject += running_script_.c_str();

			MaybeLocal<Value> loadenv_ret = node::LoadEnvironment(env, node::StartExecutionCallback{});

			if (try_catch.HasCaught())
			{
				String::Utf8Value exception(
					isolate_,
					try_catch.Exception()->ToString(context).ToLocalChecked());
				String::Utf8Value stack_trace(
					isolate_, try_catch.StackTrace(context).ToLocalChecked());
				script_running_ = false;
				return;
			}
			SWIGV8_INIT(v8::Object::New(isolate_), v8::Object::New(isolate_), context, nullptr);

			script_running_ = true;

			isolate_->AddMessageListener([](Local<v8::Message> message, Local<Value> data) -> void
										 {
											 String::Utf8Value utf8_message(v8::Isolate::GetCurrent(), message->Get());
											 std::string line = "Error occurred on line ";
											 line += std::to_string(message->GetLineNumber(v8::Isolate::GetCurrent()->GetCurrentContext()).ToChecked()); });
			String::Utf8Value utf8(isolate_, loadenv_ret.ToLocalChecked());
			env_ = env;
			std::printf(*utf8);
			{	
				uv_async_init(setup->event_loop(), &async_, reinterpret_cast<uv_async_cb>(DoCallback));
				auto exit_code = node::SpinEventLoop(env).FromMaybe(1);

				node::Stop(env);
			}
		}

		// Clear and cleanup
		script_running_ = false;
		halt_exec_ = nullptr;
	}
}

v8::Local<v8::String> GetLocalName(v8::Isolate *isolate, const char *key)
{
	return v8::String::NewFromUtf8(isolate, key, v8::NewStringType::kInternalized)
		.ToLocalChecked();
}

void GetEmuGlobal(Local<v8::String> name,
				  const v8::PropertyCallbackInfo<Value> &info)
{
	auto isolate = info.GetIsolate();
	auto context = isolate->GetCurrentContext();

	v8::Local<v8::External> ext = info.Data().As<v8::External>();

	auto obj = v8::Object::New(isolate);

	// Methods
	// obj->DefineOwnProperty(
	// 	context,
	// 	GetLocalName(isolate, "log"),
	// 	v8::Function::New(context, ConsoleLog).ToLocalChecked());

	info.GetReturnValue().Set(obj);
}

v8::Local<v8::ObjectTemplate> GetObjectTemplate(Isolate *isolate, NodeRuntime *node_runtime)
{
	v8::Local<v8::ObjectTemplate> global_templ = v8::ObjectTemplate::New(isolate);

	global_templ->SetAccessor(GetLocalName(isolate, "eqemu"), GetEmuGlobal, nullptr, v8::External::New(isolate, node_runtime));

	return global_templ;
}

template <typename T>
v8::Local<v8::Value> cast_to_js(const v8::PropertyCallbackInfo<Value> &info,
								T val)
{
	auto isolate = info.GetIsolate();
	try
	{
		if constexpr (std::is_same<T, int>::value)
		{
			return v8::Integer::New(isolate, (int32_t)val);
		}
		else if constexpr (std::is_same<T, long>::value)
		{
			return v8::Integer::New(isolate, (long)val);
		}
		else if constexpr (std::is_same<T, long long>::value)
		{
			return v8::Integer::New(isolate, (long)val);
		}
		else if constexpr (std::is_same<T, const char *>::value)
		{
			return GetLocalName(isolate, (const char *)val);
		}
		else if constexpr (std::is_same<T, std::string>::value)
		{
			return GetLocalName(isolate, ((std::string)val).c_str());
		}
		else
		{
			return GetLocalName(isolate, ((const char *)val));
		}
	}
	catch (...)
	{
		return v8::Null(isolate);
	}
}
