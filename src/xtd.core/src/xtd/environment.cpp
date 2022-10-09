#include "../../include/xtd/as.h"
#include "../../include/xtd/environment.h"
#include "../../include/xtd/argument_exception.h"
#include "../../include/xtd/convert_string.h"
#include "../../include/xtd/io/directory.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/environment.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <vector>

// Workaround : Add "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Apple/usr/bin" to PATH if needed on macOS when debugging on Xcode...
struct __update__macos_path__ {
  __update__macos_path__() {
    if (!xtd::environment::os_version().is_macos_platform()) return;
    /// @todo fix PATH with foreach...
    //for (auto path : {"/usr/local/bin", "/usr/bin", "/bin", "/usr/sbin", "/sbin", "/Library/Apple/usr/bin"})
    //  if (!xtd::environment::get_environment_variable("PATH"), path).contains() xtd::environment::set_environment_variable("PATH", path+xtd::environment::get_environment_variable("PATH"));
    xtd::environment::set_environment_variable("PATH", "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Apple/usr/bin" + xtd::environment::get_environment_variable("PATH"));
  }
} __updmacpath__;

using namespace std;
using namespace xtd;
using namespace xtd::io;

namespace {
  int exit_code = 0;
}

ustring environment::current_directory() {
  return io::directory::get_current_directory();
}

void environment::current_directory(const ustring& directory_name) {
  io::directory::set_current_directory(directory_name);
}

int environment::exit_code() {
  return ::exit_code;
}

void environment::exit_code(int value) {
  ::exit_code = value;
}

bool environment::has_shutdown_started() {
  return native::environment::has_shutdown_started();
}

xtd::collections::specialized::string_vector environment::get_command_line_args() {
  auto args = native::environment::get_command_line_args();
  return {args.begin(), args.end()};
}

ustring environment::get_environment_variable(const ustring& variable, environment_variable_target target) {
  if (target == environment_variable_target::process)
    return native::environment::get_environment_variable(variable);
  if (target == environment_variable_target::user)
    return ""; //return microsoft::win32::registry::get_value("HKEY_CURRENT_USER\\Environment", variable, "").to_string();
  if (target == environment_variable_target::machine)
    return ""; // return microsoft::win32::registry::get_value("HKEY_LOCAL_MACHINE\\System\\CurrentControlSet\\Control\\Session Manager\\Environment", variable, "").to_string();
  throw xtd::argument_exception("Invalid environment variable target value"_t, current_stack_frame_);
}

map<string, string>& environment::get_environment_variables(environment_variable_target target) {
  if (target == environment_variable_target::process) return native::environment::get_environment_variables(ENVIRONMENT_VARIABLE_TARGET_PROCESS);
  if (target == environment_variable_target::user) return native::environment::get_environment_variables(ENVIRONMENT_VARIABLE_TARGET_USER);
  if (target == environment_variable_target::machine) return native::environment::get_environment_variables(ENVIRONMENT_VARIABLE_TARGET_MACHINE);
  throw argument_exception("Invalid environment variable target value"_t);
}

ustring environment::get_folder_path(environment::special_folder folder, environment::special_folder_option option) {
  ustring path = native::environment::get_know_folder_path(static_cast<int>(folder));
  
  if (option == environment::special_folder_option::none)
    return !xtd::io::directory::exists(path) ? "" :  path;
    
  if (!xtd::io::directory::exists(path))
    xtd::io::directory::create_directory(path);
    
  return path;
}

ustring environment::machine_name() {
  return native::environment::get_machine_name();
}

ustring environment::new_line() {
  return native::environment::new_line();
}

xtd::operating_system environment::os_version() {
  static xtd::operating_system os(xtd::platform_id::unknown, xtd::version());
  if (os.platform() == xtd::platform_id::unknown) {
    int major, minor, build, revision;
    native::environment::get_os_version(major, minor, build, revision);
    xtd::version version;
    version = xtd::version(major, minor, build, revision);
    os = operating_system(static_cast<platform_id>(native::environment::get_os_platform_id()), version, native::environment::get_service_pack(), native::environment::get_desktop_environment(), native::environment::get_desktop_theme(), native::environment::is_os_64_bit());
  }
  return os;
}

xtd::processor environment::processor_information() {
  static xtd::processor proc(xtd::architecture_id::unknown, false, 1);
  if (proc.architecture() == xtd::architecture_id::unknown)
    proc = xtd::processor(native::environment::is_processor_arm() ? architecture_id::arm : architecture_id::x86, native::environment::is_os_64_bit(), native::environment::get_processor_count());
  return proc;
}

void environment::set_environment_variable(const ustring& variable, const ustring& value, environment_variable_target target) {
  if (ustring::is_empty(variable)) throw xtd::argument_exception("Environment variable name is empty"_t, current_stack_frame_);
  
  if (target == environment_variable_target::process) {
    if (ustring::is_empty(value)) {
      get_environment_variables().erase(variable);
      native::environment::unset_environment_variable(variable);
    } else {
      get_environment_variables()[variable] = value;
      native::environment::set_environment_variable(variable, value);
    }
  } else if (target == environment_variable_target::user || target == environment_variable_target::machine) {
    //microsoft::win32::registry_key key = target == environment_variable_target::user ? microsoft::win32::registry::current_user().create_sub_key("Environment") : microsoft::win32::registry::local_machine().create_sub_key("System").create_sub_key("CurrentControlSet").create_sub_key("Control").create_sub_key("Session Manager").create_sub_key("Environment");
    //if (value.is_empty())
    //  key.delete_value(variable);
    //else
    //  key.set_value(variable, value);
  } else
    throw xtd::argument_exception("Invalid environment variable target value"_t, current_stack_frame_);
}

size_t environment::system_page_size() {
  return native::environment::get_system_page_size();
}

std::chrono::milliseconds environment::tick_count() {
  return std::chrono::milliseconds(native::environment::get_tick_count());
}

bool environment::user_administrator() {
  return native::environment::get_user_administrator();
}

ustring environment::user_domain_name() {
  return native::environment::get_user_domain_name();
}

bool environment::user_interactive() {
  return true;
}

ustring environment::user_name() {
  return native::environment::get_user_name();
}

int64_t environment::working_set() {
  return native::environment::working_set();
}
