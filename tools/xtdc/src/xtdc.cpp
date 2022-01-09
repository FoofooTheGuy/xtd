#include "project_management.h"

#include <xtd/xtd.core>
#include <xtd/system_report.h>
#include <chrono>
#include <ctype.h>
#include <filesystem>
#include <iostream>

#if !defined(WIN32)
#include <unistd.h>
#endif

using namespace std;
using namespace xtd;

namespace xtdc_command {
  class xtdc final static_ {
  public:
    static int main(const vector<ustring>& args) {
      if (args.size() == 0) {
        cout << ustring::join("\n", get_help()) << endl;
        return -1;
      }
      
      auto show_help = false;
      auto show_info = false;
      auto show_version = false;
      string invalid_option;
      vector<ustring> command_args;
      if (process_xtdc_arguments(args, show_help, show_info, show_version, command_args, invalid_option) == false) {
        if (!invalid_option.empty())
          cout << ustring::format("Unknown option: {0}", invalid_option) << endl;
        else
          cout << "Invalid parameters" << endl;
        cout << ustring::join("\n", get_help()) << endl;
        return -1;
      }
      
      return run_commands(show_help, show_info, show_version, invalid_option, command_args);
    }
    
  private:
    #if defined(__XTD_RESOURCES_PATH__)
    static string get_base_path() noexcept {return __XTD_RESOURCES_PATH__;}
    #else
    static string get_base_path() noexcept {return "";}
    #endif
    
    static vector<ustring> get_help() noexcept {
      return {
        "",
        "Usage: xtdc [<options> | command [<command-argument>] [<command-options>]]",
        "",
        "options:",
        "  -i, --info       Display information.",
        "  -v, --version    Display version in use.",
        "  -h, --help       Display help.",
        
        "",
        "command:",
        "  new              Initializes project.",
        "  add              Adds new project to project.",
        "  update           Regenerates a project.",
        "  run              Compiles and immediately executes a project.",
        "  build            Builds a project.",
        "  install          Install a project.",
        "  clean            Clean build output(s).",
        "  open             Open a project in default ide.",
        "  targets          List project targets.",
        "  test             Runs unit tests using the test runner specified in the project.",
        "  uninstall        Uninstall a project.",
        "  documentation    Open xtd documentation.",
        "  examples         Open xtd examples.",
        "  guide            Open xtd reference guide.",
        "  web              Open Gammasoft website.",
        "  help             Show help.",
        "",
        "Run 'xtdc command --help' for more information on a command.",
        "",
      };
    }
    
    static vector<ustring> get_add_help() noexcept {
      return {
        "Add new project to project.",
        "Usage: add [options]",
      };
    }
    
    static vector<ustring> get_build_help() noexcept {
      return {
        "Builds a project.",
        "Usage: build [path] [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -d, --debug         build debug config.",
        "  -r, --release       build release config.",
        "  -t, --target        build a specified target project.",
        "",
        "path:",
        "  Project path location. If no path is specified, the current path is used.",
        "",
        "",
        "Exemples:",
        "    xtdc build",
        "    xtdc build -p my_apps",
        "    xtdc build -p my_apps -t my_app1",
        "    xtdc build --help"
      };
    }
    
    static vector<ustring> get_clean_help() noexcept {
      return {
        "Clean build output(s).",
        "Usage: clean [path] [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -d, --debug         clean debug config.",
        "  -r, --release       clean release config.",
        "",
        "path:",
        "  Project path location. If no path is specified, the current path is used.",
        "",
        "",
        "Exemples:",
        "    xtdc clean",
        "    xtdc clean -p my_app",
        "    xtdc clean --help",
      };
    }
    
    static vector<ustring> get_install_help() noexcept {
      return {
        "Install a project.",
        "Usage: install [path] [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -d, --debug         install debug config.",
        "  -r, --release       install release config.",
        "",
        "path:",
        "  Project path location. If no path is specified, the current path is used.",
        "",
        "",
        "Exemples:",
        "    xtdc install",
        "    xtdc install -p my_app",
        "    xtdc install --help",
      };
    }
    
