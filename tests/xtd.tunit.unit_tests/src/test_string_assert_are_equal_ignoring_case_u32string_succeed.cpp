#include "assert_unit_tests.hpp"
#include <xtd/tunit>

namespace unit_tests {
  class test_class_(test_string_assert_are_equal_ignoring_case_u32string_succeed) {
  public:
    void test_method_(test_case_succeed) {
      std::u32string s = U"VALUE";
      xtd::tunit::string_assert::are_equal_ingoring_case(U"value", s);
    }
  };
}

void test_(test_string_assert_are_equal_ignoring_case_u32string_succeed, test_output) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_string_assert_are_equal_ignoring_case_u32string_succeed.*");
  std::stringstream ss;
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
                "  SUCCEED test_string_assert_are_equal_ignoring_case_u32string_succeed.test_case_succeed\n"
                "End 1 test from 1 test case ran.\n", ss.str());
}

void test_(test_string_assert_are_equal_ignoring_case_u32string_succeed, test_result) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_string_assert_are_equal_ignoring_case_u32string_succeed.*");
  std::stringstream ss;
  assert_value_(0, xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}
