#include <xtd/xtd.console>
#include <xtd/tunit>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_delegate) {
  public:
    void test_method_(create_empty_console_key_info) {
      console_key_info cki;
      
      assert::is_zero_(cki.key_char());
      assert::are_equal_(0, static_cast<int>(cki.key()));
      assert::are_equal_(0, static_cast<int>(cki.modifiers()));
    }
    
    void test_method_(create_console_key_info_with_key_char_key) {
      console_key_info cki('a', console_key::a, false, false, false);

      assert::are_equal_('a', cki.key_char());
      assert::are_equal_(static_cast<int>(console_key::a), static_cast<int>(cki.key()));
      assert::are_equal_(0, static_cast<int>(cki.modifiers()));
    }
    
    void test_method_(create_console_key_info_with_key_char_key_and_shift) {
      console_key_info cki(' ', console_key::spacebar, true, false, false);
      
      assert::are_equal_(' ', cki.key_char());
      assert::are_equal_(static_cast<int>(console_key::spacebar), static_cast<int>(cki.key()));
      assert::is_zero_(static_cast<int>(cki.modifiers()) & static_cast<int>(console_modifiers::alt));
      assert::are_equal_(static_cast<int>(console_modifiers::shift), static_cast<int>(cki.modifiers()) & static_cast<int>(console_modifiers::shift));
      assert::is_zero_(static_cast<int>(cki.modifiers()) & static_cast<int>(console_modifiers::control));
    }
    
    void test_method_(create_console_key_info_with_key_char_key_and_alt) {
      console_key_info cki('\0', console_key::up_arrow, false, true, false);
      
      assert::are_equal_('\0', cki.key_char());
      assert::are_equal_(static_cast<int>(console_key::up_arrow), static_cast<int>(cki.key()));
      assert::are_equal_(static_cast<int>(console_modifiers::alt), static_cast<int>(cki.modifiers()) & static_cast<int>(console_modifiers::alt));
      assert::is_zero_(static_cast<int>(cki.modifiers()) & static_cast<int>(console_modifiers::shift));
      assert::is_zero_(static_cast<int>(cki.modifiers()) & static_cast<int>(console_modifiers::control));
    }
    
    void test_method_(create_console_key_info_with_key_char_key_and_control) {
      console_key_info cki('\t', console_key::tab, false, false, true);

      assert::are_equal_('\t', cki.key_char());
      assert::are_equal_(static_cast<int>(console_key::tab), static_cast<int>(cki.key()));
      assert::is_zero_(static_cast<int>(cki.modifiers()) & static_cast<int>(console_modifiers::alt));
      assert::is_zero_(static_cast<int>(cki.modifiers()) & static_cast<int>(console_modifiers::shift));
      assert::are_equal_(static_cast<int>(console_modifiers::control), static_cast<int>(cki.modifiers()) & static_cast<int>(console_modifiers::control));
    }
  };
}