    static vector<ustring> get_open_help() noexcept {
      return {
        "Open a project in default ide.",
        "Usage: open [path] [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -d, --debug         open debug config.",
        "  -r, --release       open release config.",
        "",
        "path:",
        "  Project path location. If no path is specified, the current path is used.",
        "",
        "",
        "Exemples:",
        "    xtdc open",
        "    xtdc open -p my_app",
        "    xtdc open --help",
      };
    }
    
    static vector<ustring> get_new_help() noexcept {
      return {
        "Initialize project.",
        "Usage: new [template-short-name] [path] [<options>]",
        "",
        "template-short-name:",
        "  A template short name of the following table. If no short name specified, gui is used.",
        "  Templates               Short Name     SDK/Language                      ",
        "  -------------------------------------------------------------------------",
        "  GUI Application         gui            [xtd], cocoa, fltk, gtk+2, gtk+3, ",
        "                                         gtkmm, wxwidgets, qt5, win32,     ",
        "                                         winforms, wpf                     ",
        "  Console Application     console        [xtd], c++, c, c#, objective-c    ",
        "  Shared library          sharedlib      [xtd], c++, c, c#, objective-c    ",
        "  Static library          staticlib      [xtd], c++, c, c#, objective-c    ",
        "  Unit Test Project       test           [xtd], gtest, catch2              ",
        "  Solution File           sln            [xtd]                             ",
        "",
        "path:",
        "  Location to place the generated output. If no path is specified, the current path is used.",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -n, --name          The name for the project. If no name is specified, the name of the specified path or of the current directory is used.",
        "  --type              Filters templates based on available types. Predefined values are \"project\", \"item\" or \"other\".",
        "  -s , --sdk          Filters templates based on SDK/language and specifies the SDK/language of the template to create.",
        "  --force             Forces content to be generated even if it would change existing files.",
        "",
        "",
        "Exemples:",
        "    xtdc new console",
        "    xtdc new gui -p my_app",
        "    xtdc new --help",
      };
    }
    
    static vector<ustring> get_update_help() noexcept {
      return {
        "Regenrates a project.",
        "Usage: update [path] [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -t, --target        update a specified target project.",
        "",
        "path:",
        "  Project path location. If no path is specified, the current path is used.",
        "",
        "",
        "Exemples:",
        "    xtdc update",
        "    xtdc update -p my_apps",
        "    xtdc update -p my_apps -t my_app1",
        "    xtdc update --help",
      };
    }
    
    static vector<ustring> get_run_help() noexcept {
      return {
        "Compiles and immediately executes a project.",
        "Usage: run [path] [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -d, --debug         run debug config.",
        "  -r, --release       run release config.",
        "  -t, --target        run a specified target project.",
        "",
        "path:",
        "  Project path location. If no path is specified, the current path is used.",
        "",
        "",
        "Exemples:",
        "    xtdc run",
        "    xtdc run -p my_apps",
        "    xtdc run -p my_apps -t my_app1",
        "    xtdc run --help",
      };
    }
    
    static vector<ustring> get_targets_help() noexcept {
      return {
        "List project targets.",
        "Usage: targets [path] [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "",
        "path:",
        "  Project path location. If no path is specified, the current path is used.",
        "",
        "",
        "Exemples:",
        "    xtdc list",
        "    xtdc list -p my_app",
        "    xtdc list --help",
      };
    }
    
    static vector<ustring> get_test_help() noexcept {
      return {
        "Runs unit tests using the test runner specified in the project.",
        "Usage: test [path] [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -d, --debug         test debug config.",
        "  -r, --release       test release config.",
        "",
        "path:",
        "  Project path location. If no path is specified, the current path is used.",
        "",
        "",
        "Exemples:",
        "    xtdc test",
        "    xtdc test -p my_app",
        "    xtdc test --help",
      };
    }
    
