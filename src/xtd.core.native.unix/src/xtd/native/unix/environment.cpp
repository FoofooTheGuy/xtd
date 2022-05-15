#include <cstdio>
#include <cstdlib>
#include <numeric>
#include <thread>

#if defined(__APPLE__)
#include "TargetConditionals.h"
#include <time.h>
#include <sys/sysctl.h>
#else
#include <sys/sysinfo.h>
#endif
#include <sys/param.h>
#include <unistd.h>

#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/environment.h>
#include "../../../../include/xtd/native/unix/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd::native;

extern char** environ;
int32_t __environment_argc;
char** __environment_argv;

namespace {
  static std::string create_process(const std::string& command) {
    auto fs = popen(command.c_str(), "r");
    std::string result;
    while (!feof(fs)) {
      char buf[513];
      size_t l = fread(buf, 1, 512, fs);
      buf[l] = 0;
      result += buf;
    }
    pclose(fs);
    return result;
  }
  
  __attribute__((constructor)) void startup_program(int32_t argc, char** argv) {
    __environment_argc = argc;
    __environment_argv = argv;
  }
}

std::vector<std::string> environment::get_command_line_args() {
  return {__environment_argv, __environment_argv + __environment_argc};
}

std::string environment::get_desktop_environment() {
  #if defined(__APPLE__)
  return "macos";
  #else
  auto current_desktop = get_environment_variable("XDG_CURRENT_DESKTOP");
  if (current_desktop == "") current_desktop = get_environment_variable("XDG_DATA_DIRS");
  for (auto environment_desktop : {"budgie", "cinnamon", "deepin", "Enlightenment", "étoilé", "gnome", "kde", "lxqt", "mate", "pantheon", "razor", "unity", "xfce"}) {
    if (unix::strings::contains(unix::strings::to_lower(current_desktop), environment_desktop)) return environment_desktop;
  }
  return "";
  #endif
}

std::string environment::get_desktop_theme() {
#if defined(__APPLE__)
  return unix::strings::contains(create_process("defaults read -g AppleInterfaceStyle"), "Dark" ) ? "macos dark" : "macos";
#else
  auto current_theme = create_process("gsettings get org.gnome.desktop.interface gtk-theme");
  if (!current_theme.emepty())
    current_theme = unix::strings::substring(current_theme, 1, current_theme.size() - 2);
  return current_theme;
#endif
}

std::string environment::get_environment_variable(const std::string& variable) {
  auto value = getenv(variable.c_str());
  return value ? value : "";
}

std::map<std::string, std::string>& environment::get_environment_variables(int32_t target) {
  if (target == ENVIRONMENT_VARIABLE_TARGET_PROCESS) {
    static std::map<std::string, std::string> envs;
    if (envs.size() == 0) {
      for (size_t index = 0; environ[index] != nullptr; index++) {
        std::vector<std::string> key_value = unix::strings::split(environ[index], {'='});
        if (key_value.size() == 2)
          envs[key_value[0]] = key_value[1];
      }
    }
    return envs;
  }
  
  if (target == ENVIRONMENT_VARIABLE_TARGET_USER || target == ENVIRONMENT_VARIABLE_TARGET_MACHINE) {
    static std::map<std::string, std::string> envs;
    envs.clear();
    //microsoft::win32::registry_key key = target == environment_variable_target::user ? microsoft::win32::registry::current_user().create_sub_key("Environment") : microsoft::win32::registry::local_machine().create_sub_key("System").create_sub_key("CurrentControlSet").create_sub_key("Control").create_sub_key("Session Manager").create_sub_key("Environment");
    //for (auto name : key.get_value_names())
    //  envs[name] = key.get_value(name).to_string();
    return envs;
  }
  
  static std::map<std::string, std::string> envs;
  return envs;
}

