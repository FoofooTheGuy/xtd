#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <tuple>
#include <vector>
#include <xtd/static.h>
#include <xtd/drawing_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    namespace drawing2d {
      class hatch_brush;
      class conical_gradient_brush;
      class linear_gradient_brush;
      class radial_gradient_brush;
    }
    class brush;
    class solid_brush;
    class texture_brush;
    /// @endcond
    
    /// @brief The xtd::drawing::native namespace contains internal native API definitions to access underlying toolkits used by xtd.drawing library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains brush native API.
      /// @par Namespace
      /// xtd::drawing::native
      /// @par Library
      /// xtd.drawing.native
      /// @ingroup xtd_drawing_native native
      /// @warning Internal use only
      class drawing_native_export_ brush final static_ {
        friend xtd::drawing::drawing2d::hatch_brush;
        friend xtd::drawing::drawing2d::conical_gradient_brush;
        friend xtd::drawing::drawing2d::linear_gradient_brush;
        friend xtd::drawing::drawing2d::radial_gradient_brush;
        friend xtd::drawing::brush;
        friend xtd::drawing::solid_brush;
        friend xtd::drawing::texture_brush;
      protected:
        /// @name Protected methods
        
        /// @{
        /// @brief Creates brush.
        /// @return The created brush handle.
        /// @warning Internal use only
        static intptr_t create();
        
        /// @brief Destroys brush.
        /// @param brush The brush handle to destroy.
        /// @warning Internal use only
        static void destroy(intptr_t brush);
        
        /// @brief Sets solid color brush.
        /// @param brush The brush handle.
        /// @param a The alpha component of the color.
        /// @param r The red component of the color.
        /// @param g The green component of the color.
        /// @param b The blue component of the color.
        /// @warning Internal use only
        static void solid(intptr_t brush, uint8_t a, uint8_t r, uint8_t g, uint8_t b);
        
        /// @brief Sets conical gradient brush.
        /// @param brush The brush handle.
        /// @param center_x The x coordinate  of the center point.
        /// @param center_y The y coordinate  of the center point.
        /// @param colors The gradient stop colors. Contains color and  offset.
        /// @param angle The start angle of the conical gradient.
        /// @remarks An offset value of 0.0 specifies that the stop is positioned at the beginning of the gradient vector, while a value of 1.0 specifies that the stop is positioned at the end of the gradient vector.
        /// @remarks The angle rotates in the clockwise direction. An angle of O° represents an angle from the center to the left. The angle turns in the clockwise direction. An angle of 90° represents an angle from the center downwards. An angle of 180° represents an angle from the center to the right. And so on.
        /// @warning Internal use only
        static void conical_gradient(intptr_t brush, int32_t center_x, int32_t center_y, const std::vector<std::tuple<uint8_t, uint8_t, uint8_t, uint8_t, float>>& colors, float angle);
        
        /// @brief Sets linear gradient brush.
        /// @brief x1 Contains the left value of the bound rectangle of the linear brush.
        /// @brief y1 Contains the top value of the bound rectangle of the linear brush.
        /// @brief x2 Contains the right value of the bound rectangle of the linear brush.
        /// @brief y1 Contains the bottom value of the bound rectangle of the linear brush.
        /// @param angle The start angle of the linear gradient.
        /// @remarks An offset value of 0.0 specifies that the stop is positioned at the beginning of the gradient vector, while a value of 1.0 specifies that the stop is positioned at the end of the gradient vector.
        /// @remarks The angle rotates in the clockwise direction. An angle of O° represents an angle from the center to the left. The angle turns in the clockwise direction. An angle of 90° represents an angle from the center downwards. An angle of 180° represents an angle from the center to the right. And so on.
        /// @warning Internal use only
        static void linear_gradient(intptr_t brush, int32_t x1, int32_t y1, int32_t x2, int32_t y2, const std::vector<std::tuple<uint8_t, uint8_t, uint8_t, uint8_t, float>>& colors, float angle);
        
        /// @brief Sets radial gradient brush.
        /// @param brush The brush handle.
        /// @param center_x The x coordinate  of the center point.
        /// @param center_y The y coordinate  of the center point.
        /// @param focal_x The x coordinate  of the focal point.
        /// @param focal_y The y coordinate  of the focal point.
        /// @param colors The gradient stop colors. Contains color and  offset.
        /// @param radius The radius of the radial gradient.
        /// @remarks An offset value of 0.0 specifies that the stop is positioned at the beginning of the gradient vector, while a value of 1.0 specifies that the stop is positioned at the end of the gradient vector.
        /// @warning Internal use only
        static void radial_gradient(intptr_t brush, int32_t center_x, int32_t center_y, int32_t focal_x, int32_t focal_y, const std::vector<std::tuple<uint8_t, uint8_t, uint8_t, uint8_t, float>>& colors, float radius);
        
        /// @brief Sets texturebrush.
        /// @param brush The brush handle.
        /// @param texture The image handle that represents the texture of the brush.
        static void texture(intptr_t brush, intptr_t texture);
        /// @}
      };
    }
  }
}