    static vector<ustring> get_uninstall_help() noexcept {
      return {
        "Uninstall a project.",
        "Usage: uninstall [path] [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -d, --debug         uninstall debug config.",
        "  -r, --release       uninstall release config.",
        "",
        "path:",
        "  Project path location. If no path is specified, the current path is used.",
        "",
        "",
        "Exemples:",
        "    xtdc uninstall",
        "    xtdc uninstall -p my_app",
        "    xtdc uninstall --help",
      };
    }
    
    static vector<ustring> get_info() noexcept {
      return {
        "",
        get_xtd_version(),
        //"",
        "Operating System:",
        ustring::format("  Name: {}", system_report::operating_system().name()),
        ustring::format("  Version: {}", system_report::operating_system().version()),
        ustring::format("  Service pack: {}", system_report::operating_system().service_pack()),
        ustring::format("  Desktop environment: {}", system_report::operating_system().desktop_environment()),
        ustring::format("  64 bit: {}", system_report::operating_system().is_64_bit()),
        "",
        "Compiler:",
        ustring::format("  Name: {}", system_report::compiler().name()),
        ustring::format("  Version: {}", system_report::compiler().version()),
        ustring::format("  Mode: {}", system_report::compiler().is_build_type_debug() ? "Debug" : "Release"),
        ustring::format("  64 bit: {}", system_report::compiler().is_64_bit()),
        "",
        "Language:",
        ustring::format("  Name: {}", system_report::language().name()),
        ustring::format("  Version: {}", system_report::language().version()),
        ustring::format("  Experimental: {}", system_report::language().is_experimental_language()),
        ustring::format("  Supported: {}", system_report::language().is_supported()),
        "",
      };
    }
    
    static string get_xtd_version() noexcept {
      ustring result = ustring::format("xtd Framework:{}", environment::new_line());
      for (auto library : system_report::xtd_libraries()) {
        result += ustring::format("  {}", library.name(), environment::new_line());
        result += ustring::format("    Version: {}{}", library.version(), environment::new_line());
        result += ustring::format("    include path: {}{}", library.include_path(), environment::new_line());
        result += ustring::format("    library path: {}{}", library.library_path(), environment::new_line());
        result += ustring::format("    resources path: {}{}", library.resources_path(), environment::new_line());
      }
      return std::move(result);
    }
    
    static string get_version() noexcept {
      return ustring::format("xtdc version {}, (c) {:L} by Gammasoft", get_version_number(), xtd::date_time::now());
    }
    
    static string get_version_number() noexcept {
      return environment::version().to_string();
    }
    
    static bool is_ansi_supported() noexcept {
      #if defined(WIN32)
      return true;
      #else
      static string terminal = getenv("TERM") == nullptr ? "" : getenv("TERM");
      return isatty(fileno(stdout)) && (terminal == "xterm" || terminal == "xterm-color" || terminal == "xterm-256color" || terminal == "screen" || terminal == "screen-256color" || terminal == "linux" || terminal == "cygwin");
      #endif
    }
    
