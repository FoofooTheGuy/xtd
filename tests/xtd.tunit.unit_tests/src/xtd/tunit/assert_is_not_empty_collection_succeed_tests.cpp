#include "assert_unit_tests.h"
#include <xtd/xtd.tunit>
#include <vector>

namespace xtd::tunit::tests {
  class test_class_(assert_is_not_empty_collection_succeed_testst) {
  public:
    void test_method_(test_case_succeed) {
      std::vector v = {0, 1, 2, 3};
      xtd::tunit::assert::is_not_empty(v);
    }
  };
}

void test_(assert_is_not_empty_collection_succeed_testst, test_output) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("assert_is_not_empty_collection_succeed_testst.*");
  std::stringstream ss;
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED assert_is_not_empty_collection_succeed_testst.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", ss.str());
}

void test_(assert_is_not_empty_collection_succeed_testst, test_result) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("assert_is_not_empty_collection_succeed_testst.*");
  std::stringstream ss;
  assert_value_(0, xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}
