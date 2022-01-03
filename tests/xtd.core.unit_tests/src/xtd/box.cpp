#include <sstream>
#include <xtd/date_time.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_box) {
  public:
    void test_method_(create_box_with_default_constructor) {
      box<int32_t> b;
      assert::is_zero(b.value(), csf_);
    }
    
    void test_method_(create_box_value_type) {
      box<int32_t> b;
      assert::is_true(is<int32_t>(b.value()), csf_);
      assert::is_zero(b.value(), csf_);
    }
    
    void test_method_(create_box_with_value_constructor) {
      box<int32_t> b(42);
      assert::are_equal(42, b.value(), csf_);
    }

    void test_method_(create_box_with_copy_constructor) {
      box<int32_t> b1(42);
      box<int32_t> b2(b1);
      assert::are_equal(42, b2.value(), csf_);
    }

    void test_method_(box_equal_operator) {
      box<int32_t> b;
      b = 42;
      assert::are_equal(42, b.value(), csf_);
    }

    void test_method_(box_value_type_operator) {
      box<int32_t> b(42);
      int32_t i = b;
      assert::are_equal(42, i, csf_);
    }

    void test_method_(box_get_value) {
      box<int32_t> b(42);
      int32_t i = b.value();
      assert::are_equal(42, i, csf_);
    }

    void test_method_(box_set_value) {
      box<int32_t> b;
      b.value(42);
      assert::are_equal(42, b.value(), csf_);
    }

    void test_method_(box_equals) {
      box<int32_t> b1(42);
      box<int32_t> b2(42);
      assert::is_true(b1 == b2, csf_);
      
      box<int32_t> b3(41);
      assert::is_false(b1 == b3, csf_);
      
      object& o1 = b2;
      assert::is_true(b1 == o1, csf_);
      
      object& o2 = b3;
      assert::is_false(b1 == o2, csf_);
      
      ustring s1;
      object& o3 = s1;
      assert::is_false(b1 == o3, csf_);
    }

    void test_method_(box_compare_to) {
      box<int32_t> b1(42);
      box<int32_t> b2(42);
      assert::is_false(b1 < b2, csf_);
      assert::is_true(b1 <= b2, csf_);
      assert::is_false(b1 > b2, csf_);
      assert::is_true(b1 >= b2, csf_);

      box<int32_t> b3(41);
      assert::is_false(b1 < b3, csf_);
      assert::is_false(b1 <= b3, csf_);
      assert::is_true(b1 > b3, csf_);
      assert::is_true(b1 >= b3, csf_);

      box<int32_t> b4(43);
      assert::is_true(b1 < b4, csf_);
      assert::is_true(b1 <= b4, csf_);
      assert::is_false(b1 > b4, csf_);
      assert::is_false(b1 >= b4, csf_);

      object& o1 = b2;
      assert::is_false(b1 < o1, csf_);
      assert::is_true(b1 <= o1, csf_);
      assert::is_false(b1 > o1, csf_);
      assert::is_true(b1 >= o1, csf_);

      object& o2 = b3;
      assert::is_false(b1 < o2, csf_);
      assert::is_false(b1 <= o2, csf_);
      assert::is_true(b1 > o2, csf_);
      assert::is_true(b1 >= o2, csf_);

      object& o3 = b4;
      assert::is_true(b1 < o3, csf_);
      assert::is_true(b1 <= o3, csf_);
      assert::is_false(b1 > o3, csf_);
      assert::is_false(b1 >= o3, csf_);

      ustring s1;
      object& o4 = s1;
      assert::is_true(b1 < o4, csf_);
      assert::is_true(b1 <= o4, csf_);
      assert::is_false(b1 > o4, csf_);
      assert::is_false(b1 >= o4, csf_);
    }
    
    void test_method_(box_parse) {
      assert::are_equal(42, box<int32_t>::parse("42"));
    }
    
    void test_method_(box_to_string) {
      assert::are_equal("42", box<int32_t>(42).to_string());
    }
    
    void test_method_(box_to_string_wth_format) {
      assert::are_equal("2A", box<int32_t>(42).to_string("X"));
    }
    
    void test_method_(box_try_parse) {
      int32_t value = 0;
      assert::is_true(box<int32_t>(42).try_parse("42", value));
      assert::are_equal(42, value);
      
      value = 0;
      assert::is_false(box<int32_t>(42).try_parse("xxx", value));
      assert::is_zero(value);
    }
  };
}
