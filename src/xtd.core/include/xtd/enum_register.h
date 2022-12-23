/// @file
/// @brief Contains xtd::enum_register.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once

#include "enum_collection.h"
#include "types.h"

#define __XTD_CORE_INTERNAL__
#include "internal/__enum_introspection.h"
#include "internal/__enum_definition_to_enum_collection.h"
#undef __XTD_CORE_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides the registration struct for enumerations.
  /// @code
  /// template<typename enum_t>
  /// struct enum_register
  /// @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks The overloading of this operator is necessary for enum classes to be recognized by xtd::ustring::format().
  /// @remarks For more information about enumeration, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/enum_class.md">enum class</a> guide.
  /// @remarks When an enumeration is registered, we can display its name instead of its value, we can format it and parse it.
  /// @remarks See <a href="https://github.com/gammasoft71/xtd/blob/master/docs/format_enumeration_format_strings.md">Enumeration Format Strings</a>. For more information about formatting in general, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/format_overview.md">Formatting Types</a>.
  /// @par Examples
  /// The following code show how to use xtd::enum_register operator for an enum.
  /// @include enum_class_without_helper.cpp
  /// The following code show how to use xtd::enum_register operator for an enum flags.
  /// @include enum_class_flags_without_helpers.cpp
  template<typename enum_t>
  struct enum_register {
    /// Allows to register an enumeration that can be used by xtd::enum_object.
    /// @return An xtd::enum_collection collection that represent enumeration.
    /// @remarks To register an enumeration just override xtd::enum_register.
    /// @par Examples
    /// The following code show how to register the values enum class.
    /// @code
    /// enum class values {
    ///   value_one,
    ///   value_two
    /// };
    ///
    /// template<>
    /// xtd::enum_register<values> {
    ///   explicit operator auto() const noexcept {return xtd::enum_collection<values> {{values::value_one, "value_one"}, {values::value_two, "value_two"}};}
    /// };
    /// @endcode
    explicit operator auto() const noexcept {return xtd::enum_collection<enum_t> {};}
  };
}

