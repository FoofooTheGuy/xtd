#include <xtd/time_out_exception.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(time_out_exception_tests) {
    inline static bool stack_trace_enabled = false;
  public:
    void test_initialize_(test_initialize) {
      stack_trace_enabled = system_exception::enable_stack_trace();
      system_exception::enable_stack_trace(false);
    }
    
    void test_cleanup_(test_cleanup) {
      system_exception::enable_stack_trace(stack_trace_enabled);
    }
    
    void test_method_(default_creator) {
      time_out_exception e;
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::is_empty(e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::are_equal(0U, e.line_number(), csf_);
      assert::is_empty(e.member_name(), csf_);
      assert::are_equal("The operation has timed out.", e.message(), csf_);
      assert::are_equal("xtd::time_out_exception", e.name(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::are_equal("xtd::time_out_exception : The operation has timed out.", e.to_string(), csf_);
      assert::are_equal("The operation has timed out.", e.what(), csf_);
    }
    
    void test_method_(default_creator_with_current_stack_frame) {
      auto info = current_stack_frame_;
      time_out_exception e(info);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("The operation has timed out.", e.message(), csf_);
      assert::are_equal("xtd::time_out_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::time_out_exception : The operation has timed out.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("The operation has timed out.", e.what(), csf_);
    }
    
    void test_method_(creator_with_empty_message) {
      time_out_exception e("");
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::is_empty(e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(0U, e.line_number(), csf_);
      assert::is_empty(e.member_name(), csf_);
      assert::are_equal("", e.message(), csf_);
      assert::are_equal("xtd::time_out_exception", e.name(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::are_equal("xtd::time_out_exception", e.to_string(), csf_);
      assert::are_equal("xtd::time_out_exception", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_empty_and_stack_frame) {
      auto info = current_stack_frame_;
      time_out_exception e("", info);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("", e.message(), csf_);
      assert::are_equal("xtd::time_out_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::time_out_exception\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("xtd::time_out_exception", e.what(), csf_);
    }
    
    void test_method_(creator_with_message) {
      time_out_exception e("Test excpetion message.");
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::is_empty(e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(0U, e.line_number(), csf_);
      assert::is_empty(e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::time_out_exception", e.name(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::are_equal("xtd::time_out_exception : Test excpetion message.", e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_and_stack_frame) {
      auto info = current_stack_frame_;
      time_out_exception e("Test excpetion message.", info);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::time_out_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::time_out_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_error_and_stack_frame) {
      auto info = current_stack_frame_;
      time_out_exception e("Test excpetion message.", std::error_code(EBUSY, std::generic_category()), info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::time_out_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::time_out_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_help_link_and_stack_frame) {
      auto info = current_stack_frame_;
      time_out_exception e("Test excpetion message.", "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::time_out_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::time_out_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_error_help_link_and_stack_frame) {
      auto info = current_stack_frame_;
      time_out_exception e("Test excpetion message.", std::error_code(EBUSY, std::generic_category()), "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::time_out_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::time_out_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_and_inner_exception) {
      system_exception inner_exception;
      time_out_exception e("Test excpetion message.", inner_exception);
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::is_empty(e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(0U, e.line_number(), csf_);
      assert::is_empty(e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::time_out_exception", e.name(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::are_equal("xtd::time_out_exception : Test excpetion message.", e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_inner_exception_and_stack_frame) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      time_out_exception e("Test excpetion message.", inner_exception, info);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::time_out_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::time_out_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_inner_exception_error_and_stack_frame) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      time_out_exception e("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::time_out_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::time_out_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_inner_exception_help_link_and_stack_frame) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      time_out_exception e("Test excpetion message.", inner_exception, "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::time_out_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::time_out_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_inner_exception_error_help_link_and_stack_frame) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      time_out_exception e("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::time_out_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::time_out_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(copy_constructor) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      time_out_exception e = time_out_exception("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::time_out_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::time_out_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(copy_operator) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      time_out_exception e;
      e = time_out_exception("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::time_out_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::time_out_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
  };
}
