#pragma once

#define NODE_WANT_INTERNALS true

#include <type_traits>
#include <future>

#include <assert.h>
#include "node.h"
#include "node_errors.h"
#include "node_internals.h"
#include "node_quest_interface.h"
#include "env-inl.h"
#include "v8-util.h"
#include "uv.h"

using node::ArrayBufferAllocator;
using node::CommonEnvironmentSetup;
using node::Environment;
using node::IsolateData;
using node::MultiIsolatePlatform;
using node::errors::TryCatchScope;
using v8::Context;
using v8::HandleScope;
using v8::Isolate;
using v8::Local;
using v8::Locker;
using v8::MaybeLocal;
using v8::SealHandleScope;
using v8::String;
using v8::Unlocker;
using v8::V8;
using v8::Value;

struct payload
{
    std::string *type;
    void *data;
};

class NodeRuntime
{

public:
    NodeRuntime(NodeParser* np){
        this->quest_interface_ = np;
    };
    ~NodeRuntime() = default;

    void Eval(const std::string& module_path = "");
    void ModuleLoad(const std::string& module_path);
    void Init();
    void Dispose();
    void Reload();
    void StopExecution();
    void SetRunningScript(std::string eval);

    const bool GetIsRunning() { return script_running_; };
    void OnNpcEvent(QuestEventID evt, NPC *npc, Mob *init, std::string data);
    void OnZoneEvent(const char *type);
    void OnChatEvent(const char *line);
    NodeParser* GetQuestInterface() {
        return quest_interface_;
    }

private:
    std::unique_ptr<MultiIsolatePlatform> platform_;
    v8::ArrayBuffer::Allocator* allocator_;
    std::function<void()> halt_exec_;

    std::string running_script_;
    std::string module_path_;
    std::string exec_path_;
    NodeParser* quest_interface_;
    std::vector<std::function<void(Isolate *isolate, v8::Local<v8::Context> context)>> pending_tasks_;
    bool allow_execution_ = true;
    bool module_load_ = false;
    bool debug_ = false;
    bool script_running_ = false;
};

v8::Local<v8::String> GetLocalName(v8::Isolate *isolate, const char *key);

void GetEmuGlobal(Local<v8::String> name,
                  const v8::PropertyCallbackInfo<Value> &info);

v8::Local<v8::ObjectTemplate> GetObjectTemplate(Isolate *isolate, NodeRuntime *node_runtime);

template <typename T>
v8::Local<v8::Value> cast_to_js(const v8::PropertyCallbackInfo<Value> &info,
                                T val);