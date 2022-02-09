#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <wx/brush.h>
#include <wx/image.h>
#include <wx/graphics.h>

namespace xtd {
  namespace drawing {
    namespace native {
      class wx_brush {
      public:
        enum class brush_type {
          none,
          solid,
          linear_gradient,
          radial_gradient,
          texture
        };
        
        struct solid_brush {
          wxColour color;
        };
        struct linear_gradiant_brush {
          wxPoint point1;
          wxPoint point2;
          wxGraphicsGradientStops colors;
          //const wxGraphicsMatrix* graphics_matrix;
        };
        struct radial_gradiant_brush {
          wxPoint point1;
          wxPoint point2;
          float radius;
          wxGraphicsGradientStops colors;
          //const wxGraphicsMatrix* graphics_matrix;
        };
        struct texture_brush {
          wxImage texture;
        };
        
        wx_brush() = default;
        
        void create_solid_brush(const wxColour& color) {
          brush_type_ = brush_type::solid;
          solid_brush_.color = color;
        }
        
        void create_linear_gradiant_brush(const wxPoint& point1, const wxPoint& point2, const wxGraphicsGradientStops& colors) {
          brush_type_ = brush_type::linear_gradient;
          linear_gradiant_brush_.point1 = point1;
          linear_gradiant_brush_.point2 = point2;
          linear_gradiant_brush_.colors = colors;
        }
        
        void create_radial_gradiant_brush(const wxPoint& point1, const wxPoint& point2, const wxGraphicsGradientStops& colors, float radius) {
          brush_type_ = brush_type::radial_gradient;
          radial_gradiant_brush_.point1 = point1;
          radial_gradiant_brush_.point2 = point2;
          radial_gradiant_brush_.radius = radius;
          radial_gradiant_brush_.colors = colors;
        }
        
        void create_texture_brush(const wxImage& texture) {
          brush_type_ = brush_type::texture;
          texture_brush_.texture = texture;
        }
        
        bool is_solid_brush() const {return brush_type_ == brush_type::solid;}
        bool is_linear_gradiant_brush() const {return brush_type_ == brush_type::linear_gradient;}
        bool is_radial_gradiant_brush() const {return brush_type_ == brush_type::radial_gradient;}
        bool is_texture_brush() const {return brush_type_ == brush_type::texture;}
        
        const solid_brush& get_solid_brush() const {return solid_brush_;}
        solid_brush& get_solid_brush() {return solid_brush_;}
        
        const linear_gradiant_brush& get_linear_gradiant_brush() const {return linear_gradiant_brush_;}
        linear_gradiant_brush& get_linear_gradiant_brush() {return linear_gradiant_brush_;}
        
        const radial_gradiant_brush& get_radial_gradiant_brush() const {return radial_gradiant_brush_;}
        radial_gradiant_brush& get_radial_gradiant_brush() {return radial_gradiant_brush_;}
        
        const texture_brush& get_texture_brush() const {return texture_brush_;}
        texture_brush& get_texture_brush() {return texture_brush_;}
        
      private:
        brush_type brush_type_ = brush_type::none;
        solid_brush solid_brush_;
        linear_gradiant_brush linear_gradiant_brush_;
        radial_gradiant_brush radial_gradiant_brush_;
        texture_brush texture_brush_;
      };
    }
  }
}

