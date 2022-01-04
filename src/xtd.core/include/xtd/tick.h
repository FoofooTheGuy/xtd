/// @file
/// @brief Contains xtd::tick typedef.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once

#include <ratio>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a tick (1 tick = 100 nanoseconds).
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using tick = std::ratio<1LL, 10000000LL>;
}