std::string environment::get_know_folder_path(int32_t csidl) {
  #if defined(__APPLE__)
  static std::map<int32_t, std::string> special_folders = {{CSIDL_DESKTOP, get_environment_variable("HOME") + "/Desktop"}, {CSIDL_PERSONAL, get_environment_variable("HOME")}, {CSIDL_FAVORITES, get_environment_variable("HOME") + "/Library/Favorites"}, {CSIDL_MYMUSIC, get_environment_variable("HOME") + "/Music"}, {CSIDL_MYVIDEO, get_environment_variable("HOME") + "/Videos"}, {CSIDL_DESKTOPDIRECTORY, get_environment_variable("HOME") + "/Desktop"}, {CSIDL_FONTS, get_environment_variable("HOME") + "/Library/Fonts"}, {CSIDL_TEMPLATES, get_environment_variable("HOME") + "/Templates"}, {CSIDL_APPDATA, get_environment_variable("HOME") + "/.config"}, {CSIDL_LOCAL_APPDATA, get_environment_variable("HOME") + "/.local/share"}, {CSIDL_INTERNET_CACHE, get_environment_variable("HOME") + "/Library/Caches"}, {CSIDL_COMMON_APPDATA, "/usr/share"}, {CSIDL_SYSTEM, "/System"}, {CSIDL_PROGRAM_FILES, "/Applications"}, {CSIDL_MYPICTURES, get_environment_variable("HOME") + "/Pictures"}, {CSIDL_PROFILE, get_environment_variable("HOME")}, {CSIDL_COMMON_TEMPLATES, "/usr/share/templates"}, {CSIDL_HOME, get_environment_variable("HOME")}};
  #else
  static std::map<int32_t, std::string> special_folders = {{CSIDL_DESKTOP, get_environment_variable("HOME") + "/Desktop"}, {CSIDL_PERSONAL, get_environment_variable("HOME")}, {CSIDL_MYMUSIC, get_environment_variable("HOME") + "/Music"}, {CSIDL_MYVIDEO, get_environment_variable("HOME") + "/Videos"}, {CSIDL_DESKTOPDIRECTORY, get_environment_variable("HOME") + "/Desktop"}, {CSIDL_FONTS, get_environment_variable("HOME") + "/.fonts"}, {CSIDL_TEMPLATES, get_environment_variable("HOME") + "/Templates"}, {CSIDL_APPDATA, get_environment_variable("HOME") + "/.config"}, {CSIDL_LOCAL_APPDATA, get_environment_variable("HOME") + "/.local/share"}, {CSIDL_COMMON_APPDATA, "/usr/share"}, {CSIDL_MYPICTURES, get_environment_variable("HOME") + "/Pictures"}, {CSIDL_PROFILE, get_environment_variable("HOME")}, {CSIDL_COMMON_TEMPLATES, "/usr/share/templates"}, {CSIDL_HOME, get_environment_variable("HOME")}};
  #endif
  auto it = special_folders.find(csidl);
  if (it == special_folders.end()) return "";
  return it->second;
}

std::string environment::get_machine_name() {
  return unix::strings::replace(create_process("uname -n"), "\n", "");
}

int32_t environment::get_os_platform_id() {
  #if defined(__APPLE__)
  #if TARGET_OS_SIMULATOR == 1 || TARGET_OS_IPHONE == 1
  return PLATFORM_IOS;
  #else
  return PLATFORM_MACOS;
  #endif
  #else
  #if defined(__ANDROID__)
  return PLATFORM_ANDROID;
  #else
  return create_process("uname -a").find("Linux") != std::string::npos ? PLATFORM_LINUX : PLATFORM_UNIX;
  #endif
  #endif
}

void environment::get_os_version(int32_t& major, int32_t& minor, int32_t& build, int32_t& revision) {
  #if defined(__APPLE__)
  std::vector<std::string> numbers = unix::strings::split(create_process("sw_vers -productVersion"), {'.', '\n'});
  #else
  std::vector<std::string> numbers = unix::strings::split(create_process("uname -r"), {'.', '-', '\n'});
  #endif
  if (numbers.size() < 1 || !unix::strings::try_parse(numbers[0], major)) major = 0;
  if (numbers.size() < 2 || !unix::strings::try_parse(numbers[1], minor)) minor = 0;
  if (numbers.size() < 3 || !unix::strings::try_parse(numbers[2], build)) build = 0;
  if (numbers.size() < 4 || !unix::strings::try_parse(numbers[3], revision)) revision = 0;
}

std::string environment::get_service_pack() {
  return "";
}

uint32_t environment::get_processor_count() {
  return std::thread::hardware_concurrency();
}

size_t environment::get_system_page_size() {
  return sysconf(_SC_PAGESIZE);
}

uint32_t environment::get_tick_count() {
  #if defined (__APPLE__)
  // https://stackoverflow.com/questions/3269321/osx-programmatically-get-uptime
  struct timeval boottime {};
  struct timeval nowtime {};
  auto len = sizeof(boottime);
  int32_t mib[2] = {CTL_KERN, KERN_BOOTTIME};
  sysctl(mib, 2, &boottime, &len, nullptr, 0);
  gettimeofday(&nowtime, nullptr);
  return static_cast<uint32_t>((nowtime.tv_sec - boottime.tv_sec) * 1000) + static_cast<uint32_t>((nowtime.tv_usec - boottime.tv_usec) / 1000);
  #else
  // https://stackoverflow.com/questions/1540627/what-api-do-i-call-to-get-the-system-uptime
  struct sysinfo info {};
  sysinfo(&info);
  return info.uptime * 1000;
  #endif
}

std::string environment::get_user_domain_name() {
  return unix::strings::trim_end(create_process("uname -n"), {'\n'});
}

std::string environment::get_user_name() {
  auto user_name = getenv("USER");
  return user_name ? user_name : "";
}

bool environment::is_processor_arm() {
  return  unix::strings::contains(create_process("uname -m"), "arm");
}

bool environment::is_os_64_bit() {
  return  unix::strings::contains(create_process("uname -m"), "64");
}

std::string environment::new_line() {
  return "\n";
}

void environment::set_environment_variable(const std::string& name, const std::string& value) {
  setenv(name.c_str(), value.c_str(), 1);
}

void environment::unset_environment_variable(const std::string& name) {
  unsetenv(name.c_str());
}
