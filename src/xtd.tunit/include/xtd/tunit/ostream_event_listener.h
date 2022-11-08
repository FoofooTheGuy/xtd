/// @file
/// @brief Contains xtd::tunit::ostream_event_listener class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "__console_color.h"
#include "event_listener.h"
#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The ostream_unit_test class is a specialisation of event_listener class for writing events in std::ostream.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit tunit
    /// @remarks This class is use by console_unit_test.
    /// @remarks you can use this class as you want as for example communicate between network.
    /// @par Examples
    /// The following examples show how to use ostream_event_listener.
    /// @include ostream_unit_test.cpp
    class ostream_event_listener : public xtd::tunit::event_listener {
    public:
      /// @brief Creates new instance ostream event lister with ostream specified.
      /// @param os std::ostream where events are written.
      ostream_event_listener(std::ostream& os) noexcept : os_(os) {}
      
      /// @brief Occurs when class is ended.
      /// @param class_event_args Contains class event parameters.
      void on_class_end(const xtd::tunit::class_event_args& e) const override {
        if (settings::default_settings().gtest_compatibility()) {
          os_ << __foreground_color(__console_color::dark_green);
          os_ << "[----------] ";
          os_ << __reset_color();
          os_ << e.test_class().test_count() << " tests from " << e.test_class().name() << " (" << e.test_class().elapsed_time().count() << " ms total)" << std::endl << std::endl;
        }
        event_listener::on_class_end(e);
      }
      
      /// @brief Occurs when class cleanup is started.
      /// @param class_event_args Contains class event parameters.
      void on_class_start(const xtd::tunit::class_event_args& e) const override {
        if (settings::default_settings().gtest_compatibility()) {
          os_ << __foreground_color(__console_color::dark_green);
          os_ << "[----------] ";
          os_ << __reset_color();
          os_ << e.test_class().test_count() << " tests from " << e.test_class().name() << std::endl;
        }
        event_listener::on_class_start(e);
      }

      /// @brief Occurs when test is aborted.
      /// @param test_event_args Contains test event parameters.
      void on_test_aborted(const xtd::tunit::test_event_args& e) const override {
        event_listener::on_test_aborted(e);
        if (settings::default_settings().gtest_compatibility()) {
          os_ << e.test().stack_frame().get_file_name() << ":" << e.test().stack_frame().get_file_line_number() << ": Failure" << std::endl;
          if (e.test().actual() != "") os_ << "Value of: " << e.test().actual() << std::endl;
          if (e.test().actual() != "") os_ << "  Actual: " << e.test().actual() << std::endl;
          if (e.test().expect() != "") os_ << "Expected: " << e.test().expect() << std::endl;
          if (e.test().message() != "") os_ << e.test().message() << std::endl;
          os_ << __foreground_color(__console_color::dark_red);
          os_ << "[  ABORTED ] ";
          os_ << __reset_color();
          os_ << e.test_class().name() << "." << e.test().name() << " (" << e.test().elapsed_time().count() << " ms)" << std::endl;
        } else {
          os_ << __foreground_color(__console_color::magenta);
          os_ << "  ABORTED ";
          os_ << __reset_color();
          os_ << e.test_class().name() << "." << e.test().name();
          if (xtd::tunit::settings::default_settings().show_duration())
            os_ << " (" << e.test().elapsed_time().count() << " ms total)";
          os_ << std::endl;
          if (e.test().message() != "")
            os_ << "    " << e.test().message() << std::endl;
          if (e.test().expect() != "")
            os_ << "    Expected: " << e.test().expect() << std::endl;
          if (e.test().actual() != "")
            os_ << "    But was:  " << e.test().actual() << std::endl;
          if ((e.test().expect() != "" || e.test().actual() != "") && e.test().stack_frame() != xtd::diagnostics::stack_frame::empty()) {
            os_ << "    Stack Trace: in " << e.test().stack_frame().get_file_name();
            if (e.test().stack_frame().get_file_line_number() != 0) os_ << ":" << e.test().stack_frame().get_file_line_number();
          }
          os_ << std::endl;
        }
      }
      
      /// @brief Occurs when test initialize is started.
      /// @param test_event_args Contains test event parameters.
      void on_unit_test_cleanup_start(const xtd::tunit::tunit_event_args& e) const override {
        if (settings::default_settings().gtest_compatibility()) {
          os_ << __foreground_color(__console_color::dark_green);
          os_ << "[----------] ";
          os_ << __reset_color();
          os_ << "Global test environment tear-down" << std::endl;
        }
        event_listener::on_unit_test_cleanup_start(e);
      }
      
      /// @brief Occurs when unit test initialize is started.
      /// @param tunit_event_args Contains unit test event parameters.
      void on_unit_test_initialize_start(const xtd::tunit::tunit_event_args& e) const override {
        if (settings::default_settings().gtest_compatibility()) {
          os_ << __foreground_color(__console_color::dark_green);
          os_ << "[----------] ";
          os_ << __reset_color();
          os_ << "Global test environment set-up." << std::endl;
        }
        event_listener::on_unit_test_initialize_start(e);
      }

      /// @brief Occurs when test is failed.
      /// @param test_event_args Contains test event parameters.
      void on_test_failed(const xtd::tunit::test_event_args& e) const override {
        event_listener::on_test_failed(e);
        if (settings::default_settings().gtest_compatibility()) {
          os_ << e.test().stack_frame().get_file_name() << ":" << e.test().stack_frame().get_file_line_number() << ": Failure" << std::endl;
          if (e.test().actual() != "") os_ << "Value of: " << e.test().actual() << std::endl;
          if (e.test().actual() != "") os_ << "  Actual: " << e.test().actual() << std::endl;
          if (e.test().expect() != "") os_ << "Expected: " << e.test().expect() << std::endl;
          if (e.test().message() != "") os_ << e.test().message() << std::endl;
          os_ << __foreground_color(__console_color::dark_red);
          os_ << "[  FAILED  ] ";
          os_ << __reset_color();
          os_ << e.test_class().name() << "." << e.test().name() << " (" << e.test().elapsed_time().count() << " ms)" << std::endl;
        } else {
          os_ << __foreground_color(__console_color::red);
          os_ << "  FAILED  ";
          os_ << __reset_color();
          os_ << e.test_class().name() << "." << e.test().name();
          if (xtd::tunit::settings::default_settings().show_duration())
            os_ << " (" << e.test().elapsed_time().count() << " ms total)";
          os_ << std::endl;
          if (e.test().message() != "")
            os_ << "    " << e.test().message() << std::endl;
          if (e.test().expect() != "")
            os_ << "    Expected: " << e.test().expect() << std::endl;
          if (e.test().actual() != "")
            os_ << "    But was:  " << e.test().actual() << std::endl;
          if (e.test().stack_frame() != xtd::diagnostics::stack_frame::empty()) {
            os_ << "    Stack Trace: in " << e.test().stack_frame().get_file_name();
            if (e.test().stack_frame().get_file_line_number() != 0) os_ << ":" << e.test().stack_frame().get_file_line_number();
          }
          os_ << std::endl;
        }
      }
      
      /// @brief Occurs when test is ignored.
      /// @param test_event_args Contains test event parameters.
      void on_test_ignored(const xtd::tunit::test_event_args& e) const override {
        event_listener::on_test_ignored(e);
        if (settings::default_settings().gtest_compatibility()) {
          os_ << __foreground_color(__console_color::dark_yellow);
          os_ << "[ DISABLED ] ";
          os_ << __reset_color();
          os_ << e.test_class().name() << "." << e.test().name() << std::endl;
        } else {
          os_ << __foreground_color(__console_color::yellow);
          os_ << "  IGNORED ";
          os_ << __reset_color();
          os_ << e.test_class().name() << "." << e.test().name();
          if (xtd::tunit::settings::default_settings().show_duration())
            os_ << " (" << e.test().elapsed_time().count() << " ms total)";
          os_ << std::endl;
          if (e.test().message() != "")
            os_ << "    " << e.test().message() << std::endl;
        }
      }
      
      /// @brief Occurs when test initialize is started.
      /// @param test_event_args Contains test event parameters.
      void on_test_start(const xtd::tunit::test_event_args& e) const override {
        if (settings::default_settings().gtest_compatibility()) {
          os_ << __foreground_color(__console_color::dark_green);
          os_ << "[ RUN      ] ";
          os_ << __reset_color();
          os_ << e.test_class().name() << "." << e.test().name() << std::endl;
        }
        event_listener::on_test_start(e);
      }

      /// @brief Occurs when test is succeed.
      /// @param test_event_args Contains test event parameters.
      void on_test_succeed(const xtd::tunit::test_event_args& e) const override {
        event_listener::on_test_succeed(e);
        if (settings::default_settings().gtest_compatibility()) {
          os_ << __foreground_color(__console_color::dark_green);
          os_ << "[       OK ] ";
          os_ << __reset_color();
          os_ << e.test_class().name() << "." << e.test().name() << " (" << e.test().elapsed_time().count() << " ms)" << std::endl;
        } else {
          os_ << __foreground_color(__console_color::green);
          os_ << "  SUCCEED ";
          os_ << __reset_color();
          os_ << e.test_class().name() << "." << e.test().name();
          if (xtd::tunit::settings::default_settings().show_duration())
            os_ << " (" << e.test().elapsed_time().count() << " ms total)";
          os_ << std::endl;
          if (e.test().message() != "")
            os_ << "    " << e.test().message() << std::endl;
        }
      }
      
      /// @brief Occurs when unit test is ended.
      /// @param tunit_event_args Contains unit test event parameters.
      void on_unit_test_end(const xtd::tunit::tunit_event_args& e) const override {
        event_listener::on_unit_test_end(e);
        if (settings::default_settings().gtest_compatibility()) {
          os_ << __foreground_color(__console_color::dark_green);
          os_ << "[==========] ";
          os_ << __reset_color();
          os_ << e.unit_test().test_count() << " tests from " << e.unit_test().test_cases_count() << " test case ran. (" << e.unit_test().elapsed_time().count() << " ms total)" << std::endl;
          os_ << __foreground_color(__console_color::dark_green);
          os_ << "[  PASSED  ] ";
          os_ << __reset_color();
          os_ << e.unit_test().succeed_test_count() << " tests." << std::endl;
          if (e.unit_test().failed_test_count()) {
            os_ << __foreground_color(__console_color::dark_red);
            os_ << "[  FAILED  ] ";
            os_ << __reset_color();
            os_ << e.unit_test().failed_test_count() << " test, listed below:" << std::endl;
            for (std::string name : e.unit_test().failed_test_names()) {
              os_ << __foreground_color(__console_color::dark_red);
              os_ << "[  FAILED  ] ";
              os_ << __reset_color();
              os_ << name << std::endl;
            }
            os_ << std::endl;
            os_ << " " << e.unit_test().failed_test_count() << " FAILED TEST" << std::endl;
          }
          if (!e.unit_test().failed_test_count() && e.unit_test().ignored_test_count()) os_ << std::endl;
          if (e.unit_test().ignored_test_count()) {
            os_ << __foreground_color(__console_color::dark_yellow);
            os_ << "  YOU HAVE " << e.unit_test().ignored_test_count() << " DISABLED TESTS" << std::endl << std::endl;
            os_ << __reset_color();
          }
        } else {
          os_ << std::endl;
          os_ << "Test results:" << std::endl;
          if (e.unit_test().succeed_test_count()) {
            os_ << __foreground_color(__console_color::green);
            os_ << "  SUCCEED ";
            os_ << __reset_color();
            os_ << e.unit_test().succeed_test_count() << " test" << (e.unit_test().succeed_test_count() < 2 ? "" : "s") << "." << std::endl;
          }
          if (e.unit_test().aborted_test_count()) {
            os_ << __foreground_color(__console_color::magenta);
            os_ << "  ABORTED ";
            os_ << __reset_color();
            os_ << e.unit_test().aborted_test_count() << " test" << (e.unit_test().aborted_test_count() < 2 ? "" : "s") << "." << std::endl;
          }
          if (e.unit_test().failed_test_count()) {
            os_ << __foreground_color(__console_color::red);
            os_ << "  FAILED  ";
            os_ << __reset_color();
            os_ << e.unit_test().failed_test_count() << " test" << (e.unit_test().failed_test_count() < 2 ? "" : "s") << "." << std::endl;
          }
          if (e.unit_test().ignored_test_count()) {
            os_ << __foreground_color(__console_color::yellow);
            os_ << "  IGNORED ";
            os_ << __reset_color();
            os_ << e.unit_test().ignored_test_count() << " test" << (e.unit_test().ignored_test_count() < 2 ? "" : "s") << "." << std::endl;
          }
          
          os_ << "End " << e.unit_test().test_count() << " test" << (e.unit_test().test_count() < 2 ? "" : "s") << " from " << e.unit_test().test_cases_count() << " test case" << (e.unit_test().test_cases_count() < 2 ? "" : "s") << " ran.";
          if (xtd::tunit::settings::default_settings().show_duration())
            os_ << " (" << e.unit_test().elapsed_time().count() << " ms total)";
          os_ << std::endl << std::endl;
        }
      }
      
      /// @brief Occurs when unit test cleanup is started.
      /// @param tunit_event_args Contains unit test event parameters.
      void on_unit_test_start(const xtd::tunit::tunit_event_args& e) const override {
        if (e.unit_test().repeat_tests()) {
          if (!settings::default_settings().gtest_compatibility()) os_ << __foreground_color(__console_color::cyan);
          os_ << "Repeating all tests (iteration " << e.unit_test().repeat_iteration() << ") . . ." << std::endl << std::endl;
          os_ << __reset_color();
        }
        if (settings::default_settings().gtest_compatibility()) {
          os_ << "Running main() from " << settings::default_settings().file_name_ << std::endl;
          os_ << __foreground_color(__console_color::dark_green);
          os_ << "[==========] ";
          os_ << __reset_color();
          os_ << "Running " << e.unit_test().test_count() << " tests from " << e.unit_test().test_cases_count() << " test suites." << std::endl;
        } else {
          os_ << "Start " << e.unit_test().test_count() << " test" << (e.unit_test().test_count() < 2 ? "" : "s") << " from " << e.unit_test().test_cases_count() << " test case" << (e.unit_test().test_cases_count() < 2 ? "" : "s") << std::endl;
          os_ << "Run tests:" << std::endl;
        }
        event_listener::on_unit_test_start(e);
      }
      
    private:
      std::ostream& os_;
    };
  }
}
