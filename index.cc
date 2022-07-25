#include <napi.h>
#include <windows.h>

char window_title[256];

Napi::String Method(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  HWND foreground = GetForegroundWindow();

  if (foreground)
  {
      GetWindowText(foreground, window_title, 256);
  }

  return Napi::String::New(env, window_title);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "find"), Napi::Function::New(env, Method));
  return exports;
}

NODE_API_MODULE(index, Init)
