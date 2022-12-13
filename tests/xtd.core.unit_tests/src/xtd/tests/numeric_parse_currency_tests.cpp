#include <xtd/ustring.h>
#include <xtd/format_exception.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  template <typename Value>
  class numeric_parse_string_currency_tests;
  
  test_class_attribute<numeric_parse_string_currency_tests<char>> numeric_parse_string_currency_tests_class_char_attr {"numeric_parse_string_currency_tests<char>"};
  test_class_attribute<numeric_parse_string_currency_tests<unsigned char>> numeric_parse_string_currency_tests_class_unsigned_char_attr {"numeric_parse_string_currency_tests<unsigned_char>"};
  test_class_attribute<numeric_parse_string_currency_tests<short>> numeric_parse_string_currency_tests_class_short_attr {"numeric_parse_string_currency_tests<short>"};
  test_class_attribute<numeric_parse_string_currency_tests<unsigned short>> numeric_parse_string_currency_tests_class_unsigned_short_attr {"numeric_parse_string_currency_tests<unsigned_short>"};
  test_class_attribute<numeric_parse_string_currency_tests<int>> numeric_parse_string_currency_tests_class_int_attr {"numeric_parse_string_currency_tests<int>"};
  test_class_attribute<numeric_parse_string_currency_tests<unsigned int>> numeric_parse_string_currency_tests_class_unsigned_int_attr {"numeric_parse_string_currency_tests<unsigned_int>"};
  test_class_attribute<numeric_parse_string_currency_tests<long>> numeric_parse_string_currency_tests_class_long_attr {"numeric_parse_string_currency_tests<long>"};
  test_class_attribute<numeric_parse_string_currency_tests<unsigned long>> numeric_parse_string_currency_tests_class_unsigned_long_attr {"numeric_parse_string_currency_tests<unsigned_long>"};
  test_class_attribute<numeric_parse_string_currency_tests<long long>> numeric_parse_string_currency_tests_class_long_long_attr {"numeric_parse_string_currency_tests<long_long>"};
  test_class_attribute<numeric_parse_string_currency_tests<unsigned long long>> numeric_parse_string_currency_tests_class_unsigned_long_long_attr {"numeric_parse_string_currency_tests<unsigned_long_long>"};
  test_class_attribute<numeric_parse_string_currency_tests<sbyte>> numeric_parse_string_currency_tests_class_int8_t_attr {"numeric_parse_string_currency_tests<sbyte>"};
  test_class_attribute<numeric_parse_string_currency_tests<int16>> numeric_parse_string_currency_tests_class_int16_t_attr {"numeric_parse_string_currency_tests<int16>"};
  test_class_attribute<numeric_parse_string_currency_tests<int32>> numeric_parse_string_currency_tests_class_int32_t_attr {"numeric_parse_string_currency_tests<int32>"};
  test_class_attribute<numeric_parse_string_currency_tests<int64>> numeric_parse_string_currency_tests_class_int64_t_attr {"numeric_parse_string_currency_tests<int64>"};
  test_class_attribute<numeric_parse_string_currency_tests<intptr_t>> numeric_parse_string_currency_tests_class_intptr_t_attr {"numeric_parse_string_currency_tests<intptr_t>"};
  test_class_attribute<numeric_parse_string_currency_tests<ptrdiff_t>> numeric_parse_string_currency_tests_class_ptrdiff_t_attr {"numeric_parse_string_currency_tests<ptrdiff_t>"};
  test_class_attribute<numeric_parse_string_currency_tests<size_t>> numeric_parse_string_currency_tests_class_size_t_attr {"numeric_parse_string_currency_tests<size_t>"};
  test_class_attribute<numeric_parse_string_currency_tests<xtd::byte>> numeric_parse_string_currency_tests_class_uint8_t_attr {"numeric_parse_string_currency_tests<xtd::byte>"};
  test_class_attribute<numeric_parse_string_currency_tests<uint16_t>> numeric_parse_string_currency_tests_class_uint16_t_attr {"numeric_parse_string_currency_tests<uint16_t>"};
  test_class_attribute<numeric_parse_string_currency_tests<uint32_t>> numeric_parse_string_currency_tests_class_uint32_t_attr {"numeric_parse_string_currency_tests<uint32_t>"};
  test_class_attribute<numeric_parse_string_currency_tests<uint64_t>> numeric_parse_string_currency_tests_class_uint64_t_attr {"numeric_parse_string_currency_tests<uint64_t>"};
  test_class_attribute<numeric_parse_string_currency_tests<uintptr_t>> numeric_parse_string_currency_tests_class_uintptr_t_attr {"numeric_parse_string_currency_tests<uintptr_t>"};
  
  template <typename Value>
  class numeric_parse_string_currency_tests : public test_class {
  public:
    static void class_initialize_(class_initialize) {
      std::locale::global(std::locale("en_US.UTF-8"));
    }
    
    void test_method_(parse_styles_currency) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42", number_styles::currency), csf_);
    }
    
    void test_method_(parse_styles_currency_with_leading_white_spaces) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>(" \f\n\r\t\v42", number_styles::currency), csf_);
    }
    
    void test_method_(parse_styles_currency_with_trailing_white_spaces) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42 \f\n\r\t\v", number_styles::currency), csf_);
    }
    
    void test_method_(parse_styles_currency_with_leading_plus_sign) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("+42", number_styles::currency), csf_);
    }
    
    void test_method_(parse_styles_currency_with_two_leading_plus_sign) {
      assert::throws<format_exception>([] {xtd::parse<Value>("++42", number_styles::currency);}, csf_);
    }
    
    void test_method_(parse_styles_currency_with_leading_minus_sign) {
      if (std::is_signed<Value>::value)
        assert::are_equal(static_cast<Value>(-42), xtd::parse<Value>("-42", number_styles::currency), csf_);
      else
        assert::throws<format_exception>([] {xtd::parse<Value>("-42", number_styles::currency);}, csf_);
    }
    
    void test_method_(parse_styles_currency_with_two_leading_minus_sign) {
      assert::throws<format_exception>([] {xtd::parse<Value>("--42", number_styles::currency);}, csf_);
    }
    
    void test_method_(parse_styles_currency_with_trailing_plus_sign) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42+", number_styles::currency), csf_);
    }
    
    void test_method_(parse_styles_currency_with_two_trailing_plus_sign) {
      assert::throws<format_exception>([] {xtd::parse<Value>("42++", number_styles::currency);}, csf_);
    }
    
    void test_method_(parse_styles_currency_with_trailing_minus_sign) {
      if (std::is_signed<Value>::value)
        assert::are_equal(static_cast<Value>(-42), xtd::parse<Value>("42-", number_styles::currency), csf_);
      else
        assert::throws<format_exception>([] {xtd::parse<Value>("42-", number_styles::currency);}, csf_);
    }
    
    void test_method_(parse_styles_currency_with_two_trailing_minus_sign) {
      assert::throws<format_exception>([] {xtd::parse<Value>("42--", number_styles::currency);}, csf_);
    }
    
    void test_method_(parse_styles_currency_with_parentheses) {
      if (std::is_signed<Value>::value)
        assert::are_equal(static_cast<Value>(-42), xtd::parse<Value>("(42)", number_styles::currency), csf_);
      else
        assert::throws<format_exception>([] {xtd::parse<Value>("(42)", number_styles::currency);}, csf_);
    }
    
    void test_method_(parse_styles_currency_with_two_parentheses) {
      assert::throws<format_exception>([] {xtd::parse<Value>("((42))", number_styles::currency);}, csf_);
    }
    
    void test_method_(parse_styles_currency_with_decimal_point) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42.0", number_styles::currency), csf_);
    }
    
    void test_method_(parse_styles_currency_with_two_decimal_point) {
      assert::throws<format_exception>([] {xtd::parse<Value>("4.2.0", number_styles::currency);}, csf_);
    }
    
    void test_method_(parse_styles_currency_with_thousands) {
      if (!std::is_same<Value, sbyte>::value && !std::is_same<Value, char>::value && !std::is_same<Value, unsigned char>::value)
        assert::are_equal(static_cast<Value>(1234), xtd::parse<Value>("1,234", number_styles::currency), csf_);
    }
    
    void test_method_(parse_styles_currency_with_two_thousands) {
      if (!std::is_same<Value, sbyte>::value && !std::is_same<Value, char>::value && !std::is_same<Value, unsigned char>::value)
        assert::throws<format_exception>([] {xtd::parse<Value>("1,,234", number_styles::currency);}, csf_);
    }
    
    void test_method_(parse_styles_currency_with_exponent) {
      assert::throws<format_exception>([] {xtd::parse<Value>("4E+01", number_styles::currency);}, csf_);
    }
    
    void test_method_(parse_styles_currency_with_leading_currency_symbol) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("$42", number_styles::currency), csf_);
    }
    
    void test_method_(parse_styles_currency_with_trailing_currency_symbol) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42$", number_styles::currency), csf_);
    }
    
    void test_method_(parse_styles_currency_with_binary_specifier) {
      assert::throws<format_exception>([] {xtd::parse<Value>("0b101010", number_styles::currency);}, csf_);
    }
    
    void test_method_(parse_styles_currency_with_octal_specifier) {
      assert::are_equal(static_cast<Value>(52), xtd::parse<Value>("052", number_styles::currency), csf_);
    }
    
    void test_method_(parse_styles_currency_with_hexa_specifier) {
      assert::throws<format_exception>([] {xtd::parse<Value>("0x2A", number_styles::currency);}, csf_);
    }
    
    void test_method_(parse_styles_currency_invalid) {
      assert::throws<format_exception>([] {xtd::parse<Value>("z42", number_styles::currency);}, csf_);
    }
  };
}
