/// @file
/// @brief Contains xtd::drawing::solid_brush class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.h"
#include "brush.h"
#include "color.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Defines a xtd::drawing::brush of a single color. Brushes are used to fill graphics shapes, such as rectangles, ellipses, pies, polygons, and paths. This class cannot be inherited.
    /// @code
    /// class drawing_export_ solid_brush : public xtd::drawing::brush
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::drawing::brush → xtd::drawing::solid_brush
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    /// @image html solid_brush.png
    /// @par Examples
    /// The following code example demonstrates the use of solid_brush class.
    /// @include fill_rectangle.cpp
    /// @remarks This class inherits from the xtd::drawing::brush class.
    class drawing_export_ solid_brush final : public xtd::drawing::brush {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new xtd::drawing::solid_brush object of the specified color.
      /// @param color A xtd::drawing::color structure that represents the color of this brush.
      explicit solid_brush(const xtd::drawing::color& color) {this->color(color);}
      /// @}
      
      /// @cond
      solid_brush(const solid_brush& value);
      solid_brush& operator=(const solid_brush& value);
      bool operator==(const solid_brush& value) const {return data_->color_ == value.data_->color_;}
      bool operator!=(const solid_brush& value) const {return !operator==(value);}
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the color of this xtd::drawing::solid_brush object.
      /// @return A xtd::drawing::color structure that represents the color of this brush.
      const xtd::drawing::color& color() const noexcept {return data_->color_;}
      /// @brief Sets the color of this xtd::drawing::solid_brush object.
      /// @param value A xtd::drawing::color structure that represents the color of this brush.
      /// @return This current instance.
      xtd::drawing::solid_brush& color(const xtd::drawing::color& value);
      /// @}
      
    private:
      solid_brush();
      struct data {
        drawing::color color_;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
