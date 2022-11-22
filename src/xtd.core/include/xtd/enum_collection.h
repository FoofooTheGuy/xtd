/// @file
/// @brief Contains xtd::enum_collection.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a pair of an enum_t value and a string of an enum of type enum_t.
  /// @remarks For more information about enumeration, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/enum_class.md">enum class</a> guide.
  template<typename enum_t>
  using enum_collection = std::vector<std::pair<enum_t, xtd::ustring>>;
}
