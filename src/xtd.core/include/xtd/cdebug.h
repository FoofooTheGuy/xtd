/// @file
/// @brief Contains xtd::cdebug ostream.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <iostream>
#include "debugstreambuf.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
  /// @brief A xtd::debugstreambuf variable used by xtd::cdebug ostream.
  inline xtd::debugstreambuf cdebugstreambuf;
  
  /// @brief Provides an std::ostream for xtd::diagnostics::debug.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  inline std::ostream cdebug(&cdebugstreambuf);
  #else
  /// @brief Provides an std::ostream for xtd::diagnostics::debug.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  inline std::ostream cdebug(nullptr);
  #endif
}
