#include <xtd/arithmetic_exception.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(arithmetic_exception_tests) {
  public:
    void test_method_(default_creator) {
      arithmetic_exception e;
      assert::are_equal_(std::system_category(), e.error_code().category());
      assert::is_false_(e.inner_exception().has_value());
      assert::is_empty_(e.file_path());
      assert::is_empty_(e.help_link());
      assert::are_equal_(0, e.error_code().value());
      assert::are_equal_(0U, e.line_number());
      assert::is_empty_(e.member_name());
      assert::are_equal_("Overflow or underflow in the arithmetic operation.", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::is_empty_(e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception : Overflow or underflow in the arithmetic operation.", e.to_string());
      assert::are_equal_("Overflow or underflow in the arithmetic operation.", e.what());
    }
    
    void test_method_(default_creator_with_current_stack_frame) {
      auto info = current_stack_frame_;
      arithmetic_exception e(info);
      assert::are_equal_(std::system_category(), e.error_code().category());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(info.get_file_name(), e.file_path());
      assert::is_empty_(e.help_link());
      assert::are_equal_(0, e.error_code().value());
      assert::are_equal_(info.get_file_line_number(), e.line_number());
      assert::are_equal_(info.get_method(), e.member_name());
      assert::are_equal_("Overflow or underflow in the arithmetic operation.", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::are_equal_(info.to_string(), e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception : Overflow or underflow in the arithmetic operation.\n" + info.to_string(), e.to_string());
      assert::are_equal_("Overflow or underflow in the arithmetic operation.", e.what());
    }
    
    void test_method_(creator_with_empty_message) {
      arithmetic_exception e("");
      assert::are_equal_(0, e.error_code().value());
      assert::are_equal_(std::system_category(), e.error_code().category());
      assert::is_empty_(e.file_path());
      assert::is_empty_(e.help_link());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(0U, e.line_number());
      assert::is_empty_(e.member_name());
      assert::are_equal_("", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::is_empty_(e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception", e.to_string());
      assert::are_equal_("xtd::arithmetic_exception", e.what());
    }
    
    void test_method_(creator_with_message_empty_and_stack_frame) {
      auto info = current_stack_frame_;
      arithmetic_exception e("", info);
      assert::are_equal_(info.get_file_name(), e.file_path());
      assert::is_empty_(e.help_link());
      assert::are_equal_(0, e.error_code().value());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(std::system_category(), e.error_code().category());
      assert::are_equal_(info.get_file_line_number(), e.line_number());
      assert::are_equal_(info.get_method(), e.member_name());
      assert::are_equal_("", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::are_equal_(info.to_string(), e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception\n" + info.to_string(), e.to_string());
      assert::are_equal_("xtd::arithmetic_exception", e.what());
    }
    
    void test_method_(creator_with_message) {
      arithmetic_exception e("Test excpetion message.");
      assert::are_equal_(0, e.error_code().value());
      assert::are_equal_(std::system_category(), e.error_code().category());
      assert::is_empty_(e.file_path());
      assert::is_empty_(e.help_link());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(0U, e.line_number());
      assert::is_empty_(e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::is_empty_(e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception : Test excpetion message.", e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(creator_with_message_and_stack_frame) {
      auto info = current_stack_frame_;
      arithmetic_exception e("Test excpetion message.", info);
      assert::are_equal_(info.get_file_name(), e.file_path());
      assert::is_empty_(e.help_link());
      assert::are_equal_(0, e.error_code().value());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(std::system_category(), e.error_code().category());
      assert::are_equal_(info.get_file_line_number(), e.line_number());
      assert::are_equal_(info.get_method(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::are_equal_(info.to_string(), e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception : Test excpetion message.\n" + info.to_string(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(creator_with_message_error_and_stack_frame) {
      auto info = current_stack_frame_;
      arithmetic_exception e("Test excpetion message.", std::error_code(EBUSY, std::generic_category()), info);
      assert::are_equal_(EBUSY, e.error_code().value());
      assert::are_equal_(std::generic_category(), e.error_code().category());
      assert::are_equal_(info.get_file_name(), e.file_path());
      assert::is_empty_(e.help_link());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(info.get_file_line_number(), e.line_number());
      assert::are_equal_(info.get_method(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::are_equal_(info.to_string(), e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception : Test excpetion message.\n" + info.to_string(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(creator_with_message_help_link_and_stack_frame) {
      auto info = current_stack_frame_;
      arithmetic_exception e("Test excpetion message.", "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal_(0, e.error_code().value());
      assert::are_equal_(std::system_category(), e.error_code().category());
      assert::are_equal_(info.get_file_name(), e.file_path());
      assert::are_equal_("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(info.get_file_line_number(), e.line_number());
      assert::are_equal_(info.get_method(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::are_equal_(info.to_string(), e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception : Test excpetion message.\n" + info.to_string(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(creator_with_message_error_help_link_and_stack_frame) {
      auto info = current_stack_frame_;
      arithmetic_exception e("Test excpetion message.", std::error_code(EBUSY, std::generic_category()), "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal_(EBUSY, e.error_code().value());
      assert::are_equal_(std::generic_category(), e.error_code().category());
      assert::are_equal_(info.get_file_name(), e.file_path());
      assert::are_equal_("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(info.get_file_line_number(), e.line_number());
      assert::are_equal_(info.get_method(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::are_equal_(info.to_string(), e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception : Test excpetion message.\n" + info.to_string(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(creator_with_message_and_inner_exception) {
      system_exception inner_exception;
      arithmetic_exception e("Test excpetion message.", inner_exception);
      assert::are_equal_(0, e.error_code().value());
      assert::are_equal_(std::system_category(), e.error_code().category());
      assert::is_empty_(e.file_path());
      assert::is_empty_(e.help_link());
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get());
      assert::are_equal_(inner_exception.what(), e.inner_exception().value().get().what());
      assert::are_equal_(0U, e.line_number());
      assert::is_empty_(e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::is_empty_(e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception : Test excpetion message.", e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(creator_with_message_inner_exception_and_stack_frame) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      arithmetic_exception e("Test excpetion message.", inner_exception, info);
      assert::are_equal_(info.get_file_name(), e.file_path());
      assert::is_empty_(e.help_link());
      assert::are_equal_(0, e.error_code().value());
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get());
      assert::are_equal_(inner_exception.what(), e.inner_exception().value().get().what());
      assert::are_equal_(std::system_category(), e.error_code().category());
      assert::are_equal_(info.get_file_line_number(), e.line_number());
      assert::are_equal_(info.get_method(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::are_equal_(info.to_string(), e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception : Test excpetion message.\n" + info.to_string(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(creator_with_message_inner_exception_error_and_stack_frame) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      arithmetic_exception e("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), info);
      assert::are_equal_(EBUSY, e.error_code().value());
      assert::are_equal_(std::generic_category(), e.error_code().category());
      assert::are_equal_(info.get_file_name(), e.file_path());
      assert::is_empty_(e.help_link());
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get());
      assert::are_equal_(inner_exception.what(), e.inner_exception().value().get().what());
      assert::are_equal_(info.get_file_line_number(), e.line_number());
      assert::are_equal_(info.get_method(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::are_equal_(info.to_string(), e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception : Test excpetion message.\n" + info.to_string(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(creator_with_message_inner_exception_help_link_and_stack_frame) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      arithmetic_exception e("Test excpetion message.", inner_exception, "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal_(0, e.error_code().value());
      assert::are_equal_(std::system_category(), e.error_code().category());
      assert::are_equal_(info.get_file_name(), e.file_path());
      assert::are_equal_("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link());
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get());
      assert::are_equal_(inner_exception.what(), e.inner_exception().value().get().what());
      assert::are_equal_(info.get_file_line_number(), e.line_number());
      assert::are_equal_(info.get_method(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::are_equal_(info.to_string(), e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception : Test excpetion message.\n" + info.to_string(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(creator_with_message_inner_exception_error_help_link_and_stack_frame) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      arithmetic_exception e("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal_(EBUSY, e.error_code().value());
      assert::are_equal_(std::generic_category(), e.error_code().category());
      assert::are_equal_(info.get_file_name(), e.file_path());
      assert::are_equal_("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link());
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get());
      assert::are_equal_(inner_exception.what(), e.inner_exception().value().get().what());
      assert::are_equal_(info.get_file_line_number(), e.line_number());
      assert::are_equal_(info.get_method(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::are_equal_(info.to_string(), e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception : Test excpetion message.\n" + info.to_string(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(copy_constructor) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      arithmetic_exception e = arithmetic_exception("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal_(EBUSY, e.error_code().value());
      assert::are_equal_(std::generic_category(), e.error_code().category());
      assert::are_equal_(info.get_file_name(), e.file_path());
      assert::are_equal_("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link());
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get());
      assert::are_equal_(inner_exception.what(), e.inner_exception().value().get().what());
      assert::are_equal_(info.get_file_line_number(), e.line_number());
      assert::are_equal_(info.get_method(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::are_equal_(info.to_string(), e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception : Test excpetion message.\n" + info.to_string(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(copy_operator) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      arithmetic_exception e;
      e = arithmetic_exception("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal_(EBUSY, e.error_code().value());
      assert::are_equal_(std::generic_category(), e.error_code().category());
      assert::are_equal_(info.get_file_name(), e.file_path());
      assert::are_equal_("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link());
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get());
      assert::are_equal_(inner_exception.what(), e.inner_exception().value().get().what());
      assert::are_equal_(info.get_file_line_number(), e.line_number());
      assert::are_equal_(info.get_method(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::are_equal_(info.to_string(), e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception : Test excpetion message.\n" + info.to_string(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
  };
}