    static int add(const vector<ustring>& args) {
      auto show_help = false;
      string invalid_option;
      string type;
      string sdk;
      string name;
      string path;
      if (!process_add_arguments(args, show_help, type, name, path, sdk, invalid_option)) {
        if (!invalid_option.empty())
          cout << ustring::format("Unknown option: {0}", invalid_option) << endl;
        else
          cout << "Invalid parameters" << endl;
        cout << ustring::join("\n", get_add_help()) << endl;
        return -1;
      }
      if (type.empty()) type = "gui";
      if (sdk.empty()) sdk = "xtd";
      if (name.empty()) name = filesystem::path(path).stem().string();
      if (path.empty()) path = environment::current_directory();
      
      if (show_help)
        cout << ustring::join("\n", get_add_help()) << endl;
      else {
        xtdc_command::project_type project_type = map<string, xtdc_command::project_type> {{"sln", project_type::blank_solution}, {"gui", project_type::gui}, {"console", project_type::console}, {"sharedlib", project_type::shared_library}, {"staticlib", project_type::static_library}, {"test", project_type::unit_test_application}} [type];
        xtdc_command::project_sdk project_sdk = map<string, xtdc_command::project_sdk> {{"none", xtdc_command::project_sdk::none}, {"catch2", xtdc_command::project_sdk::catch2}, {"cocoa", xtdc_command::project_sdk::cocoa}, {"fltk", xtdc_command::project_sdk::fltk}, {"gtest", xtdc_command::project_sdk::gtest}, {"gtk+2", xtdc_command::project_sdk::gtk2}, {"gtk+3", xtdc_command::project_sdk::gtk3}, {"gtkmm", xtdc_command::project_sdk::gtkmm}, {"qt5", xtdc_command::project_sdk::qt5}, {"win32", xtdc_command::project_sdk::win32}, {"winforms", xtdc_command::project_sdk::winforms}, {"wpf", xtdc_command::project_sdk::wpf}, {"wxwidgets", xtdc_command::project_sdk::wxwidgets}, {"xtd", xtdc_command::project_sdk::xtd}} [sdk];
        xtdc_command::project_language project_language = map<string, xtdc_command::project_language> {{"cocoa", xtdc_command::project_language::objectivec}, {"fltk", xtdc_command::project_language::cpp}, {"gtk+2", xtdc_command::project_language::cpp}, {"gtk+3", xtdc_command::project_language::cpp}, {"gtkmm", xtdc_command::project_language::cpp}, {"qt5", xtdc_command::project_language::cpp}, {"win32", xtdc_command::project_language::cpp}, {"winforms", xtdc_command::project_language::csharp}, {"wpf", xtdc_command::project_language::csharp}, {"wxwidgets", xtdc_command::project_language::cpp}, {"xtd", xtdc_command::project_language::cpp}, {"c++", xtdc_command::project_language::cpp}, {"cpp", xtdc_command::project_language::cpp}, {"c", xtdc_command::project_language::c}, {"c#", xtdc_command::project_language::csharp}, {"csharp", xtdc_command::project_language::csharp}, {"objective-c", xtdc_command::project_language::objectivec}, {"objectivec", xtdc_command::project_language::objectivec}} [sdk];
        cout << project_management(filesystem::absolute(filesystem::path(path))).add(name, project_type, project_sdk, project_language) << endl;
      }
      return 0;
    }
    
    static int build(const vector<ustring>& args) {
      bool show_help = false;
      string invalid_option;
      bool clean_first = false;
      bool release = false;
      string target;
      string path;
      if (!process_build_arguments(args, show_help, clean_first, release, target, path, invalid_option)) {
        if (!invalid_option.empty())
          cout << ustring::format("Unknown option: {0}", invalid_option) << endl;
        else
          cout << "Invalid parameters" << endl;
        cout << ustring::join("\n", get_build_help()) << endl;
        return -1;
      }
      if (show_help)
        cout << ustring::join("\n", get_build_help()) << endl;
      else {
        if (path.empty()) path = environment::current_directory();
        cout << project_management(filesystem::absolute(filesystem::path(path))).build(target, clean_first, release) << endl;
      }
      return 0;
    }
    
    static int clean(const vector<ustring>& args) {
      bool show_help = false;
      string invalid_option;
      bool release = false;
      string path;
      if (!process_clean_arguments(args, show_help, release, path, invalid_option)) {
        if (!invalid_option.empty())
          cout << ustring::format("Unknown option: {0}", invalid_option) << endl;
        else
          cout << "Invalid parameters" << endl;
        cout << ustring::join("\n", get_clean_help()) << endl;
        return -1;
      }
      if (show_help)
        cout << ustring::join("\n", get_clean_help()) << endl;
      else {
        if (path.empty()) path = environment::current_directory();
        cout << project_management(filesystem::absolute(filesystem::path(path))).clean(release) << endl;
      }
      return 0;
    }
    
    static int help(const vector<ustring>& args) {
      cout << ustring::join("\n", get_help()) << endl;
      return 0;
    }
    
