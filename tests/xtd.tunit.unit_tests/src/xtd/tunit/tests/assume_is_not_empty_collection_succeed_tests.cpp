#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>
#include <vector>

namespace xtd::tunit::tests {
  class test_class_(assume_is_not_empty_collection_succeed_testst) {
  public:
    void test_method_(test_case_succeed) {
      std::vector v = {0, 1, 2, 3};
      xtd::tunit::assume::is_not_empty(v);
    }
  };
}

void test_(assume_is_not_empty_collection_succeed_testst, test_output) {
  auto [output, result] = run_test_("assume_is_not_empty_collection_succeed_testst.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED assume_is_not_empty_collection_succeed_testst.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(assume_is_not_empty_collection_succeed_testst, test_result) {
  auto [output, result] = run_test_("assume_is_not_empty_collection_succeed_testst.*");
  assert_value_(0, result);
}
