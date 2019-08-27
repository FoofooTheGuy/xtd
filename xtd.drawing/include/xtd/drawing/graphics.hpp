#pragma once
#include <cstdint>
#include <ostream>
#include <xtd/xtd.strings>
#include "brush.hpp"
#include "color.hpp"
#include "font.hpp"
#include "pen.hpp"
#include "point.hpp"
#include "point_f.hpp"
#include "rectangle.hpp"
#include "rectangle_f.hpp"
#include "size.hpp"
#include "size_f.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace forms {
    class control;
    class screen;
  }
  /// @endcond
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Defines an object used to draw lines and curves. This class cannot be inherited.
    class graphics {
    public:
      /// @cond
      ~graphics();
      graphics(const graphics&) = default;
      graphics& operator=(const graphics&) = default;
      /// @endcond
      
      void clear(const color& color);
      
      void draw_arc(const pen& pen, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle);
      
      void draw_arc(const pen& pen, float x, float y, float width, float height, float start_angle, float sweep_angle) {draw_arc(pen, static_cast<int32_t>(x), static_cast<int32_t>(y), static_cast<int32_t>(width), static_cast<int32_t>(height), static_cast<int32_t>(start_angle), static_cast<int32_t>(sweep_angle));}

      void draw_arc(const pen& pen, const rectangle& rect, float start_angle, float sweep_angle) {draw_arc(pen, rect.x(), rect.y(), rect.width(), rect.height(), static_cast<int32_t>(start_angle), static_cast<int32_t>(sweep_angle));}
      
      void draw_arc(const pen& pen, const rectangle_f& rect, float start_angle, float sweep_angle) {draw_arc(pen, rect.x(), rect.y(), rect.width(), rect.height(), start_angle, sweep_angle);}

      void draw_bezier(const pen& pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, int32_t x4, int32_t y4);

      void draw_ellipse(const pen& pen, int32_t x, int32_t y, int32_t width, int32_t height);
      
      void draw_ellipse(const pen& pen, float x, float y, float width, float height) {draw_ellipse(pen, static_cast<int32_t>(x), static_cast<int32_t>(y), static_cast<int32_t>(width), static_cast<int32_t>(height));}
      
      void draw_ellipse(const pen& pen, const rectangle& rect) {draw_ellipse(pen, rect.x(), rect.y(), rect.width(), rect.height());}
      
      void draw_ellipse(const pen& pen, const rectangle_f& rect) {draw_ellipse(pen, rect.x(), rect.y(), rect.width(), rect.height());}

      void draw_line(const pen& pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2);
      
      void draw_line(const pen& pen, float x1, float y1, float x2, float y2) {draw_line(pen, static_cast<int32_t>(x1), static_cast<int32_t>(y1), static_cast<int32_t>(x2), static_cast<int32_t>(y2));}
      
      void draw_line(const pen& pen, const point& p1, const point& p2) {draw_line(pen, p1.x(), p1.y(), p2.x(), p2.y());}
      
      void draw_line(const pen& pen, const point_f& p1, const point_f& p2) {draw_line(pen, p1.x(), p1.y(), p2.x(), p2.y());}
      
      void draw_rectangle(const pen& pen, int32_t x, int32_t y, int32_t width, int32_t height);
      
      void draw_rectangle(const pen& pen, float x, float y, float width, float height) {draw_rectangle(pen, static_cast<int32_t>(x), static_cast<int32_t>(y), static_cast<int32_t>(width), static_cast<int32_t>(height));}
      
      void draw_rectangle(const pen& pen, const rectangle& rect) {draw_rectangle(pen, rect.x(), rect.y(), rect.width(), rect.height());}
      
      void draw_rectangle(const pen& pen, const rectangle_f& rect) {draw_rectangle(pen, rect.x(), rect.y(), rect.width(), rect.height());}
      
      void fill_ellipse(const brush& brush, int32_t x, int32_t y, int32_t width, int32_t height);
      
      void fill_ellipse(const brush& brush, float x, float y, float width, float height) {fill_ellipse(brush, static_cast<int32_t>(x), static_cast<int32_t>(y), static_cast<int32_t>(width), static_cast<int32_t>(height));}
      
      void fill_ellipse(const brush& brush, const rectangle& rect) {fill_ellipse(brush, rect.x(), rect.y(), rect.width(), rect.height());}
      
      void fill_ellipse(const brush& brush, const rectangle_f& rect) {fill_ellipse(brush, rect.x(), rect.y(), rect.width(), rect.height());}
      
      void fill_pie(const brush& brush, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle);
      
      void fill_pie(const brush& brush, float x, float y, float width, float height, float start_angle, float sweep_angle) {fill_pie(brush, static_cast<int32_t>(x), static_cast<int32_t>(y), static_cast<int32_t>(width), static_cast<int32_t>(height), static_cast<int32_t>(start_angle), static_cast<int32_t>(sweep_angle));}
      
      void fill_pie(const brush& brush, const rectangle& rect, float start_angle, float sweep_angle) {fill_pie(brush, rect.x(), rect.y(), rect.width(), rect.height(), static_cast<int32_t>(start_angle), static_cast<int32_t>(sweep_angle));}
      
      void fill_pie(const brush& brush, const rectangle_f& rect, float start_angle, float sweep_angle) {fill_pie(brush, rect.x(), rect.y(), rect.width(), rect.height(), start_angle, sweep_angle);}

      void fill_rectangle(const brush& brush, int32_t x, int32_t y, int32_t width, int32_t height);
      
      void fill_rectangle(const brush& brush, float x, float y, float width, float height) {fill_rectangle(brush, static_cast<int32_t>(x), static_cast<int32_t>(y), static_cast<int32_t>(width), static_cast<int32_t>(height));}
      
      void fill_rectangle(const brush& brush, const rectangle& rect) {fill_rectangle(brush, rect.x(), rect.y(), rect.width(), rect.height());}
      
      void fill_rectangle(const brush& brush, const rectangle_f& rect) {fill_rectangle(brush, rect.x(), rect.y(), rect.width(), rect.height());}

      std::string to_string() const {return strings::full_class_name(*this);}
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::graphics& graphics) noexcept {
        return os << graphics.to_string();
      }
      /// @endcond
      
    private:
      friend drawing::font;
      friend forms::control;
      friend forms::screen;
      graphics(intptr_t handle) {this->data_->handle_ = handle;}

      struct data {
        intptr_t handle_ = 0;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