    static int install(const vector<ustring>& args) {
      bool show_help = false;
      string invalid_option;
      bool release = false;
      string path;
      if (!process_install_arguments(args, show_help, release, path, invalid_option)) {
        if (!invalid_option.empty())
          cout << ustring::format("Unknown option: {0}", invalid_option) << endl;
        else
          cout << "Invalid parameters" << endl;
        cout << ustring::join("\n", get_install_help()) << endl;
        return -1;
      }
      if (show_help)
        cout << ustring::join("\n", get_install_help()) << endl;
      else {
        if (path.empty()) path = environment::current_directory();
        cout << project_management(filesystem::absolute(filesystem::path(path))).install(release) << endl;
      }
      return 0;
    }
    
    static int new_project(const vector<ustring>& args) {
      auto show_help = false;
      string invalid_option;
      string type;
      string sdk;
      string name;
      string path;
      if (!process_new_arguments(args, show_help, type, name, path, sdk, invalid_option)) {
        if (!invalid_option.empty())
          cout << ustring::format("Unknown option: {0}", invalid_option) << endl;
        else
          cout << "Invalid parameters" << endl;
        cout << ustring::join("\n", get_new_help()) << endl;
        return -1;
      }
      if (type.empty()) type = "gui";
      if (sdk.empty()) sdk = "xtd";
      if (name.empty()) name = filesystem::path(path).stem().string();
      if (path.empty()) path = environment::current_directory();
      
      if (show_help)
        cout << ustring::join("\n", get_new_help()) << endl;
      else {
        if (name.empty()) {
          cout << "The name is empty." << endl;
          return -1;
        }
        if (std::find_if(name.begin(), name.end(), [](auto c) {return !(isalnum(c) || c == '_');}) != name.end()) {
          cout << "The name : \"" << name << "\" contains invalid charaters." << endl;
          return -1;
        }
        if (name.size() > 128) {
          cout << "The size of the name is invalid, the size must be less than or equal to 128." << endl;
          return -1;
        }
        
        xtdc_command::project_type project_type = map<string, xtdc_command::project_type> {{"sln", project_type::blank_solution}, {"gui", project_type::gui}, {"console", project_type::console}, {"sharedlib", project_type::shared_library}, {"staticlib", project_type::static_library}, {"test", project_type::unit_test_application}} [type];
        xtdc_command::project_sdk project_sdk = map<string, xtdc_command::project_sdk> {{"none", xtdc_command::project_sdk::none}, {"catch2", xtdc_command::project_sdk::catch2}, {"cocoa", xtdc_command::project_sdk::cocoa}, {"fltk", xtdc_command::project_sdk::fltk}, {"gtest", xtdc_command::project_sdk::gtest}, {"gtk+2", xtdc_command::project_sdk::gtk2}, {"gtk+3", xtdc_command::project_sdk::gtk3}, {"gtkmm", xtdc_command::project_sdk::gtkmm}, {"qt5", xtdc_command::project_sdk::qt5}, {"win32", xtdc_command::project_sdk::win32}, {"winforms", xtdc_command::project_sdk::winforms}, {"wpf", xtdc_command::project_sdk::wpf}, {"wxwidgets", xtdc_command::project_sdk::wxwidgets}, {"xtd", xtdc_command::project_sdk::xtd}} [sdk];
        xtdc_command::project_language project_language = map<string, xtdc_command::project_language> {{"cocoa", xtdc_command::project_language::objectivec}, {"fltk", xtdc_command::project_language::cpp}, {"gtk+2", xtdc_command::project_language::cpp}, {"gtk+3", xtdc_command::project_language::cpp}, {"gtkmm", xtdc_command::project_language::cpp}, {"qt5", xtdc_command::project_language::cpp}, {"win32", xtdc_command::project_language::cpp}, {"winforms", xtdc_command::project_language::csharp}, {"wpf", xtdc_command::project_language::csharp}, {"wxwidgets", xtdc_command::project_language::cpp}, {"xtd", xtdc_command::project_language::cpp}, {"c++", xtdc_command::project_language::cpp}, {"cpp", xtdc_command::project_language::cpp}, {"c", xtdc_command::project_language::c}, {"c#", xtdc_command::project_language::csharp}, {"csharp", xtdc_command::project_language::csharp}, {"objective-c", xtdc_command::project_language::objectivec}, {"objectivec", xtdc_command::project_language::objectivec}} [sdk];
        cout << project_management(filesystem::absolute(filesystem::path(path))).create(name, project_type, project_sdk, project_language) << endl;
      }
      return 0;
    }
    
