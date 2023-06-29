#include <xtd/tunit/file_assume.h>
#include <xtd/tunit/test_class_attribute.h>
#include <xtd/tunit/test_method_attribute.h>
#include "../../../assert_unit_tests/assert_unit_tests.h"

namespace xtd::tunit::tests {
  class test_class_(file_assume_exists_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      file_assume::exists(xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file.txt"), csf_);
    }
  };
}

void test_(file_assume_exists_failed_tests, test_output) {
  auto [output, result] = run_test_("file_assume_exists_failed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  ABORTED file_assume_exists_failed_tests.test_case_failed\n"
    "    Test aborted\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(file_assume_exists_failed_tests, test_result) {
  auto [output, result] = run_test_("file_assume_exists_failed_tests.*");
  assert_value_(0, result);
}
