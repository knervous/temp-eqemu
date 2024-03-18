%fragment("js_function_dispatcher", "templates")
%{
static SwigV8ReturnValue $jswrapper(const SwigV8Arguments &args) {
    SWIGV8_HANDLESCOPE();

    SWIGV8_VALUE jsresult;
    OverloadErrorHandler errorHandler;
    $jscode
    if (!errorHandler.err.IsEmpty()) {
      SWIGV8_THROW_EXCEPTION(errorHandler.err);
    }
    else {
      SWIG_exception_fail(SWIG_ERROR, "Illegal arguments for function $jsname");
    }

    goto fail;
    fail:
    SWIGV8_RETURN(SWIGV8_UNDEFINED());
}
%}

%typemap(in) int* {
	if ($input->IsInt32Array()) {
    v8::Local<v8::Int32Array> myarr = $input.As<v8::Int32Array>();
    $1 = (int*)((int*)myarr->Buffer()->GetBackingStore()->Data() + myarr->ByteOffset());
  } else {
    SWIG_exception_fail(SWIG_ArgError(SWIG_TypeError), "Illegal argument '$argnum' must be of type '""Int32Array""'");
  }
}

%typemap(in) double* {
	if ($input->IsFloat64Array()) {
    v8::Local<v8::Float64Array> myarr = $input.As<v8::Float64Array>();
    $1 = (double*)((double*)myarr->Buffer()->GetBackingStore()->Data() + myarr->ByteOffset());
  } else {
    SWIG_exception_fail(SWIG_ArgError(SWIG_TypeError), "Illegal argument '$argnum' must be of type '""Float64Array""'");
  }
}

%typemap(in) unsigned char* {
	if ($input->IsUint8Array()) {
    v8::Local<v8::Uint8Array> myarr = $input.As<v8::Uint8Array>();
    $1 = (unsigned char*)((unsigned char*)myarr->Buffer()->GetBackingStore()->Data() + myarr->ByteOffset());
  } else {
    SWIG_exception_fail(SWIG_ArgError(SWIG_TypeError), "Illegal argument '$argnum' must be of type '""Uint8Array""'");
  }
}

%typemap(in) char** {
	if ($input->IsArray()) {
    SWIGV8_ARRAY array = SWIGV8_ARRAY::Cast($input);
    char** c_arr = new char*[array->Length()];
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    for (uint32_t i = 0; i < array->Length(); i++) {
      if (SWIGV8_ARRAY_GET(array, i)->IsString()) {
        v8::String::Utf8Value value(isolate, SWIGV8_TO_STRING(SWIGV8_ARRAY_GET(array, i)));
        auto c_str = new char[value.length() + 1];
        strcpy(c_str, *value);
        c_arr[i] = c_str;
      } else {
        SWIG_exception_fail(SWIG_ArgError(SWIG_TypeError), "Illegal value type in Array");
      }
    }
    $1 = c_arr;
  } else {
    SWIG_exception_fail(SWIG_ArgError(SWIG_TypeError), "Illegal argument '$argnum' must be of type '""Array""'");
  }
}

%typemap(freearg) char** data {
  for (uint32_t i = 0; i < SWIGV8_ARRAY::Cast($input)->Length(); ++i) {
    delete[] $1[i];
  }
  delete[] $1;
}

// Typedefs
%include <stdint.i>

typedef uint8_t byte;
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;
typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;

// In typemaps (JavaScript to C/C++)
%typemap(jstype) byte, uint8, uint16, uint32, uint64, int8, int16, int32, int64 "number";
%typemap(jsin) byte, uint8, uint16, uint32, uint64, int8, int16, int32, int64 "$input";

// Out typemaps (C/C++ to JavaScript)
%typemap(jsout) byte, uint8, uint16, uint32, uint64 {
    $result = SWIG_NewNumberObj($1);
}
%typemap(jsout) int8, int16, int32 {
    $result = SWIG_NewNumberObj($1);
}
%typemap(jsout) int64, uint64 {
    // For large integers, consider returning a string to prevent precision loss,
    // or use specific JavaScript libraries for large integers.
    $result = SWIG_ToString($1);
}


%typemap(in) enum SWIGTYPE* {
	if ($input->IsInt32Array()) {
    v8::Local<v8::Int32Array> myarr = $input.As<v8::Int32Array>();
    $1 = ($1_ltype)((int*)myarr->Buffer()->GetBackingStore()->Data() + myarr->ByteOffset());
  } else {
    SWIG_exception_fail(SWIG_ArgError(SWIG_TypeError), "Illegal argument '$argnum' must be of type '""Int32Array""'");
  }
}

%typemap(out) SWIGTYPE
{
  $result = SWIG_NewPointerObj(new $1_ltype(std::move($1)), $&1_descriptor, SWIG_POINTER_OWN |  0 );
}
