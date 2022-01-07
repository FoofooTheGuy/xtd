#include "../../../include/xtd/drawing/rectangle_f.h"

using namespace xtd::drawing;

const rectangle_f rectangle_f::empty;

void rectangle_f::make_intersect(const rectangle_f& rect) {
  auto x1 = std::max(x_, rect.x_);
  auto x2 = std::min(x_ + width_, rect.x_ + rect.width_);
  auto y1 = std::max(y_, rect.y_);
  auto y2 = std::min(y_ + height_, rect.y_ + rect.height_);
  
  if (x2 < x1 || y2 < y1) x_ = y_ = width_ = height_ = 0;
  else {
    x_ = x1;
    y_ = y1;
    width_ = x2 - x1;
    height_ = y2 - y1;
  }
}

void rectangle_f::make_union(const rectangle_f& rect) {
  auto x1 = std::min(x_, rect.x_);
  auto x2 = std::max(x_ + width_, rect.x_ + rect.width_);
  auto y1 = std::min(y_, rect.y_);
  auto y2 = std::max(y_ + height_, rect.y_ + rect.height_);
  
  x_ = x1;
  y_ = y1;
  width_ = x2 - x1;
  height_ = y2 - y1;
}
