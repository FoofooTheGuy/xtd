#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>
#include <memory>

namespace xtd::tunit::tests {
  class test_class_(valid_is_null_unqiue_ptr_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      std::unique_ptr<int> p = std::make_unique<int>(42);
      xtd::tunit::valid::is_null(p);
    }
  };
}

void test_(valid_is_null_unqiue_ptr_failed_tests, test_output) {
  auto [output, result] = run_test_("valid_is_null_unqiue_ptr_failed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  FAILED  valid_is_null_unqiue_ptr_failed_tests.test_case_failed\n"
    "    Expected: null\n"
    "    But was:  not null\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(valid_is_null_unqiue_ptr_failed_tests, test_result) {
  auto [output, result] = run_test_("valid_is_null_unqiue_ptr_failed_tests.*");
  assert_value_(1, result);
}