    static int open(const vector<ustring>& args) {
      bool show_help = false;
      string invalid_option;
      bool release = false;
      string path;
      if (!process_open_arguments(args, show_help, release, path, invalid_option)) {
        if (!invalid_option.empty())
          cout << ustring::format("Unknown option: {0}", invalid_option) << endl;
        else
          cout << "Invalid parameters" << endl;
        cout << ustring::join("\n", get_open_help()) << endl;
        return -1;
      }
      if (show_help)
        cout << ustring::join("\n", get_open_help()) << endl;
      else {
        if (path.empty()) path = environment::current_directory();
        cout << project_management(filesystem::absolute(filesystem::path(path))).open(release) << endl;
      }
      return 0;
    }
    
    static int update(const vector<ustring>& args) {
      bool show_help = false;
      string invalid_option;
      string target;
      string path;
      if (!process_update_arguments(args, show_help, target, path, invalid_option)) {
        if (!invalid_option.empty())
          cout << ustring::format("Unknown option: {0}", invalid_option) << endl;
        else
          cout << "Invalid parameters" << endl;
        cout << ustring::join("\n", get_update_help()) << endl;
        return -1;
      }
      if (show_help)
        cout << ustring::join("\n", get_update_help()) << endl;
      else {
        if (path.empty()) path = environment::current_directory();
        cout << project_management(filesystem::absolute(filesystem::path(path))).update(target) << endl;
      }
      return 0;
    }
    
    static int run(const vector<ustring>& args) {
      bool show_help = false;
      string invalid_option;
      bool release = false;
      string target;
      string path;
      if (!process_run_arguments(args, show_help, release, target, path, invalid_option)) {
        if (!invalid_option.empty())
          cout << ustring::format("Unknown option: {0}", invalid_option) << endl;
        else
          cout << "Invalid parameters" << endl;
        cout << ustring::join("\n", get_run_help()) << endl;
        return -1;
      }
      if (show_help)
        cout << ustring::join("\n", get_run_help()) << endl;
      else {
        if (path.empty()) path = environment::current_directory();
        cout << project_management(filesystem::absolute(filesystem::path(path))).run(target, release) << endl;
      }
      return 0;
    }
    
    static int targets(const vector<ustring>& args) {
      bool show_help = false;
      string invalid_option;
      string path;
      if (!process_targets_arguments(args, show_help, path, invalid_option)) {
        if (!invalid_option.empty())
          cout << ustring::format("Unknown option: {0}", invalid_option) << endl;
        else
          cout << "Invalid parameters" << endl;
        cout << ustring::join("\n", get_targets_help()) << endl;
        return -1;
      }
      if (show_help)
        cout << ustring::join("\n", get_targets_help()) << endl;
      else {
        if (path.empty()) path = environment::current_directory();
        cout << xtd::ustring::join(", ", project_management(filesystem::absolute(filesystem::path(path))).targets()) << endl;
      }
      return 0;
    }
    
    static int test(const vector<ustring>& args) {
      bool show_help = false;
      string invalid_option;
      bool release = false;
      string path;
      if (!process_test_arguments(args, show_help, release, path, invalid_option)) {
        if (!invalid_option.empty())
          cout << ustring::format("Unknown option: {0}", invalid_option) << endl;
        else
          cout << "Invalid parameters" << endl;
        cout << ustring::join("\n", get_test_help()) << endl;
        return -1;
      }
      if (show_help)
        cout << ustring::join("\n", get_test_help()) << endl;
      else {
        if (path.empty()) path = environment::current_directory();
        cout << project_management(filesystem::absolute(filesystem::path(path))).test(release) << endl;
      }
      return 0;
    }
    
