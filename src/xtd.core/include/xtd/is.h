/// @file
/// @brief Contains xtd::is method.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <any>
#include <limits>
#include <memory>
#include <stdexcept>
#include "parse.h"
#include "types.h"
#include "unused.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  template<typename value_t>
  inline bool is(bool value) {return false;}
  template<typename value_t>
  inline bool is(decimal_t value) {return false;}
  template<typename value_t>
  inline bool is(double value) {return false;}
  template<typename value_t>
  inline bool is(float value) {return false;}
  template<typename value_t>
  inline bool is(sbyte value) {return false;}
  template<typename value_t>
  inline bool is(int16 value) {return false;}
  template<typename value_t>
  inline bool is(int32 value) {return false;}
  template<typename value_t>
  inline bool is(int64 value) {return false;}
  template<typename value_t>
  inline bool is(llong_t value) {return false;}
  template<typename value_t>
  inline bool is(xtd::byte value) {return false;}
  template<typename value_t>
  inline bool is(uint16_t value) {return false;}
  template<typename value_t>
  inline bool is(uint32 value) {return false;}
  template<typename value_t>
  inline bool is(uint64 value) {return false;}
  template<typename value_t>
  inline bool is(ullong_t value) {return false;}
  /// @endcond
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int main() {
  ///   bool b = false;
  ///   std::cout << "b " << is<bool>(b) ? "is" : "isn't" << " bool" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<bool>(bool value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int main() {
  ///   decimal_t d = 4.2;
  ///   std::cout << "d " << is<decimal_t>(d) ? "is" : "isn't" << " decimal_t" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<decimal_t>(decimal_t value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int main() {
  ///   double d = 4.2;
  ///   std::cout << "d " << is<double>(d) ? "is" : "isn't" << " double" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<double>(double value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int main() {
  ///   float f = 4.2;
  ///   std::cout << "f " << is<float>(f) ? "is" : "isn't" << " float" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<float>(float value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int main() {
  ///   sbyte i = 42;
  ///   std::cout << "i " << is<sbyte>(i) ? "is" : "isn't" << " sbyte" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<sbyte>(sbyte value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int main() {
  ///   int16 i = 42;
  ///   std::cout << "i " << is<int16>(i) ? "is" : "isn't" << " int16" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<int16>(int16 value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int main() {
  ///   int32 i = 42;
  ///   std::cout << "i " << is<int32>(i) ? "is" : "isn't" << " int32" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<int32>(int32 value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int main() {
  ///   int64 i = 42;
  ///   std::cout << "i " << is<int64>(i) ? "is" : "isn't" << " int64" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<int64>(int64 value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int main() {
  ///   llong_t i = 42;
  ///   std::cout << "i " << is<llong_t>(i) ? "is" : "isn't" << " llong_t" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<llong_t>(llong_t value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int main() {
  ///   xtd::byte u = 42;
  ///   std::cout << "u " << is<xtd::byte>(u) ? "is" : "isn't" << " xtd::byte" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<xtd::byte>(xtd::byte value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int main() {
  ///   uint16_t u = 42;
  ///   std::cout << "u " << is<uint16_t>(u) ? "is" : "isn't" << " uint16_t" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<uint16_t>(uint16_t value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int main() {
  ///   uint32 u = 42;
  ///   std::cout << "u " << is<uint32>(u) ? "is" : "isn't" << " uint32" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<uint32>(uint32 value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int main() {
  ///   uint64 u = 42;
  ///   std::cout << "u " << is<uint64>(u) ? "is" : "isn't" << " uint64" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<uint64>(uint64 value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int main() {
  ///   ullong_t u = 42;
  ///   std::cout << "u " << is<ullong_t>(i) ? "is" : "isn't" << " ullong_t" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<ullong_t>(ullong_t value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename type_t>
  bool is(std::any value) {
    try {
      any_cast<type_t>(value);
      return true;
    } catch (const std::bad_cast&) {
      return false;
    }
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline bool is<std::any>(std::any value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename type_t, typename param_t>
  bool is(const param_t* value) {
    try {
      if (value == nullptr) return false;
      return dynamic_cast<const type_t*>(value) != nullptr;
    } catch (const std::bad_cast&) {
      return false;
    }
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename type_t, typename param_t>
  bool is(const param_t& value) {
    return is<type_t>(&value);
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename type_t, typename param_t>
  bool is(param_t* value) {
    try {
      if (value == nullptr) return false;
      return dynamic_cast<type_t*>(value) != nullptr;
    } catch (const std::bad_cast&) {
      return false;
    }
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename type_t, typename param_t>
  bool is(param_t& value) {
    return is<type_t>(&value);
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename new_type_t, typename current_type_t>
  bool is(std::shared_ptr<current_type_t>& value) {
    auto result = dynamic_pointer_cast<new_type_t>(value);
    if (result) return true;
    return false;
  }
}
