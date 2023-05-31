#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>


namespace xtd::tunit::tests {
  class test_class_(one_test_two_test_cases_tests) {
  public:
    void test_method_(test_case1) {
    }
    void test_method_(test_case2) {
    }
  };
}

void test_(one_test_two_test_cases_tests, test_output) {
  auto [result, output] = run_test_("one_test_two_test_cases_tests*");
  assert_value_("Start 2 tests from 1 test case\n"
    "  SUCCEED one_test_two_test_cases_tests.test_case1\n"
    "  SUCCEED one_test_two_test_cases_tests.test_case2\n"
    "End 2 tests from 1 test case ran.\n", output);
}

void test_(one_test_two_test_cases_tests, test_result) {
  auto [result, output] = run_test_("one_test_two_test_cases_tests*");
  assert_value_(0, result);
}