    static int uninstall(const vector<ustring>& args) {
      bool show_help = false;
      string invalid_option;
      bool release = false;
      string path;
      if (!process_uninstall_arguments(args, show_help, release, path, invalid_option)) {
        if (!invalid_option.empty())
          cout << ustring::format("Unknown option: {0}", invalid_option) << endl;
        else
          cout << "Invalid parameters" << endl;
        cout << ustring::join("\n", get_uninstall_help()) << endl;
        return -1;
      }
      if (show_help)
        cout << ustring::join("\n", get_uninstall_help()) << endl;
      else {
        if (path.empty()) path = environment::current_directory();
        cout << project_management(filesystem::absolute(filesystem::path(path))).uninstall(release) << endl;
      }
      return 0;
    }
    
    static int documentation(const vector<ustring>& args) {
      xtd::diagnostics::process::start("https://github.com/gammasoft71/xtd/blob/master/docs/home.md").wait_for_exit();
      return 0;
    }
    
    static int examples(const vector<ustring>& args) {
      xtd::diagnostics::process::start("https://github.com/gammasoft71/xtd/blob/master/examples/README.md").wait_for_exit();
      return 0;
    }
    
    static int guide(const vector<ustring>& args) {
      xtd::diagnostics::process::start("https://codedocs.xyz/gammasoft71/xtd/index.html").wait_for_exit();
      return 0;
    }
    
    static int web(const vector<ustring>& args) {
      xtd::diagnostics::process::start("https://gammasoft71.wixsite.com/gammasoft").wait_for_exit();
      return 0;
    }
    
    static bool process_xtdc_arguments(const vector<ustring>& args, bool& show_help, bool& show_info, bool& show_version, vector<ustring>& command_args, string& invalid_option) {
      for (size_t i = 0; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-i" || args[i] == "--info")
          show_info = true;
        else if (args[i] == "-v" || args[i] == "--version")
          show_version = true;
        else if (!args[i].starts_with('-')) {
          command_args = vector<ustring>(args.size() - i);
          command_args = {args.begin() + i, args.end()};
          i = args.size();
        } else if (args[i].starts_with('-')) {
          invalid_option = args[i];;
          return false;
        }
      }
      return true;
    }
    
