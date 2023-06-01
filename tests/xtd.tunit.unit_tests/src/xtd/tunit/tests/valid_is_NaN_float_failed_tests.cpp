#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(valid_is_NaN_float_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      float f = 3.14159f;
      xtd::tunit::valid::is_NaN(f);
    }
  };
}

void test_(valid_is_NaN_float_failed_tests, test_output) {
  auto [output, result] = run_test_("valid_is_NaN_float_failed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  FAILED  valid_is_NaN_float_failed_tests.test_case_failed\n"
    "    Expected: NaN\n"
    "    But was:  3.14159\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(valid_is_NaN_float_failed_tests, test_result) {
  auto [output, result] = run_test_("valid_is_NaN_float_failed_tests.*");
  assert_value_(1, result);
}
