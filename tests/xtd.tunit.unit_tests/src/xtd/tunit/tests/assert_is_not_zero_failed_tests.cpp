#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(assert_is_not_zero_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      int i = 0;
      xtd::tunit::assert::is_not_zero(i);
    }
  };
}

void test_(assert_is_not_zero_failed_tests, test_output) {
  auto [output, result] = run_test_("assert_is_not_zero_failed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  FAILED  assert_is_not_zero_failed_tests.test_case_failed\n"
    "    Expected: not zero\n"
    "    But was:  0\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(assert_is_not_zero_failed_tests, test_result) {
  auto [output, result] = run_test_("assert_is_not_zero_failed_tests.*");
  assert_value_(1, result);
}
