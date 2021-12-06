/// @file
/// @brief Contains xtd::drawing::rectangle_f class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <ostream>
#include <string>
#include <xtd/object.h>
#include <xtd/ustring.h>
#include "../drawing_export.h"
#include "point_f.h"
#include "size_f.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class rectangle;
    /// @endcond

    /// @brief Stores a set of four floating-points that represent the location and size of a rectangle.
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    class drawing_export_ rectangle_f : public object {
    public:
      /// @name Fields
      
      /// @{
      static const rectangle_f empty;
      /// @}
      
      /// @name Constructors
      
      /// @{
      rectangle_f() = default;
      rectangle_f(float x, float y, float width, float height) : x_(x), y_(y), width_(width), height_(height) {}
      rectangle_f(const point_f& location, const size_f& size) : rectangle_f(location.x(), location.y(), size.width(), size.height()) {}
      /// @}

      /// @cond
      rectangle_f(const rectangle_f&) = default;
      rectangle_f& operator=(const rectangle_f&) = default;
      bool operator==(const rectangle_f& value) const {return x_ == value.x_ && y_ == value.y_ && width_ == value.width_ && height_ == value.height_;}
      bool operator!=(const rectangle_f& value) const {return !operator==(value);}
      /// @endcond
      
      /// @name Properties
      
      /// @{
      float bottom() const {return y_ + height_;}
      
      float height() const {return height_;}
      void height(float height) {height_ = height;}
      
      bool is_empty() const {return *this == rectangle_f::empty;}

      float left() const {return x_;}
      void left(float left) {x_ = left;}

      point_f location() const {return {x_, y_};}
      void location(const point_f& location) {
        x_ = location.x();
        y_ = location.y();
      }
      
      float right() const {return x_ + width_;}

      size_f size() const {return {width_, height_};}
      void size(const size_f& size) {
        width_ = size.width();
        height_ = size.height();
      }

      float top() const {return y_;}
      void top(float top) {y_ = top;}

      float x() const {return x_;}
      void x(float x) {x_ = x;}
      
      float y() const {return y_;}
      void y(float y) {y_ = y;}
      
      float width() const {return width_;}
      void width(float width) {width_ = width;}
      /// @}

      /// @name Methods
      
      /// @{
      bool contains(float x, float y) const {return x_ <= x && x < x_ + width_ && y_ <= y && y < y_ + height_;}
      bool contains(const point_f& pt) const {return contains(pt.x(), pt.y());}
      bool contains(const rectangle_f& rect) const {return x_ <= rect.x_ && (rect.x_ + rect.width_) <= (x_ + width_) && y_ <= rect.y_ &&  (rect.y_ + rect.height_) <= (y_ + height_);}

      static rectangle_f from_ltrb(float left, float top, float right, float bottom) {return rectangle_f(left, top, right - left, bottom - top);}
      
      void inflate(const drawing::size_f& sz) {inflate(sz.width(), sz.height());}
      void inflate(float width, float height) {
        width_ += width;
        height_ += height;
      }
      static rectangle_f inflate(const rectangle_f& rect, const drawing::size_f& sz) {return inflate(rect, sz.width(), sz.height());}
      static rectangle_f inflate(const rectangle_f& rect, float width, float height) {
        auto result = rect;
        result.inflate(width, height);
        return result;
      }

      bool intersects_with(const rectangle_f& rect) const {return (rect.x_ < x_ + width_) && (x_ < (rect.x_ + rect.width_)) && (rect.y_ < y_ + height_) && (y_ < rect.y_ + rect.height_);}

      static rectangle_f make_intersect(const rectangle_f& a, const rectangle_f& b) {
        auto result = a;
        result.make_intersect(b);
        return result;
      }
      void make_intersect(const rectangle_f& rect);
      
      static rectangle_f make_union(const rectangle_f& a, const rectangle_f& b) {
        auto result = a;
        result.make_union(b);
        return result;
      }
      void make_union(const rectangle_f& rect);

      void offset(const point_f& pt) {offset(pt.x(), pt.y());}
      void offset(float dx, float dy) {
        x_ += dx;
        y_ += dy;
      }
      static rectangle_f offset(const rectangle_f& rect, const point_f& pt) {return offset(rect, pt.x(), pt.y());}
      static rectangle_f offset(const rectangle_f& rect, float x, float y) {
        auto result = rect;
        result.offset(x, y);
        return result;
      }
      
      xtd::ustring to_string() const noexcept override {return "{x=" + std::to_string(x_) + ", y=" + std::to_string(y_) + ", width=" + std::to_string(width_) + ", height=" + std::to_string(height_) + "}";}
      /// @}
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::rectangle_f& rectangle) noexcept {return os << rectangle.to_string();}
      /// @endcond
      
    private:
      float x_ = 0;
      float y_ = 0;
      float width_ = 0;
      float height_ = 0;
    };
  }
}
