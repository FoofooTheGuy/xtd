/// @file
/// @brief Contains xtd::drawing::drawing2d::line_cap enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::drawing2d namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing2d {
      /// @brief Specifies the available cap styles with which a xtd::drawing::pen object can end a line.
      /// @par Namespace
      /// xtd::drawing::drawing2d
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      enum class line_cap {
        /// @brief Specifies a flat line cap.
        flat = 0,
        /// @brief Specifies a square line cap.
        square = 1,
        /// @brief Specifies a round line cap.
        round = 2,
      };
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::drawing::drawing2d::line_cap> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::drawing::drawing2d::line_cap> {{xtd::drawing::drawing2d::line_cap::flat, "flat"}, {xtd::drawing::drawing2d::line_cap::square, "square"}, {xtd::drawing::drawing2d::line_cap::round, "round"}};}
};
/// @endcond
