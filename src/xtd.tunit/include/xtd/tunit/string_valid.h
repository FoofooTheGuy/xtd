/// @file
/// @brief Contains xtd::tunit::string_valid class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "valid.h"
#include "string_assert.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The string_valid class contains a collection of static methods that implement the most string assertions used in xtd::tUnit.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit validations
    /// @remarks Validations are the same as assertions with the difference, no exception is thrown, but an error is generated.
    /// @remarks If a validation fails, he test can be continued to the end or to an assertion is generated.
    /// @par Examples
    /// This example show how to used some methods :
    /// @include assert.cpp
    class tunit_export_ string_valid final : private base_assert {
    public:
      /// @cond
      string_valid() = delete;
      /// @endcond
      
      /// @name Methods
      
      /// @{
      /// @brief Validates that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_valid::are_equal_ignoring_case("value", xtd::ustring("VALUE")); // test ok.
      /// xtd::tunit::string_valid::are_equal_ignoring_case("key", xtd::ustring("VALUE")); // test fails.
      /// @endcode
      static void are_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual);
      /// @brief Validates that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_valid::are_equal_ignoring_case("value", xtd::ustring("VALUE"), csf_); // test ok.
      /// xtd::tunit::string_valid::are_equal_ignoring_case("key", xtd::ustring("VALUE"), csf_); // test fails.
      /// @endcode
      static void are_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Validates that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_valid::are_equal_ignoring_case("value", xtd::ustring("VALUE"), "User message..."); // test ok.
      /// xtd::tunit::string_valid::are_equal_ignoring_case("key", xtd::ustring("VALUE"), "User message..."); // test fails.
      /// @endcode
      static void are_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::ustring& message);
      /// @brief Validates that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_valid::are_equal_ignoring_case("value", xtd::ustring("VALUE"), "User message...", csf_); // test ok.
      /// xtd::tunit::string_valid::are_equal_ignoring_case("key", xtd::ustring("VALUE"), "User message...", csf_); // test fails.
      /// @endcode
      static void are_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      /// @brief Validates that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_valid::are_not_equal_ignoring_case("key", xtd::ustring("VALUE")); // test ok.
      /// xtd::tunit::string_valid::are_not_equal_ignoring_case("value", xtd::ustring("VALUE")); // test fails.
      /// @endcode
      static void are_not_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual);
      /// @brief Validates that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_valid::are_not_equal_ignoring_case("key", xtd::ustring("VALUE"), csf_); // test ok.
      /// xtd::tunit::string_valid::are_not_equal_ignoring_case("value", xtd::ustring("VALUE"), csf_); // test fails.
      /// @endcode
      static void are_not_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Validates that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_valid::are_not_equal_ignoring_case("key", xtd::ustring("VALUE"), "User message..."); // test ok.
      /// xtd::tunit::string_valid::are_not_equal_ignoring_case("value", xtd::ustring("VALUE"), "User message..."); // test fails.
      /// @endcode
      static void are_not_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::ustring& message);
      /// @brief Validates that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_valid::are_not_equal_ignoring_case("key", xtd::ustring("VALUE"), "User message...", csf_); // test ok.
      /// xtd::tunit::string_valid::are_not_equal_ignoring_case("value", xtd::ustring("VALUE"), "User message...", csf_); // test fails.
      /// @endcode
      static void are_not_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      /// @brief Validates that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_valid::contains("a", s); // test ok.
      /// xtd::tunit::string_valid::contains("z", s); // test fails.
      /// @endcode
      static void contains(const xtd::ustring& item, const xtd::ustring& string);
      /// @brief Validates that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_valid::contains("a", s, csf_); // test ok.
      /// xtd::tunit::string_valid::contains("z", s, csf_); // test fails.
      /// @endcode
      static void contains(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Validates that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_valid::contains("a", s, "User message..."); // test ok.
      /// xtd::tunit::string_valid::contains("z", s, "User message..."); // test fails.
      /// @endcode
      static void contains(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message);
      /// @brief Validates that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_valid::contains("a", s, "User message...", csf_); // test ok.
      /// xtd::tunit::string_valid::contains("z", s, "User message...", csf_); // test fails.
      /// @endcode
      static void contains(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      /// @brief Validates that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_valid::contains("a", s); // test ok.
      /// xtd::tunit::string_valid::contains("z", s); // test fails.
      /// @endcode
      static void does_not_contain(const xtd::ustring& item, const xtd::ustring& string);
      /// @brief Validates that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_valid::contains("a", s, csf_); // test ok.
      /// xtd::tunit::string_valid::contains("z", s, csf_); // test fails.
      /// @endcode
      static void does_not_contain(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Validates that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_valid::contains("a", s, "User message..."); // test ok.
      /// xtd::tunit::string_valid::contains("z", s, "User message..."); // test fails.
      /// @endcode
      static void does_not_contain(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message);
      /// @brief Validates that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_valid::contains("a", s, "User message...", csf_); // test ok.
      /// xtd::tunit::string_valid::contains("z", s, "User message...", csf_); // test fails.
      /// @endcode
      static void does_not_contain(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      /// @brief Validates that string does not end with a specific item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_valid::does_not_end_with("law", s); // test ok.
      /// xtd::tunit::string_valid::does_not_end_with("lue", s); // test fails.
      /// @endcode
      static void does_not_end_with(const xtd::ustring& item, const xtd::ustring& string);
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_valid::does_not_end_with("law", s, csf_); // test ok.
      /// xtd::tunit::string_valid::does_not_end_with("lue", s, csf_); // test fails.
      /// @endcode
      static void does_not_end_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_valid::does_not_end_with("law", s, "User message..."); // test ok.
      /// xtd::tunit::string_valid::does_not_end_with("lue", s, "User message..."); // test fails.
      /// @endcode
      static void does_not_end_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message);
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_valid::does_not_end_with("law", s, "User message...", csf_); // test ok.
      /// xtd::tunit::string_valid::does_not_end_with("lue", s, "User message...", csf_); // test fails.
      /// @endcode
      static void does_not_end_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      /// @brief Validates that does not match regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_valid::does_not_match("^Salut", xtd::ustring("Hello, World!")); // test ok.
      /// xtd::tunit::string_valid::does_not_match("^Hello", xtd::ustring("Hello, World!")); // test fails.
      /// @endcode
      static void does_not_match(const xtd::ustring& regex_pattern, const xtd::ustring& actual);
      /// @brief Validates that does not match regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_valid::does_not_match("^Salut", xtd::ustring("Hello, World!"), csf_); // test ok.
      /// xtd::tunit::string_valid::does_not_match("^Hello", xtd::ustring("Hello, World!"), csf_); // test fails.
      /// @endcode
      static void does_not_match(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Validates that does not match regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_valid::does_not_match("^Salut", xtd::ustring("Hello, World!"), "User message..."); // test ok.
      /// xtd::tunit::string_valid::does_not_match("^Hello", xtd::ustring("Hello, World!"), "User message..."); // test fails.
      /// @endcode
      static void does_not_match(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::ustring& message);
      /// @brief Validates that does not match regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_valid::does_not_match("^Salut", "Hello, World!", xtd::ustring("User message..."), csf_); // test ok.
      /// xtd::tunit::string_valid::does_not_match("^Hello", "Hello, World!", xtd::ustring("User message..."), csf_); // test fails.
      /// @endcode
      static void does_not_match(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      /// @brief Validates that string does not start with a specific item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_valid::does_not_start_with("zoe", s); // test ok.
      /// xtd::tunit::string_valid::does_not_start_with("val", s); // test fails.
      /// @endcode
      static void does_not_start_with(const xtd::ustring& item, const xtd::ustring& string);
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_valid::does_not_start_with("zoe", s, csf_); // test ok.
      /// xtd::tunit::string_valid::does_not_start_with("val", s, csf_); // test fails.
      /// @endcode
      static void does_not_start_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_valid::does_not_start_with("zoe", s, "User message..."); // test ok.
      /// xtd::tunit::string_valid::does_not_start_with("val", s, "User message..."); // test fails.
      /// @endcode
      static void does_not_start_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message);
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_valid::does_not_start_with("zoe", s, "User message...", csf_); // test ok.
      /// xtd::tunit::string_valid::does_not_start_with("val", s, "User message...", csf_); // test fails.
      /// @endcode
      static void does_not_start_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      /// @brief Validates that string ends with a specific item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_valid::ends_with("val", s); // test ok.
      /// xtd::tunit::string_valid::ends_with("law", s); // test fails.
      /// @endcode
      static void ends_with(const xtd::ustring& item, const xtd::ustring& string);
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_valid::ends_with("val", s, csf_); // test ok.
      /// xtd::tunit::string_valid::ends_with("law", s, csf_); // test fails.
      /// @endcode
      static void ends_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_valid::ends_with("val", s, "User message..."); // test ok.
      /// xtd::tunit::string_valid::ends_with("law", s, "User message..."); // test fails.
      /// @endcode
      static void ends_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message);
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_valid::ends_with("lue", s, "User message...", csf_); // test ok.
      /// xtd::tunit::string_valid::ends_with("law", s, "User message...", csf_); // test fails.
      /// @endcode
      static void ends_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      /// @brief Validates that matches regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_valid::matches("^Hello", xtd::ustring("Hello, World!")); // test ok.
      /// xtd::tunit::string_valid::matches("^Salut", xtd::ustring("Hello, World!")); // test fails.
      /// @endcode
      static void matches(const xtd::ustring& regex_pattern, const xtd::ustring& actual);
      /// @brief Validates that matches regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_valid::matches("^Hello", xtd::ustring("Hello, World!"), csf_); // test ok.
      /// xtd::tunit::string_valid::matches("^Salut", xtd::ustring("Hello, World!"), csf_); // test fails.
      /// @endcode
      static void matches(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Validates that matches regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_valid::matches("^Hello", xtd::ustring("Hello, World!"), "User message..."); // test ok.
      /// xtd::tunit::string_valid::matches("^Salut", xtd::ustring("Hello, World!"), "User message..."); // test fails.
      /// @endcode
      static void matches(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::ustring& message);
      /// @brief Validates that matches regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_valid::matches("^Hello", "Hello, World!", xtd::ustring("User message..."), csf_); // test ok.
      /// xtd::tunit::string_valid::matches("^Salut", "Hello, World!", xtd::ustring("User message..."), csf_); // test fails.
      /// @endcode
      static void matches(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame);

      /// @brief Validates that string starts with a specific item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_valid::starts_with("val", s); // test ok.
      /// xtd::tunit::string_valid::starts_with("zoe", s); // test fails.
      /// @endcode
      static void starts_with(const xtd::ustring& item, const xtd::ustring& string);
      
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_valid::starts_with("val", s, csf_); // test ok.
      /// xtd::tunit::string_valid::starts_with("zoe", s, csf_); // test fails.
      /// @endcode
      static void starts_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_valid::starts_with("val", s, "User message..."); // test ok.
      /// xtd::tunit::string_valid::starts_with("zoe", s, "User message..."); // test fails.
      /// @endcode
      static void starts_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message);
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_valid::starts_with("val", s, "User message...", csf_); // test ok.
      /// xtd::tunit::string_valid::starts_with("zoe", s, "User message...", csf_); // test fails.
      /// @endcode
      static void starts_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame);
      /// @}
    };
  }
}
