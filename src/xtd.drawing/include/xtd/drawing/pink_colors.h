/// @file
/// @brief Contains xtd::drawing::pink_colors factory.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <vector>
#include <xtd/static.h>
#include "../drawing_export.h"
#include "color.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Pink colors for all the hmtl pink colors. This class cannot be inherited.
    /// @code
    /// class drawing_export_ pink_colors final static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::pink_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    class drawing_export_ pink_colors final static_ {
    public:
      /// @name Public properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html colors_deep_pink.png
      static xtd::drawing::color deep_pink();
      
      /// @brief A system-defined color object.
      /// @image html colors_hot_pink.png
      static xtd::drawing::color hot_pink();
      
      /// @brief A system-defined color object.
      /// @image html colors_light_pink.png
      static xtd::drawing::color light_pink();
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_violet_red.png
      static xtd::drawing::color medium_violet_red();
      
      /// @brief A system-defined color object.
      /// @image html colors_pale_violet_red.png
      static xtd::drawing::color pale_violet_red();
      
      /// @brief A system-defined color object.
      /// @image html colors_pink.png
      static xtd::drawing::color pink();
      /// @}

      /// @name Public methods
      
      /// @{
      /// @brief Gets an array of known colors.
      static std::vector<xtd::drawing::color> get_colors();
      /// @}
    };
  }
}
