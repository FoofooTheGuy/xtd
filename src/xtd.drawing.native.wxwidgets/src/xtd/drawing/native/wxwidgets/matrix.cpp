#include <map>
#include <vector>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/matrix.h>
#include <xtd/drawing/native/toolkit.h>
#include "../../../../../include/xtd/drawing/native/hdc_wrapper.h"
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <wx/graphics.h>
#include <xtd/as.h>
#include <xtd/math.h>

using namespace std;
using namespace xtd::drawing::native;

intptr_t matrix::create(float m11, float m12, float m21, float m22, float dx, float dy) {
  toolkit::initialize(); // Must be first
  wxMemoryDC mdc;
  wxGraphicsContext* mgc = wxGraphicsContext::Create(mdc);
  return reinterpret_cast<intptr_t>(new wxGraphicsMatrix(mgc->CreateMatrix(m11, m12, m22, dx, dy)));
}

void matrix::destroy(intptr_t handle) {
  delete reinterpret_cast<wxGraphicsMatrix*>(handle);
}

std::vector<float> matrix::elenents(intptr_t handle) {
  double m11 = 1.0, m12 = 0.0, m21 = 0.0, m22 = 1.0, dx = 0.0, dy = 0.0;
  if (handle) reinterpret_cast<wxGraphicsMatrix*>(handle)->Get(&m11, &m12, &m21, &m22, &dx, &dy);
  return {as<float>(m11), as<float>(m12), as<float>(m21), as<float>(m22), as<float>(dx), as<float>(dy)};
}

bool matrix::is_identity(intptr_t handle) {
  if (!handle) return false;
  return reinterpret_cast<wxGraphicsMatrix*>(handle)->IsIdentity();
}

bool matrix::is_invertible(intptr_t handle) {
  if (!handle) return false;
  return true;
}

void matrix::invert(intptr_t handle) {
  if (!handle) return;
  reinterpret_cast<wxGraphicsMatrix*>(handle)->Invert();
}

float matrix::offset_x(intptr_t handle) {
  double dx = 0.0, dy = 0.0;
  reinterpret_cast<wxGraphicsMatrix*>(handle)->TransformDistance(&dx, &dy);
  return as<float>(dx);
}

float matrix::offset_y(intptr_t handle) {
  double dx = 0.0, dy = 0.0;
  reinterpret_cast<wxGraphicsMatrix*>(handle)->TransformDistance(&dx, &dy);
  return as<float>(dy);
}

void matrix::multiply(intptr_t handle, intptr_t matrix, int32_t order) {
  if (!handle) return;
  /// Does not exist on wxWidgets...
}

void matrix::reset(intptr_t handle) {
  if (!handle) return;
  reinterpret_cast<wxGraphicsMatrix*>(handle)->Set();
}

void matrix::rotate(intptr_t handle, float angle, int32_t order) {
  if (!handle) return;
  reinterpret_cast<wxGraphicsMatrix*>(handle)->Rotate(math::degrees_to_radians(angle));
}

void matrix::rotate_at(intptr_t handle, float angle, float x, float y, int32_t order) {
  if (!handle) return;
  reinterpret_cast<wxGraphicsMatrix*>(handle)->Translate(x, y);
  reinterpret_cast<wxGraphicsMatrix*>(handle)->Rotate(math::degrees_to_radians(angle));
}

void matrix::scale(intptr_t handle, float scale_x, float scale_y, int32_t order) {
  if (!handle) return;
  reinterpret_cast<wxGraphicsMatrix*>(handle)->Scale(scale_x, scale_y);
}

void matrix::shear(intptr_t handle, float scale_x, float scale_y, int32_t order) {
  if (!handle) return;
  /// Does not exist on wxWidgets...
}

void matrix::transform_point(intptr_t handle, int32_t& x, int32_t& y) {
  if (!handle) return;
  double dx = x, dy = y;
  reinterpret_cast<wxGraphicsMatrix*>(handle)->TransformPoint(&dx, &dy);
  x = as<int32_t>(dx);
  y = as<int32_t>(dy);
}

void matrix::transform_point(intptr_t handle, float& x, float& y) {
  if (!handle) return;
  double dx = x, dy = y;
  reinterpret_cast<wxGraphicsMatrix*>(handle)->TransformPoint(&dx, &dy);
  x = as<float>(dx);
  y = as<float>(dy);
}

void matrix::transform_vectors(intptr_t handle, std::vector<std::pair<int32_t, int32_t>>& points) {
  if (!handle) return;
}

void matrix::transform_vectors(intptr_t handle, std::vector<std::pair<float, float>>& points) {
  if (!handle) return;
}

void matrix::translate(intptr_t handle, float ofset_x, float offset_y, int32_t order) {
  if (!handle) return;
  reinterpret_cast<wxGraphicsMatrix*>(handle)->Translate(offset_y, offset_y);
}

void matrix::vector_transform_points(intptr_t handle, std::vector<std::pair<int32_t, int32_t>>& points) {
  if (!handle) return;
}
