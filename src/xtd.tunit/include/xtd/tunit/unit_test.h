/// @file
/// @brief Contains xtd::tunit::unit_test class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once

#include "../tunit_export.h"
#include "event_listener.h"
#include "registered_test_class.h"
#include "settings.h"
#include <xtd/convert.h>
#include <xtd/date_time.h>
#include <xtd/random.h>
#include <xtd/system_exception.h>
#include <iomanip>
#include <fstream>
#include <memory>
#include <random>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @cond
    template <typename test_class_t>
    class test_class_attribute;
    /// @endcond
    
    /// @brief The template class.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit tunit
    class tunit_export_ unit_test {
    public:
      /// @brief Initializes a new instance of xtd::tunit::unit_test with specified xtd::tunit::event_listener.
      /// @param event_listener The event listener associate to the unit tests.
      /// @remarks The arguments of the unit test application are detected automatically.
      explicit unit_test(std::unique_ptr<xtd::tunit::event_listener> event_listener) noexcept;
      
      /// @brief Initializes a new instance of xtd::tunit::unit_test with specified xtd::tunit::event_listener, argument counts and arguments array.
      /// @param event_listener The event listener associate to the unit tests.
      /// @param argc Argument count from main method.
      /// @param argv Arguments array from main method.
      unit_test(std::unique_ptr<xtd::tunit::event_listener> event_listener, int argc, char* argv[]) noexcept;
      
      /// @cond
      virtual ~unit_test() {}
      /// @endcond
      
      /// @brief Runs all tests in this UnitTest object and prints the result.
      /// @return EXIT_SUCCESS (0) if succeed; otherwise return EXIT_FAILURE (1).
      int32 run() {
        if (parse_arguments(arguments))
          return xtd::tunit::settings::default_settings().exit_status();
          
        if (xtd::tunit::settings::default_settings().list_tests()) {
          std::vector<std::string> tests;
          for (auto test_class : test_classes())
            for (auto test : test_class.test()->tests())
              tests.push_back(test_class.test()->name() + '.' + test.name());

          if (xtd::tunit::settings::default_settings().output_json()) write_list_tests_json();
          if (xtd::tunit::settings::default_settings().output_xml()) write_list_tests_xml();

          return list_tests(tests);
        }
        
        xtd::system_exception::enable_stack_trace(settings::default_settings().enable_stack_trace());

        auto random = xtd::tunit::settings::default_settings().random_seed() ? xtd::random(xtd::tunit::settings::default_settings().random_seed()) : xtd::random();

        for (repeat_iteration_ = 1; repeat_iteration_ <= xtd::tunit::settings::default_settings().repeat_test() || xtd::tunit::settings::default_settings().repeat_test() < 0; ++repeat_iteration_) {
          if (xtd::tunit::settings::default_settings().shuffle_test())
            std::shuffle(test_classes().begin(), test_classes().end(), random.generator());

          try {
            event_listener_->on_unit_test_start(xtd::tunit::tunit_event_args(*this));
            
            event_listener_->on_unit_test_initialize_start(xtd::tunit::tunit_event_args(*this));
            unit_test_initialize();
            event_listener_->on_unit_test_initialize_end(xtd::tunit::tunit_event_args(*this));
            
            start_time_point_ = xtd::date_time::now();
            for (auto& test_class : test_classes())
              if (test_class.test()->test_count())
                test_class.test()->run(*this);
            end_time_point_ = xtd::date_time::now();
            
            event_listener_->on_unit_test_cleanup_start(xtd::tunit::tunit_event_args(*this));
            unit_test_cleanup();
            event_listener_->on_unit_test_cleanup_end(xtd::tunit::tunit_event_args(*this));
            
            event_listener_->on_unit_test_end(xtd::tunit::tunit_event_args(*this));
          } catch (const std::exception&) {
            xtd::tunit::settings::default_settings().exit_status(EXIT_FAILURE);
            // do error...
          } catch (...) {
            xtd::tunit::settings::default_settings().exit_status(EXIT_FAILURE);
            // do error...
          }
        }
        
        xtd::tunit::settings::default_settings().end_time(xtd::date_time::now());
        
        if (xtd::tunit::settings::default_settings().output_json()) write_tests_json();
        if (xtd::tunit::settings::default_settings().output_xml()) write_tests_xml();

        return xtd::tunit::settings::default_settings().exit_status();
      }
      
      int32 repeat_iteration() const noexcept {return repeat_iteration_;}
      
      int32 repeat_iteration_count() const noexcept {return xtd::tunit::settings::default_settings().repeat_test();}
      
      bool repeat_tests() const noexcept {return xtd::tunit::settings::default_settings().repeat_test() != 1;}
      
      size_t test_cases_count() const noexcept {
        size_t count = 0;
        for (auto test_class : test_classes())
          if (test_class.test()->test_count())
            count ++;
        return count;
      }
      
      size_t test_count() const noexcept {
        size_t count = 0;
        for (auto test_class : test_classes())
          count += test_class.test()->test_count();
        return count;
      }
      
      size_t aborted_test_count() const noexcept {
        size_t count = 0;
        for (auto& test_class : test_classes())
          for (auto& test : test_class.test()->tests())
            if (settings::default_settings().is_match_test_name(test_class.test()->name(), test.name()) && test.aborted()) count++;
        return count;
      }
      
      std::vector<std::string> aborted_test_names() const noexcept {
        std::vector<std::string> names;
        for (auto& test_class : test_classes())
          for (auto& test : test_class.test()->tests())
            if (settings::default_settings().is_match_test_name(test_class.test()->name(), test.name()) && test.aborted()) names.push_back(test_class.test()->name() + "." + test.name());
        return names;
      }
      
      std::chrono::milliseconds elapsed_time() const noexcept {
        using namespace std::chrono_literals;
        if (start_time_point_.ticks() == 0ms && end_time_point_.ticks() == 0ms) return 0ms;
        if (end_time_point_.ticks() == 0ms) return std::chrono::duration_cast<std::chrono::milliseconds>((xtd::date_time::now() - start_time_point_).ticks());
        return std::chrono::duration_cast<std::chrono::milliseconds>((end_time_point_ - start_time_point_).ticks());
      }
      
      size_t ignored_test_count() const noexcept {
        size_t count = 0;
        for (auto test_class : test_classes())
          count += test_class.test()->ignored_test_count();
        return count;
      }
      
      std::vector<std::string> ignored_test_names() const noexcept {
        std::vector<std::string> names;
        for (auto& test_class : test_classes())
          for (auto& test : test_class.test()->tests())
            if (settings::default_settings().is_match_test_name(test_class.test()->name(), test.name()) && test.ignored()) names.push_back(test_class.test()->name() + "." + test.name());
        return names;
      }
      
      size_t failed_test_count() const noexcept {
        size_t count = 0;
        for (auto& test_class : test_classes())
          for (auto& test : test_class.test()->tests())
            if (settings::default_settings().is_match_test_name(test_class.test()->name(), test.name()) && test.failed()) count++;
        return count;
      }
      
      std::vector<std::string> failed_test_names() const noexcept {
        std::vector<std::string> names;
        for (auto& test_class : test_classes())
          for (auto& test : test_class.test()->tests())
            if (settings::default_settings().is_match_test_name(test_class.test()->name(), test.name()) && test.failed()) names.push_back(test_class.test()->name() + "." + test.name());
        return names;
      }
      
      size_t succeed_test_count() const noexcept {
        size_t count = 0;
        for (auto& test_class : test_classes())
          for (auto& test : test_class.test()->tests())
            if (settings::default_settings().is_match_test_name(test_class.test()->name(), test.name()) && test.succeed()) count++;
        return count;
      }
      
      std::vector<std::string> succeed_test_names() const noexcept {
        std::vector<std::string> names;
        for (auto& test_class : test_classes())
          for (auto& test : test_class.test()->tests())
            if (settings::default_settings().is_match_test_name(test_class.test()->name(), test.name()) && test.succeed()) names.push_back(test_class.test()->name() + "." + test.name());
        return names;
      }
      
    protected:
      virtual int32 list_tests(const std::vector<std::string>& tests) {
        return xtd::tunit::settings::default_settings().exit_status();
      }
      
      virtual bool parse_arguments(const std::vector<std::string>& args) {
        bool gtest_compatibility = xtd::tunit::settings::default_settings().gtest_compatibility();
        for (auto arg : args) {
          if (arg == "--gtest_compatibility" || arg.find("--gtest") == 0) gtest_compatibility = true;
          // Test selection :
          if (arg == "--list_tests") xtd::tunit::settings::default_settings().list_tests(true);
          else if (arg == "--gtest_list_tests") xtd::tunit::settings::default_settings().list_tests(true);
          else if (arg.find("--filter_tests=") == 0) xtd::tunit::settings::default_settings().filter_tests(arg.substr(15));
          else if (arg.find("--gtest_filter=") == 0) xtd::tunit::settings::default_settings().filter_tests(arg.substr(15));
          else if (arg == "--also_run_ignored_tests") xtd::tunit::settings::default_settings().also_run_ignored_tests(true);
          else if (arg == "--gtest_also_run_disabled_tests") xtd::tunit::settings::default_settings().also_run_ignored_tests(true);
          // Test execution:
          else if (arg.find("--repeat_tests=") == 0) xtd::tunit::settings::default_settings().repeat_tests(convert::to_int32(arg.substr(15)));
          else if (arg.find("--gtest_repeat=") == 0) xtd::tunit::settings::default_settings().repeat_tests(convert::to_int32(arg.substr(15)));
          else if (arg == "--shuffle_tests") xtd::tunit::settings::default_settings().shuffle_test(true);
          else if (arg == "--gtest_shuffle") xtd::tunit::settings::default_settings().shuffle_test(true);
          else if (arg.find("--random_seed=") == 0) xtd::tunit::settings::default_settings().random_seed(convert::to_uint32(arg.substr(14)));
          else if (arg.find("--gtest_random_seed=") == 0) xtd::tunit::settings::default_settings().random_seed(convert::to_uint32(arg.substr(20)));
          else if (arg == "--enable_stack_trace=true") xtd::tunit::settings::default_settings().enable_stack_trace(true);
          else if (arg == "--enable_stack_trace=false") xtd::tunit::settings::default_settings().enable_stack_trace(false);
          // Test output
          else if (arg == "--output_color=true") xtd::tunit::settings::default_settings().output_color(true);
          else if (arg == "--gtest_color=auto" || arg == "--gtest_color=yes") xtd::tunit::settings::default_settings().output_color(true);
          else if (arg == "--output_color=false") xtd::tunit::settings::default_settings().output_color(false);
          else if (arg == "--gtest_color=no") xtd::tunit::settings::default_settings().output_color(false);
          else if (arg == "--show_duration=true") xtd::tunit::settings::default_settings().show_duration(true);
          else if (arg == "--show_duration=false") xtd::tunit::settings::default_settings().show_duration(false);
          else if (arg == "--gtest_print_time=0") xtd::tunit::settings::default_settings().show_duration(false);
          else if (arg.find("--output=json") == 0) {
            xtd::tunit::settings::default_settings().output_json(true);
            if (arg[13] == ':') xtd::tunit::settings::default_settings().output_json_path(arg.substr(14));
          } else if (arg.find("--gtest_output=json") == 0) {
            xtd::tunit::settings::default_settings().output_json(true);
            if (arg[19] == ':') xtd::tunit::settings::default_settings().output_json_path(arg.substr(20));
          } else if (arg.find("--output=xml") == 0) {
            xtd::tunit::settings::default_settings().output_xml(true);
            if (arg[12] == ':') xtd::tunit::settings::default_settings().output_xml_path(arg.substr(13));
          } else if (arg.find("--gtest_output=xml") == 0) {
            xtd::tunit::settings::default_settings().output_xml(true);
            if (arg[18] == ':') xtd::tunit::settings::default_settings().output_xml_path(arg.substr(19));
          }
        }
        xtd::tunit::settings::default_settings().gtest_compatibility(gtest_compatibility);
        return false;
      }
      
    private:
      template <typename test_class_t>
      friend class xtd::tunit::test_class_attribute;
      friend class xtd::tunit::test_class;
      friend class xtd::tunit::test;
      friend class xtd::tunit::base_assert;
      
      static void add(const xtd::tunit::registered_test_class& test_class) {test_classes().push_back(test_class);}
      
      static std::vector<xtd::tunit::registered_test_class>& test_classes() {
        static std::vector<xtd::tunit::registered_test_class> test_classes;
        return test_classes;
      }

      std::string get_filename(const std::string& path) {
        std::string filename = path;
        const size_t last_slash_idx = filename.find_last_of("\\/");
        if (std::string::npos != last_slash_idx)
          filename.erase(0, last_slash_idx + 1);
          
        const size_t period_idx = filename.rfind('.');
        if (std::string::npos != period_idx)
          filename.erase(period_idx);
        return filename;
      }
      
      std::string cdata_message_to_xml_string(const xtd::tunit::test& test) {
        std::stringstream ss;
        if (settings::default_settings().gtest_compatibility()) {
          if (test.stack_frame() != xtd::diagnostics::stack_frame::empty())
            ss << test.stack_frame().get_file_name() << ":" << test.stack_frame().get_file_line_number() << std::endl;
          ss << "Value of: " << test.actual() << std::endl;
          ss << "  Actual: " << test.actual() << std::endl;
          ss << "Expected: " << test.expect();
        } else {
          if (test.stack_frame() != xtd::diagnostics::stack_frame::empty())
            ss << test.stack_frame().get_file_name() << ":" << test.stack_frame().get_file_line_number() << std::endl;
          ss << "Expected: " << test.expect() << std::endl;
          ss << "But was : " << test.actual();
        }
        return ss.str();
      }
      
      std::string escape_path_to_json_string(const std::string& path) {
        return ustring::join(ustring::format("\\{}", io::path::directory_separator_char()), ustring(path).split({io::path::directory_separator_char()}));
      }

      std::string escape_to_json_string(const std::string& str) {
        return ustring(str).replace("\"", "\\\"");
      }
      
      std::string escape_to_xml_string(const std::string& str) {
        return ustring(str).replace("\"", "&quot;").replace("&", "&amp;").replace("'", "&apos;").replace("<", "&lt;").replace(">", "&gt;");
      }
      
      std::string message_to_json_string(const xtd::tunit::test& test) {
        std::stringstream ss;
        if (settings::default_settings().gtest_compatibility())
          ss << "Value of: " << escape_to_json_string(test.actual()) << "\\n" << "  Actual: " << escape_to_json_string(test.actual()) << "\\n" << "Expected: " << escape_to_json_string(test.expect());
        else
          ss <<  "Expected: " << escape_to_json_string(test.expect()) << "\\n" << "But was: " << escape_to_json_string(test.actual());
        return ss.str();
      }
      
      std::string message_to_xml_string(const xtd::tunit::test& test) {
        std::stringstream ss;
        if (settings::default_settings().gtest_compatibility()) {
          if (test.stack_frame() != xtd::diagnostics::stack_frame::empty())
            ss << test.stack_frame().get_file_name() << ":" << test.stack_frame().get_file_line_number() << "&#x0A;";
          ss << "Value of: " << escape_to_xml_string(test.actual()) << "&#x0A;";
          ss << "  Actual: " << escape_to_xml_string(test.actual()) << "&#x0A;";
          ss << "Expected: " <<  escape_to_xml_string(test.expect());
        } else {
          if (test.stack_frame() != xtd::diagnostics::stack_frame::empty())
            ss << test.stack_frame().get_file_name() << ":" << test.stack_frame().get_file_line_number() << "&#x0A;";
          ss << "Expected: " << escape_to_xml_string(test.expect()) << "&#x0A;";
          ss << "But was : " << escape_to_xml_string(test.actual());
        }
        return ss.str();
      }
      
      std::string name_to_string(const std::string& name) {
        return (settings::default_settings().gtest_compatibility() ? "AllTests" : name_);
      }
      
      std::string status_to_string(const xtd::tunit::test& test) {
        std::stringstream ss;
        if (test.not_started() || test.ignored()) ss << "notrun";
        else ss << "run";
        return ss.str();
      }

      std::string to_string(const std::chrono::milliseconds& ms) {
        std::stringstream ss;
        if (ms.count() == 0)
          ss << 0;
        else
          ss << ms.count() / 1000 << "." << std::setfill('0') << std::setw(3) << ms.count() % 1000;
        return ss.str();
      }
      
      std::string to_string(const std::chrono::time_point<std::chrono::system_clock>& time) {
        std::time_t time_t = std::chrono::system_clock::to_time_t(time);
        std::tm tm = *std::localtime(&time_t);
        std::stringstream ss;
        ss << tm.tm_year + 1900 << "-" << std::setfill('0') << std::setw(2) << tm.tm_mon << "-" << std::setfill('0') << std::setw(2) << tm.tm_mday;
        ss << "T" << std::setfill('0') << std::setw(2) << tm.tm_hour << ":" << std::setfill('0') << std::setw(2) << tm.tm_min << ":" << std::setfill('0') << std::setw(2) << tm.tm_sec;
        return ss.str();
      }
      
      void unit_test_cleanup() {
      }
      
      void unit_test_initialize() {
      }

      void write_list_tests_json() {
        std::fstream file(xtd::tunit::settings::default_settings().output_json_path(), std::ios::out | std::ios::trunc);
        file << "{" << std::endl;
        file << "  \"tests\": " << test_count() << "," << std::endl;
        file << "  \"name\": \"" << name_to_string(name_) << "\"," << std::endl;
        file << "  \"testsuites\": [" << std::endl;
        for (auto& test_class : test_classes()) {
          file << "    {" << std::endl;
          file << "      \"name\": \"" << escape_to_xml_string(test_class.test()->name()) << "\"," << std::endl;
          file << "      \"tests\": " << test_class.test()->test_count() << "," << std::endl;
          file << "      \"testsuite\": [" << std::endl;
          for (auto& test : test_class.test()->tests()) {
            file << "        {" << std::endl;
            file << "          \"name\": \"" << test.name() << "\"," << std::endl;
            file << "          \"file\": \"" << escape_path_to_json_string(test.stack_frame().get_file_name()) << "\"," << std::endl;
            file << "          \"line\": " << test.stack_frame().get_file_line_number() << "," << std::endl;
            file << "        }," << std::endl;
          }
          file << "      ]" << std::endl;
          file << "    }," << std::endl;
        }
        file << "  ]" << std::endl;
        file << "}" << std::endl;
        file.close();
      }
      
      void write_list_tests_xml() {
        std::fstream file(xtd::tunit::settings::default_settings().output_xml_path(), std::ios::out | std::ios::trunc);
        file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
        file << "<testsuites tests=\"" << test_count() << "\" name=\"" << name_to_string(name_) << "\">" << std::endl;
        for (auto& test_class : test_classes()) {
          file << "  <testsuite name=\"" << escape_to_xml_string(test_class.test()->name()) << "\" tests=\"" << test_class.test()->test_count() << "\">" << std::endl;
          for (auto& test : test_class.test()->tests()) {
            file << "    <testcase name=\"" << test.name() << "\" file=\"" << test.stack_frame().get_file_name() << "\" line=\"" << test.stack_frame().get_file_line_number() << "\" />" << std::endl;
          }
          file << "  </testsuite>" << std::endl;
        }
        file << "</testsuites>" << std::endl;
        file.close();
      }

      void write_tests_json() {
        std::fstream file(xtd::tunit::settings::default_settings().output_json_path(), std::ios::out | std::ios::trunc);
        file << "{" << std::endl;
        file << "  \"tests\": " << test_count() << "," << std::endl;
        file << "  \"failures\": " << failed_test_count() << "," << std::endl;
        file << "  \"disabled\": " << ignored_test_count() << "," << std::endl;
        file << "  \"errors\": " << 0  << ","<< std::endl;
        file << "  \"timestamp\": \"" << ustring::format("{0:L}-{0:k}-{0:i}T{0:t}Z", xtd::tunit::settings::default_settings().start_time()) << "\"," << std::endl;
        file << "  \"time\": \"" << to_string(elapsed_time()) << "s\"," << std::endl;
        file << "  \"name\": \"" << name_to_string(name_) << "\"," << std::endl;
        file << "  \"testsuites\": [" << std::endl;
        for (auto& test_class : test_classes()) {
          file << "    {" << std::endl;
          file << "      \"name\": \"" << escape_to_xml_string(test_class.test()->name()) << "\"," << std::endl;
          file << "      \"tests\": " << test_class.test()->test_count() << "," << std::endl;
          file << "      \"failures\": " << test_class.test()->failed_test_count() << "," << std::endl;
          file << "      \"disabled\": " << test_class.test()->ignored_test_count() << "," << std::endl;
          file << "      \"errors\": " << 0 << "," << std::endl;
          file << "      \"timestamp\": \"" << ustring::format("{0:L}-{0:k}-{0:i}T{0:t}Z", test_class.test()->start_time()) << "\"," << std::endl;
          file << "      \"time\": \"" << to_string(test_class.test()->elapsed_time()) << "s\"," << std::endl;
          file << "      \"testsuite\": [" << std::endl;
          for (auto& test : test_class.test()->tests()) {
            file << "        {" << std::endl;
            file << "          \"name\": \"" << test.name() << "\"," << std::endl;
            file << "          \"file\": \"" << escape_path_to_json_string(test.stack_frame().get_file_name()) << "\"," << std::endl;
            file << "          \"line\": " << test.stack_frame().get_file_line_number() << "," << std::endl;
            file << "          \"status\": \"" << ustring(status_to_string(test)).to_upper() << "\"," << std::endl;
            file << "          \"result\": \"" << (test.ignored() ? "SUPPRESSED" : "COMPLETED") << "\"," << std::endl;
            file << "          \"timestamp\": \"" << ustring::format("{0:L}-{0:k}-{0:i}T{0:t}Z", test.start_time()) << "\"," << std::endl;
            file << "          \"time\": \"" << to_string(test.elapsed_time()) << "s\"," << std::endl;
            file << "          \"classname\": \"" << escape_to_xml_string(test_class.test()->name()) << "\"," << std::endl;
            if (test.failed()) {
              file << "          \"failures\": [" << std::endl;
              file << "            {" << std::endl;
              file << "              \"failure\": \"" << test.stack_frame().get_file_name() << ":" << test.stack_frame().get_file_line_number() << "\\n" <<message_to_json_string(test) <<"\"" << std::endl;
              file << "              \"type\": \"\"" << std::endl;
              file << "            }" << std::endl;
              file << "          ]" << std::endl;
            }
            file << "        }," << std::endl;
          }
          file << "      ]" << std::endl;
          file << "    }," << std::endl;
        }
        file << "  ]" << std::endl;
        file << "}" << std::endl;
        file.close();
      }
      
      void write_tests_xml() {
        std::fstream file(xtd::tunit::settings::default_settings().output_xml_path(), std::ios::out | std::ios::trunc);
        file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
        file << "<testsuites tests=\"" << test_count() << "\" failures=\"" << failed_test_count() << "\" disabled=\"" << ignored_test_count() << "\" errors=\"" << 0 << "\" time=\"" << to_string(elapsed_time()) << "\" timestamp=\"" << xtd::tunit::settings::default_settings().start_time().to_string("S") << "\" name=\"" << name_to_string(name_) << "\">" << std::endl;
        for (auto& test_class : test_classes()) {
          file << "  <testsuite name=\"" << escape_to_xml_string(test_class.test()->name()) << "\" tests=\"" << test_class.test()->test_count() << "\" failures=\"" << test_class.test()->failed_test_count() << "\" disabled=\"" << test_class.test()->ignored_test_count() << "\" skipped=\"" << 0 << "\" errors=\"" << 0 << "\" time=\"" << to_string(test_class.test()->elapsed_time()) << "\" timestamp=\"" << test_class.test()->start_time().to_string("S") << "\">" << std::endl;
          for (auto& test : test_class.test()->tests()) {
            file << "    <testcase name=\"" << test.name() << "\" file=\"" << test.stack_frame().get_file_name() << "\" line=\"" << test.stack_frame().get_file_line_number() << "\" status=\"" << status_to_string(test) << "\" result=\"" << (test.ignored() ? "suppressed" : "completed") << "\" time=\"" << to_string(test.elapsed_time()) << "\" timestamp=\"" << test.start_time().to_string("S") << "\" classname=\"" << escape_to_xml_string(test_class.test()->name()) << "\"";
            if (!test.failed())
              file << " />" << std::endl;
            else {
              file << ">" << std::endl;
              file << "      <failure message=\"" << message_to_xml_string(test) << "\" type=\"" << "\">" << "<![CDATA[" << cdata_message_to_xml_string(test) << "]]></failure>" << std::endl;
              file << "    </testcase>" << std::endl;
            }
          }
          file << "  </testsuite>" << std::endl;
        }
        file << "</testsuites>" << std::endl;
        file.close();
      }

      std::vector<std::string> arguments;
      std::string name_ = "AllTests";
      std::unique_ptr<xtd::tunit::event_listener> event_listener_;
      xtd::date_time end_time_point_;
      int32 repeat_iteration_ = 0;
      xtd::date_time start_time_point_;
    };
  }
}
