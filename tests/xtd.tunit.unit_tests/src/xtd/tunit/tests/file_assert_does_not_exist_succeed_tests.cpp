#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(file_assert_does_not_exist_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      file_assert::does_not_exist(xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file.txt"), csf_);
    }
  };
}

void test_(file_assert_does_not_exist_succeed_tests, test_output) {
  auto [output, result] = run_test_("file_assert_does_not_exist_succeed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED file_assert_does_not_exist_succeed_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(file_assert_does_not_exist_succeed_tests, test_result) {
  auto [output, result] = run_test_("file_assert_does_not_exist_succeed_tests.*");
  assert_value_(0, result);
}
