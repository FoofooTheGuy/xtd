/// @file
/// @brief Contains xtd::drawing::drawing2d::linear_gradient_mode enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::drawing2d namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing2d {
      /// @brief Specifies the direction of a linear gradient.
      /// @par Namespace
      /// xtd::drawing::drawing2d
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      enum class linear_gradient_mode {
        /// @brief Specifies a gradient from left to right.
        horizontal = 0,
        /// @brief Specifies a gradient from top to bottom.
        vertical = 1,
        /// @brief Specifies a gradient from upper left to lower right.
        forward_diagonal = 2,
        /// @brief Specifies a gradient from upper right to lower left.
        backward_diagonal = 3
      };
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::drawing::drawing2d::linear_gradient_mode> {
  void operator()(xtd::enum_collection<xtd::drawing::drawing2d::linear_gradient_mode>& values, xtd::enum_attribute& attribute) {values = {{xtd::drawing::drawing2d::linear_gradient_mode::horizontal, "horizontal"}, {xtd::drawing::drawing2d::linear_gradient_mode::vertical, "vertical"}, {xtd::drawing::drawing2d::linear_gradient_mode::forward_diagonal, "forward_diagonal"}, {xtd::drawing::drawing2d::linear_gradient_mode::backward_diagonal, "backward_diagonal"}};}
};
/// @endcond