    static bool process_add_arguments(const vector<ustring>& args, bool& show_help, string& type, string& name, string& path, string& sdk, string& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-n" || args[i] == "--name") {
          if (i + 1 >= args.size()) return false;
          name = args[++i];
        } else if (args[i] == "-s" || args[i] == "--sdk") {
          if (i + 1 >= args.size()) return false;
          sdk = args[++i];
        } else if (args[i].starts_with('-')) {
          invalid_option = args[i];;
          return false;
        } else if (type.empty())
          type = args[i];
        else if (name.empty())
          path = args[i];
        else
          return false;
      }
      return true;
    }
    
    static bool process_build_arguments(const vector<ustring>& args, bool& show_help, bool& clean_first, bool& release, string& target, string& path, string& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-c" || args[i] == "--clean-first")
          clean_first = true;
        else if (args[i] == "-d" || args[i] == "--debug")
          release = false;
        else if (args[i] == "-r" || args[i] == "--release")
          release = true;
        else if (args[i] == "-t" || args[i] == "--target")
          target = args[++i];
        else if (path.empty())
          path = args[i];
        else if (args[i].starts_with('-')) {
          invalid_option = args[i];;
          return false;
        }
      }
      return true;
    }
    
    static bool process_clean_arguments(const vector<ustring>& args, bool& show_help, bool& release, string& path, string& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-d" || args[i] == "--debug")
          release = false;
        else if (args[i] == "-r" || args[i] == "--release")
          release = true;
        else if (path.empty())
          path = args[i];
        else if (args[i].starts_with('-')) {
          invalid_option = args[i];;
          return false;
        }
      }
      return true;
    }
    
    static bool process_install_arguments(const vector<ustring>& args, bool& show_help, bool& release, string& path, string& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-d" || args[i] == "--debug")
          release = false;
        else if (args[i] == "-r" || args[i] == "--release")
          release = true;
        else if (path.empty())
          path = args[i];
        else if (args[i].starts_with('-')) {
          invalid_option = args[i];;
          return false;
        }
      }
      return true;
    }
    
    static bool process_open_arguments(const vector<ustring>& args, bool& show_help, bool& release, string& path, string& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-d" || args[i] == "--debug")
          release = false;
        else if (args[i] == "-r" || args[i] == "--release")
          release = true;
        else if (path.empty())
          path = args[i];
        else if (args[i].starts_with('-')) {
          invalid_option = args[i];;
          return false;
        }
      }
      return true;
    }
    
    static bool process_new_arguments(const vector<ustring>& args, bool& show_help, string& type, string& name, string& path, string& sdk, string& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-n" || args[i] == "--name") {
          if (i + 1 >= args.size()) return false;
          name = args[++i];
        } else if (args[i] == "-s" || args[i] == "--sdk") {
          if (i + 1 >= args.size()) return false;
          sdk = args[++i];
        } else if (args[i].starts_with('-')) {
          invalid_option = args[i];;
          return false;
        } else if (type.empty())
          type = args[i];
        else if (path.empty())
          path = args[i];
        else
          return false;
      }
      return true;
    }
    
    static bool process_update_arguments(const vector<ustring>& args, bool& show_help, string& target, string& path, string& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-t" || args[i] == "--target")
          target = args[++i];
        else if (path.empty())
          path = args[i];
        else if (args[i].starts_with('-')) {
          invalid_option = args[i];;
          return false;
        }
      }
      return true;
    }
    
    static bool process_run_arguments(const vector<ustring>& args, bool& show_help, bool& release, string& target, string& path, string& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-d" || args[i] == "--debug")
          release = false;
        else if (args[i] == "-r" || args[i] == "--release")
          release = true;
        else if (args[i] == "-t" || args[i] == "--target")
          target = args[++i];
        else if (path.empty())
          path = args[i];
        else if (args[i].starts_with('-')) {
          invalid_option = args[i];;
          return false;
        }
      }
      return true;
    }
    
    static bool process_targets_arguments(const vector<ustring>& args, bool& show_help, string& path, string& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (path.empty())
          path = args[i];
        else if (args[i].starts_with('-')) {
          invalid_option = args[i];;
          return false;
        }
      }
      return true;
    }
    
    static bool process_test_arguments(const vector<ustring>& args, bool& show_help, bool& release, string& path, string& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-d" || args[i] == "--debug")
          release = false;
        else if (args[i] == "-r" || args[i] == "--release")
          release = true;
        else if (path.empty())
          path = args[i];
        else if (args[i].starts_with('-')) {
          invalid_option = args[i];;
          return false;
        }
      }
      return true;
    }
    
    static bool process_uninstall_arguments(const vector<ustring>& args, bool& show_help, bool& release, string& path, string& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-d" || args[i] == "--debug")
          release = false;
        else if (args[i] == "-r" || args[i] == "--release")
          release = true;
        else if (path.empty())
          path = args[i];
        else if (args[i].starts_with('-')) {
          invalid_option = args[i];;
          return false;
        }
      }
      return true;
    }
    
    static int invalid_command(const vector<ustring>& command_args) {
      cout << "Invalid command" << endl;
      cout << ustring::join("\n", get_help()) << endl;
      return -1;
    }
    
    static int run_commands(bool show_help, bool show_info, bool show_version, string invalid_option, const vector<ustring>& command_args) {
      if (show_version || show_info || show_help) {
        cout << get_version() << endl;
        if (show_info) cout << ustring::join("\n", get_info()) << endl;
        if (show_help) cout << ustring::join("\n", get_help()) << endl;
        return 0;
      }
      static map<ustring, function<int(const vector<ustring>&)>> commands {{"add", add}, {"build", build}, {"clean", clean}, {"documentation", documentation}, {"examples", examples}, {"guide", guide}, {"help", help}, {"install", install}, {"new", new_project}, {"open", open}, {"update", update}, {"run", run}, {"targets", targets}, {"test", test}, {"uninstall", uninstall}, {"web", web}};
      auto it = commands.find(command_args[0]);
      if (it == commands.end()) return invalid_command(command_args);
      return it->second(command_args);
    }
  };
}

startup_(xtdc_command::xtdc);
