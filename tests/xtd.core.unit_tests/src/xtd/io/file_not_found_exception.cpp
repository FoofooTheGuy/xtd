#include <xtd/io/file_not_found_exception.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::io;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_file_not_found_exception) {
  public:
    void test_method_(default_creator) {
      file_not_found_exception e;
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::is_empty(e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::are_equal(0U, e.line_number(), csf_);
      assert::is_empty(e.member_name(), csf_);
      assert::are_equal("Unable to find the specified file.", e.message(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception", e.name(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Unable to find the specified file.", e.to_string(), csf_);
      assert::are_equal("Unable to find the specified file.", e.what(), csf_);
    }
    
    void test_method_(default_creator_with_current_stack_frame) {
      auto info = current_stack_frame_;
      file_not_found_exception e(info);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Unable to find the specified file.", e.message(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Unable to find the specified file.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Unable to find the specified file.", e.what(), csf_);
    }
    
    void test_method_(creator_with_empty_message) {
      file_not_found_exception e("");
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::is_empty(e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(0U, e.line_number(), csf_);
      assert::is_empty(e.member_name(), csf_);
      assert::are_equal("", e.message(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception", e.name(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception", e.to_string(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_empty_and_stack_frame) {
      auto info = current_stack_frame_;
      file_not_found_exception e("", info);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("", e.message(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception", e.what(), csf_);
    }
    
    void test_method_(creator_with_message) {
      file_not_found_exception e("Test excpetion message.");
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::is_empty(e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(0U, e.line_number(), csf_);
      assert::is_empty(e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception", e.name(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Test excpetion message.", e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_and_stack_frame) {
      auto info = current_stack_frame_;
      file_not_found_exception e("Test excpetion message.", info);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_error_and_stack_frame) {
      auto info = current_stack_frame_;
      file_not_found_exception e("Test excpetion message.", std::error_code(EBUSY, std::generic_category()), info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_help_link_and_stack_frame) {
      auto info = current_stack_frame_;
      file_not_found_exception e("Test excpetion message.", "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_error_help_link_and_stack_frame) {
      auto info = current_stack_frame_;
      file_not_found_exception e("Test excpetion message.", std::error_code(EBUSY, std::generic_category()), "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_and_inner_exception) {
      system_exception inner_exception;
      file_not_found_exception e("Test excpetion message.", inner_exception);
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::is_empty(e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(0U, e.line_number(), csf_);
      assert::is_empty(e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception", e.name(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Test excpetion message.", e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_inner_exception_and_stack_frame) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      file_not_found_exception e("Test excpetion message.", inner_exception, info);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_inner_exception_error_and_stack_frame) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      file_not_found_exception e("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_inner_exception_help_link_and_stack_frame) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      file_not_found_exception e("Test excpetion message.", inner_exception, "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal(0, e.error_code().value(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_inner_exception_error_help_link_and_stack_frame) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      file_not_found_exception e("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(copy_constructor) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      file_not_found_exception e = file_not_found_exception("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(copy_operator) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      file_not_found_exception e;
      e = file_not_found_exception("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
  };
}
