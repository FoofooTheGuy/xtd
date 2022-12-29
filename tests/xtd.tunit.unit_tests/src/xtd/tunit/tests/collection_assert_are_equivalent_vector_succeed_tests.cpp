#include "assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(collection_assert_are_equivalent_vector_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      std::vector<int> a = {1, 2, 3, 4};
      xtd::tunit::collection_assert::are_equivalent({4, 3, 2, 1}, a);
    }
  };
}

void test_(collection_assert_are_equivalent_vector_succeed_tests, test_output) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("collection_assert_are_equivalent_vector_succeed_tests.*");
  std::stringstream ss;
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED collection_assert_are_equivalent_vector_succeed_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", ss.str());
}

void test_(collection_assert_are_equivalent_vector_succeed_tests, test_result) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("collection_assert_are_equivalent_vector_succeed_tests.*");
  std::stringstream ss;
  assert_value_(0, xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}
