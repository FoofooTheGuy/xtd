/// @file
/// @brief Contains xtd::tunit::settings class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "../tunit_export.h"
#include <xtd/date_time.h>
#include <xtd/environment.h>
#include <xtd/io/path.h>
#include <cstdlib>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The settings class contains xtd.tunit settings.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit tunit
    class tunit_export_ settings final {
    public:
      /// @brief Creates new instance of settings.
      settings() = default;
      
      /// @cond
      settings(const settings&) = default;
      settings& operator=(const settings&) = default;
      /// @endcond
      
      /// @brief Gets default settings instance.
      /// @return Default settings instance.
      static xtd::tunit::settings& default_settings() noexcept;
      
      /// @brief Gets also run ignored test.
      /// @return true if also run ignored test; otherwise false.
      bool also_run_ignored_tests() const noexcept {return also_run_ignored_tests_;}
      
      /// @brief Sets also run ignored test.
      /// @param also_run_ignored_tests  true if also run ignored test; otherwise false.
      void also_run_ignored_tests(bool also_run_ignored_tests) noexcept {also_run_ignored_tests_ = also_run_ignored_tests;}
      
      /// @brief Gets exit status.
      /// @return exit status.
      /// @remarks The value by default is EXIT_SUCCESS.
      /// @remarks When an error occurred in unit test the value is set to EXIT_FAILURE.
      int exit_status() const noexcept {return exit_status_;}
      
      /// @brief Sets exit status.
      /// @param exit_status exit status.
      /// @remarks The value by default is EXIT_SUCCESS.
      /// @remarks When an error occurred in unit test the value is set to EXIT_FAILURE.
      void exit_status(int exit_status) noexcept {exit_status_ = exit_status;}
      
      /// @brief Gets filter tests.
      /// @return filter tests.
      /// @remarks The value by default is "*.*".
      const std::string& filter_tests() const noexcept {return filter_tests_;}
      
      /// @brief Sets filter tests.
      /// @param filter_tests filter tests.
      /// @remarks The value by default is "*.*".
      void filter_tests(const std::string& filter_tests) noexcept {filter_tests_ = !filter_tests.empty() ? filter_tests : "*.*";}
      
      /// @brief Return true if a specified test class name and specified test name match with the current filter tests.
      /// @return Return true if class name and test name match with the current filter tests; otherwise false.
      bool is_match_test_name(const std::string& test_class_name, const std::string& test_name) const noexcept {return pattern_compare(test_class_name + "." + test_name, filter_tests_);}
      
      /// @brief Gets list tests.
      /// @return true if list tests; otherwise false.
      bool list_tests() const noexcept {return list_tests_;}
      
      /// @brief Sets list tests.
      /// @param list_tests true if list tests; otherwise false.
      void list_tests(bool list_tests) noexcept {list_tests_ = list_tests;}
      
      /// @brief Gets output color.
      /// @return true for colored output; otherwise false.
      bool output_color() const noexcept {return output_color_;}
      
      /// @brief Sets output color.
      /// @param output_color true for colored output; otherwise false.
      void output_color(bool output_color) noexcept {output_color_ = output_color;}
      
      /// @brief Gets output xml.
      /// @return true for generate xml report; otherwise false.
      bool output_json() const noexcept {return output_json_;}
      
      /// @brief Sets output json.
      /// @param output_json true for generate json report; otherwise false.
      void output_json(bool output_json) noexcept {output_json_ = output_json;}
      
      /// @brief Gets output xml.
      /// @return true for generate xml report; otherwise false.
      bool output_xml() const noexcept {return output_xml_;}
      
      /// @brief Sets output xml.
      /// @param output_xml true for generate xml report; otherwise false.
      void output_xml(bool output_xml) noexcept {output_xml_ = output_xml;}
      
      /// @brief Gets output json path.
      /// @return Output json path.
      std::string output_json_path() const noexcept {return output_json_path_;}
      
      /// @brief Sets output sjon path.
      /// @param output_jsonl_path Output json path.
      void output_json_path(const std::string& output_json_path) noexcept {output_json_path_ = output_json_path;}
      
      /// @brief Gets output xml path.
      /// @return Output xml path.
      std::string output_xml_path() const noexcept {return output_xml_path_;}
      
      /// @brief Sets output xml path.
      /// @param output_xml_path Output xml path.
      void output_xml_path(const std::string& output_xml_path) noexcept {output_xml_path_ = output_xml_path;}
      
      /// @brief Gets shuffle tests.
      /// @return Shuffle test.
      /// @remarks By default is set to false (no shuffle).
      bool shuffle_test() const noexcept {return shuffle_tests_;}
      
      /// @brief Sets shuffle tests.
      /// @param shuffle_test Shuffle test.
      /// @remarks By default is set to false (no shuffle).
      void shuffle_test(bool shuffle_test) noexcept {shuffle_tests_ = shuffle_test;}
      
      /// @brief Gets random seed value.
      /// @return Random seed value.
      /// @remarks By default is set to 0 (no seed).
      unsigned int random_seed() const noexcept {return random_seed_;}
      
      /// @brief Sets random seed value.
      /// @param random_seed Random seed value.
      /// @remarks By default is set to 0 (no seed).
      void random_seed(unsigned int random_seed) noexcept {random_seed_ = random_seed;}
      
      /// @brief Gets repeat tests count.
      /// @return Repeat test count.
      /// @remarks By default is set to 1 (no repeat).
      int repeat_test() const noexcept {return repeat_tests_;}
      
      /// @brief Sets repeat tests count.
      /// @param repeat_tests Repeat test count.
      /// @remarks By default is set to 1 (no repeat).
      void repeat_tests(int repeat_tests) noexcept {repeat_tests_ = repeat_tests;}
      
      /// @brief Gets if show duration for each test.
      /// @return true if show duration for each test; otherwise false.
      bool show_duration() const noexcept {return show_duration_;}
      
      /// @brief Sets if show duration for each test.
      /// @param show_duration true if show duration for each test; otherwise false.
      void show_duration(bool show_duration) noexcept {show_duration_ = show_duration;}
      
      /// @brief Gets unit test end time.
      /// @return Unit test end time.
      const xtd::date_time& end_time() const noexcept {return end_time_;}
      
      /// @brief Gets unit test start time.
      /// @return Unit test start time.
      const xtd::date_time& start_time() const noexcept {return start_time_;}
      
      /// @brief Gets stack trace enabled.
      /// @return true if stack trace enabled; otherwise false.
      /// @remarks The default value is false for increase the unit test execution.
      bool enable_stack_trace() const noexcept {return enable_stack_trace_;}
      
      /// @brief Sets stack trace enabled.
      /// @param enable_stack_trace true if stack trace enabled; otherwise false.
      /// @remarks The default value is false for increase the unit test execution.
      void enable_stack_trace(bool enable_stack_trace) noexcept {enable_stack_trace_ = enable_stack_trace;}

    private:
      friend class unit_test;
      friend class ostream_unit_test;

      bool pattern_compare(const std::string& name, const std::string& pattern) const noexcept {
        if (pattern == "") return name == "";
        if (name == "") return false;
        if (pattern == "*" || pattern == "*.*") return true;
        if (pattern[0] == '*') return pattern_compare(name, pattern.substr(1)) || pattern_compare(name.substr(1), pattern);
        return ((pattern[0] == '?') || (name[0] == pattern[0])) && pattern_compare(name.substr(1), pattern.substr(1));
      }
      
      void end_time(const xtd::date_time& end_time) noexcept {start_time_ = end_time;}
      void start_time(const xtd::date_time& start_time) noexcept {start_time_ = start_time;}
      
      bool also_run_ignored_tests_ = false;
      std::string filter_tests_ = "*.*";
      int exit_status_ = EXIT_SUCCESS;
      bool gtest_compatibility_ = false;
      bool list_tests_ = false;
      bool output_color_ = true;
      bool output_json_ = false;
      bool output_xml_ = false;
      std::string output_json_path_ = "tests.json";
      std::string output_xml_path_ = "tests.xml";
      std::string file_name_ = xtd::io::path::get_full_path(xtd::environment::get_command_line_args()[0]);
      bool show_duration_ = true;
      bool shuffle_tests_ = false;
      unsigned int random_seed_ = 0;
      int repeat_tests_ = 1;
      bool enable_stack_trace_ = false;
      xtd::date_time start_time_;
      xtd::date_time end_time_;
    };
  }
}