/// @brief Provides the registration struct for enum with specified underlying type.
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core system keywords
/// @param namespace_name The name of the the namespace. Empty if no namespace.
/// @param enum_type The name of the enum.
/// @param underlying_type The underying type.
/// @param ... The nemumeration lists.
/// @remaks This helper is created to facilitate to set the xtd::enum_register with the enumeration identifiers.
/// @warning The helper has one limitiation :
///  * The enumeration's cannot be in a class or struct. The enum must be in the global namespace or in a namespace hierarchy. If the enumeration is in a class or struct, add operators manually and use xtd::enum_register to register the enumeration identifiers.
/// @par Examples
/// The following code show how to use #enum_ut_ helper.
/// @include enum_ut.cpp
#define enum_ut_(namespace_name, enum_t, underlying_t, ...) \
  namespace namespace_name {enum enum_t : underlying_t {__VA_ARGS__};} \
  __enum_introspection__(namespace_name, enum_t, underlying_t, __VA_ARGS__) \
  template<> struct xtd::enum_register<namespace_name::enum_t> {explicit operator auto() const {return __enum_definition_to_enum_collection__<namespace_name::enum_t>(#__VA_ARGS__);}}

/// @brief Provides the registration struct for enum class with specified underlying type.
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core system keywords
/// @param namespace_name The name of the the namespace. Empty if no namespace.
/// @param enum_class_type The name of the enum class.
/// @param underlying_type The underying type.
/// @param ... The nemumeration lists.
/// @remaks This helper is created to facilitate to set the xtd::enum_register with the enumeration identifiers.
/// @warning The helper has one limitiation :
///  * The enumeration's cannot be in a class or struct. The enum must be in the global namespace or in a namespace hierarchy. If the enumeration is in a class or struct, add operators manually and use xtd::enum_register to register the enumeration identifiers.
/// @par Examples
/// The following code show how to use #enum_class_ut_ helper.
/// @include enum_class_ut.cpp
#define enum_class_ut_(namespace_name, enum_class_t, underlying_t, ...) \
  namespace namespace_name {enum class enum_class_t : underlying_t { __VA_ARGS__ };} \
  __enum_introspection__(namespace_name, enum_class_t, underlying_t, __VA_ARGS__) \
  template<> struct xtd::enum_register<namespace_name::enum_class_t> {explicit operator auto() const {return __enum_definition_to_enum_collection__<namespace_name::enum_class_t>(#__VA_ARGS__);}}

/// @brief Provides the registration struct for enum with specified underlying type.
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core system keywords
/// @param namespace_name The name of the the namespace. Empty if no namespace.
/// @param enum_struct_type The name of the enum struct.
/// @param underlying_type The underying type.
/// @param ... The nemumeration lists.
/// @remaks This helper is created to facilitate to set the xtd::enum_register with the enumeration identifiers.
/// @warning The helper has one limitiation :
///  * The enumeration's cannot be in a class or struct. The enum must be in the global namespace or in a namespace hierarchy. If the enumeration is in a class or struct, add operators manually and use xtd::enum_register to register the enumeration identifiers.
/// @par Examples
/// The following code show how to use #enum_struct_ut_ helper.
/// @include enum_struct_ut.cpp
#define enum_struct_ut_(namespace_name, enum_struct_t, underlying_t, ...) \
  namespace namespace_name {enum struct enum_struct_t : underlying_t { __VA_ARGS__ };} \
  __enum_introspection__(namespace_name, enum_struct_t, underlying_t, __VA_ARGS__) \
  template<> struct xtd::enum_register<namespace_name::enum_struct_t> {explicit operator auto() const {return __enum_definition_to_enum_collection__<namespace_name::enum_struct_t>(#__VA_ARGS__);}}

/// @brief Provides the registration struct for enum.
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core system keywords
/// @param namespace_name The name of the the namespace. Empty if no namespace.
/// @param enum_type The name of the enum.
/// @param ... The nemumeration lists.
/// @remaks This helper is created to facilitate to set the xtd::enum_register with the enumeration identifiers.
/// @warning The helper has one limitiation :
///  * The enumeration's cannot be in a class or struct. The enum must be in the global namespace or in a namespace hierarchy. If the enumeration is in a class or struct, add operators manually and use xtd::enum_register to register the enumeration identifiers.
/// @par Examples
/// The following code show how to use #enum_ helper.
/// @include enum.cpp
#define enum_(namespace_name, enum_t, ...) \
  enum_ut_(namespace_name, enum_t, xtd::int32, __VA_ARGS__)

/// @brief Provides the registration struct for enum class.
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core system keywords
/// @param namespace_name The name of the the namespace. Empty if no namespace.
/// @param enum_class_type The name of the enum class.
/// @param ... The nemumeration lists.
/// @remaks This helper is created to facilitate to set the xtd::enum_register with the enumeration identifiers.
/// @warning The helper has one limitiation :
///  * The enumeration's cannot be in a class or struct. The enum must be in the global namespace or in a namespace hierarchy. If the enumeration is in a class or struct, add operators manually and use xtd::enum_register to register the enumeration identifiers.
/// @par Examples
/// The following code show how to use #enum_ helper.
/// @include enum_class.cpp
#define enum_class_(namespace_name, enum_class_t, ...) \
  enum_class_ut_(namespace_name, enum_class_t, xtd::int32, __VA_ARGS__)

/// @brief Provides the registration struct for enum struct.
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core system keywords
/// @param namespace_name The name of the the namespace. Empty if no namespace.
/// @param enum_struct_type The name of the enum struct.
/// @param ... The nemumeration lists.
/// @remaks This helper is created to facilitate to set the xtd::enum_register with the enumeration identifiers.
/// @warning The helper has one limitiation :
///  * The enumeration's cannot be in a class or struct. The enum must be in the global namespace or in a namespace hierarchy. If the enumeration is in a class or struct, add operators manually and use xtd::enum_register to register the enumeration identifiers.
/// @par Examples
/// The following code show how to use #enum_ helper.
/// @include enum_struct.cpp
#define enum_struct_(namespace_name, enum_struct_t, ...) \
  enum_struct_ut_(namespace_name, enum_struct_t, xtd::int32, __VA_ARGS__)
