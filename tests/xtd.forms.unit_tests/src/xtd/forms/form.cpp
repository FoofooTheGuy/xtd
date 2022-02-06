#include <xtd/forms/form.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_form) {
  public:
    void test_method_(new_form_back_color) {
      form form;
      assert::are_equal(form.default_back_color(), form.back_color(), csf_);
    }
    
    void test_method_(new_form_client_size) {
      form form;
      assert::is_less_or_equal(form.client_size().height(), form.size().height(), csf_);
      assert::is_less_or_equal(form.client_size().width(), form.size().width(), csf_);
    }
    
    void test_method_(new_form_fore_color) {
      form form;
      assert::are_equal(form.default_fore_color(), form.fore_color(), csf_);
    }
    
    void test_method_(new_form_default_back_color) {
      form form;
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), form.default_back_color(), csf_);
    }
    
    void test_method_(new_form_default_fore_color) {
      form form;
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), form.default_fore_color(), csf_);
    }
    
    void test_method_(new_form_parent_default_size) {
      form form;
      assert::are_equal(xtd::drawing::size(300, 300), form.default_size(), csf_);
    }
    
    void test_method_(new_form_handle) {
      form form;
      assert::is_not_zero(form.handle(), csf_);
    }
    
    void test_method_(new_form_parent) {
      form form;
      assert::is_false(form.parent().has_value(), csf_);
    }
    
    void test_method_(new_form_size) {
      form form;
      assert::are_equal(form.default_size(), form.size(), csf_);
    }
  };
}
