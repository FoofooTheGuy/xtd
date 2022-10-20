#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/speech_synthesizer.h>
#include <xtd/native/file_permission.h>
#include <xtd/native/file_system.h>
#include <xtd/native/process.h>
#include <xtd/native/process_window_style.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>

using namespace std;
using namespace xtd::native;

namespace {
  struct speech_synthesizer_data {
    string say_cmd_file_name;
    intptr_t process_handle = 0;
  };

  static string get_temp_path() {
    auto tmp_path = getenv("TMPDIR");
    return tmp_path ? tmp_path : "/tmp/";
  }

  static string get_unique_speak_cmd_file_name() {
    static int32_t cpt = 0;
    stringstream ss;
    ss << get_temp_path() << "/__xtd_speech_synthesizer_speak_process_" << ++cpt << "__.cmd";
    return  ss.str();
  }
}

intptr_t speech_synthesizer::create() {
  speech_synthesizer_data* data = new speech_synthesizer_data {get_unique_speak_cmd_file_name(), 0};
  ofstream cmd_file;
  cmd_file.open(data->say_cmd_file_name);
#if (__APPLE__)
  cmd_file << "say \"$*\"\n";
#else
  cmd_file << "spd-say \"$*\"\n");
#endif
  cmd_file.close();
  native::file_system::set_permissions(data->say_cmd_file_name, FILE_PERMISSIONS_OWNER_ALL);
  return reinterpret_cast<intptr_t>(data);
}

void speech_synthesizer::destroy(intptr_t handle) {
  unlink(reinterpret_cast<speech_synthesizer_data*>(handle)->say_cmd_file_name.c_str());
  delete reinterpret_cast<speech_synthesizer_data*>(handle);
}

void speech_synthesizer::speak(intptr_t handle, const string& text_to_speak) {
  speak_async(handle, text_to_speak);
  int32_t exit_code = 0;
  native::process::wait(reinterpret_cast<speech_synthesizer_data*>(handle)->process_handle, exit_code);
}

void speech_synthesizer::speak_async(intptr_t handle, const string& text_to_speak) {
  reinterpret_cast<speech_synthesizer_data*>(handle)->process_handle = native::process::shell_execute("", reinterpret_cast<speech_synthesizer_data*>(handle)->say_cmd_file_name, text_to_speak, "", PROCESS_WINDOW_STYLE_HIDDEN);
}
