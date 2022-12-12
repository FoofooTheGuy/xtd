#include "../../../include/xtd/drawing/image.h"
#include "../../../include/xtd/drawing/bitmap.h"
#include "../../../include/xtd/drawing/graphics.h"
#include <fstream>
#include <xtd/as.h>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/argument_exception.h>
#include <xtd/drawing/native/image.h>
#include <xtd/drawing/native/image_formats.h>
#include <xtd/drawing/native/frame_dimension.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

image image::empty;

namespace {
  xtd::drawing::imaging::image_format to_image_format(size_t raw_fomat) {
    static std::map<size_t, xtd::drawing::imaging::image_format> raw_formats {{IFM_BMP, imaging::image_format::bmp()}, {IFM_EMF, imaging::image_format::emf()}, {IFM_EXIF, imaging::image_format::exif()}, {IFM_GIF, imaging::image_format::gif()}, {IFM_ICO, imaging::image_format::ico()}, {IFM_JPEG, imaging::image_format::jpeg()}, {IFM_MEMORY_BMP, imaging::image_format::memory_bmp()}, {IFM_PNG, imaging::image_format::png()}, {IFM_TIFF, imaging::image_format::tiff()}, {IFM_WMF, imaging::image_format::wmf()}, {IFM_MEMORY_GIF, imaging::image_format::memory_gif()}, {IFM_MEMORY_ICO, imaging::image_format::memory_ico()}, {IFM_MEMORY_JPEG, imaging::image_format::memory_jpeg()}, {IFM_MEMORY_PNG, imaging::image_format::memory_png()}, {IFM_MEMORY_TIFF, imaging::image_format::memory_tiff()}, {IFM_CUR, imaging::image_format::cur()}, {IFM_MEMORY_CUR, imaging::image_format::memory_cur()}, {IFM_XBM, imaging::image_format::xbm()}, {IFM_MEMORY_XBM, imaging::image_format::memory_xbm()}, {IFM_XPM, imaging::image_format::xpm()}, {IFM_MEMORY_XPM, imaging::image_format::memory_xpm()}, {IFM_PNM, imaging::image_format::pnm()}, {IFM_MEMORY_PNM, imaging::image_format::memory_pnm()}, {IFM_PCX, imaging::image_format::pcx()}, {IFM_MEMORY_PCX, imaging::image_format::memory_pcx()}, {IFM_PICT, imaging::image_format::pict()}, {IFM_MEMORY_PICT, imaging::image_format::memory_pict()}, {IFM_ICON, imaging::image_format::icon()}, {IFM_MEMORY_ICON, imaging::image_format::memory_icon()}, {IFM_MACCUR, imaging::image_format::cursor()}, {IFM_MEMORY_MACCUR, imaging::image_format::memory_cursor()}, {IFM_ANI, imaging::image_format::ani()}, {IFM_IIF, imaging::image_format::iif()}, {IFM_TGA, imaging::image_format::tga()}};
    auto it = raw_formats.find(raw_fomat);
    return it == raw_formats.end() ? xtd::drawing::imaging::image_format() : it->second;
  }
  
  size_t to_raw_format(const xtd::drawing::imaging::image_format& image_format) {
    static std::map<xtd::drawing::imaging::image_format, size_t> image_formats {{imaging::image_format::bmp(), IFM_BMP}, {imaging::image_format::emf(), IFM_EMF}, {imaging::image_format::exif(), IFM_EXIF}, {imaging::image_format::gif(), IFM_GIF}, {imaging::image_format::ico(), IFM_ICO}, {imaging::image_format::jpeg(), IFM_JPEG}, {imaging::image_format::memory_bmp(), IFM_MEMORY_BMP}, {imaging::image_format::png(), IFM_PNG}, {imaging::image_format::tiff(), IFM_TIFF}, {imaging::image_format::wmf(), IFM_WMF}, {imaging::image_format::memory_gif(), IFM_MEMORY_GIF}, {imaging::image_format::memory_ico(), IFM_MEMORY_ICO}, {imaging::image_format::memory_jpeg(), IFM_MEMORY_JPEG}, {imaging::image_format::memory_png(), IFM_MEMORY_PNG}, {imaging::image_format::memory_tiff(), IFM_MEMORY_TIFF}, {imaging::image_format::cur(), IFM_CUR}, {imaging::image_format::memory_cur(), IFM_MEMORY_CUR}, {imaging::image_format::xbm(), IFM_XBM}, {imaging::image_format::memory_xbm(), IFM_MEMORY_XBM}, {imaging::image_format::xpm(), IFM_XPM}, {imaging::image_format::memory_xpm(), IFM_MEMORY_XPM}, {imaging::image_format::pnm(), IFM_PNM}, {imaging::image_format::memory_pnm(), IFM_MEMORY_PNM}, {imaging::image_format::pcx(), IFM_PCX}, {imaging::image_format::memory_pcx(), IFM_MEMORY_PCX}, {imaging::image_format::pict(), IFM_PICT}, {imaging::image_format::memory_pict(), IFM_MEMORY_PICT}, {imaging::image_format::icon(), IFM_ICON}, {imaging::image_format::memory_icon(), IFM_MEMORY_ICON}, {imaging::image_format::cursor(), IFM_MACCUR}, {imaging::image_format::memory_cursor(), IFM_MEMORY_MACCUR}, {imaging::image_format::ani(), IFM_ANI}, {imaging::image_format::iif(), IFM_IIF}, {imaging::image_format::tga(), IFM_TGA}};
    auto it = image_formats.find(image_format);
    return it == image_formats.end() ? IFM_UNKNOWN : it->second;
  }
}

image::image(intptr_t hbitmap) {
  if (hbitmap) {
    data_->handle_ = hbitmap;
    update_properties();
  }
}

image::image(const ustring& filename) {
  map<size_t, size_t> frame_resolutions;
  data_->handle_ = native::image::create(filename, frame_resolutions);
  data_->frame_dimensions.clear();
  for (auto frame_resolution : frame_resolutions) {
    if (frame_resolution.first == FD_PAGE) data_->frame_dimensions[imaging::frame_dimension::page().guid()] =  frame_resolution.second;
    else if (frame_resolution.first == FD_RESOLUTION) data_->frame_dimensions[imaging::frame_dimension::resolution().guid()] =  frame_resolution.second;
    else if (frame_resolution.first == FD_TIME) data_->frame_dimensions[imaging::frame_dimension::time().guid()] =  frame_resolution.second;
    else throw argument_exception(csf_);
  }
  update_properties();
}

image::image(std::istream& stream) {
  map<size_t, size_t> frame_resolutions;
  data_->handle_ = native::image::create(stream, frame_resolutions);
  data_->frame_dimensions.clear();
  for (auto frame_resolution : frame_resolutions) {
    if (frame_resolution.first == FD_PAGE) data_->frame_dimensions[imaging::frame_dimension::page().guid()] =  frame_resolution.second;
    else if (frame_resolution.first == FD_RESOLUTION) data_->frame_dimensions[imaging::frame_dimension::resolution().guid()] =  frame_resolution.second;
    else if (frame_resolution.first == FD_TIME) data_->frame_dimensions[imaging::frame_dimension::time().guid()] =  frame_resolution.second;
    else throw argument_exception(csf_);
  }
  update_properties();
}

image::image(const char* const* bits) {
  data_->handle_ = native::image::create(bits);
  data_->raw_format_ = imaging::image_format::memory_xpm();
  update_properties();
}

image::image(int32 width, int32 height) {
  data_->handle_ = native::image::create(width, height);
  update_properties();
}

image::image(const image& image, int32 width, int32 height) {
  data_->handle_ = native::image::create(image.handle(), width, height);
  update_properties();
}

image::image(const image& image, const rectangle& rect) {
  data_->handle_ = native::image::create(image.handle(), rect.left(), rect.top(), rect.width(), rect.height());
  update_properties();
}

image::~image() {
  if (data_.use_count() == 1 && data_->handle_)
    native::image::destroy(data_->handle_);
}

int32 image::flags() const noexcept {
  return static_cast<int32>(data_->flags_);
}

vector<guid> image::frame_dimentions_list() const noexcept {
  vector<guid> result;
  for (auto frame : data_->frame_dimensions)
    result.push_back(frame.first);
  return result;
}

intptr_t image::handle() const noexcept {
  return data_->handle_;
}

int32 image::height() const noexcept {
  return data_->size_.height();
}

float image::horizontal_resolution() const noexcept {
  return data_->horizontal_resolution_;
}

imaging::color_palette image::palette() const noexcept {
  return data_->palette_;
}

void image::palette(const imaging::color_palette& palette) noexcept {
  data_->palette_ = palette;
}

const size_f& image::physical_dimension() const noexcept {
  return data_->physical_dimension_;
}

imaging::pixel_format image::pixel_format() const noexcept {
  return data_->pixel_format_;
}

const std::vector<int32>& image::property_id_list() const noexcept {
  return data_->property_id_list_;
}

const std::vector<imaging::property_item>& image::property_items() const noexcept {
  return data_->property_items_;
}

const imaging::image_format& image::raw_format() const noexcept {
  return data_->raw_format_;
}

const drawing::size& image::size() const noexcept {
  return data_->size_;
}

const std::any& image::tag() const noexcept {
  return data_->tag_;
}

void image::tag(const std::any& tag) noexcept {
  data_->tag_ = tag;
}

float image::vertical_resolution() const noexcept {
  return data_->vertical_resolution_;
}

int32 image::width() const noexcept {
  return data_->size_.width();
}

bool image::equals(const image& image) const noexcept {
  return data_->handle_ == image.data_->handle_;
}

bitmap image::from_hbitmap(intptr_t hbitmap) {
  return bitmap(image(hbitmap));
}

image image::from_stream(std::istream& stream) {
  return image(stream);
}

image image::from_data(const char* const* bits) {
  return image(bits);
}

xtd::drawing::rectangle_f image::get_bounds(graphics_unit page_unit) const noexcept {
  return rectangle_f(0.0f, 0.0f, graphics::to_page_unit(as<float>(data_->size_.width()), page_unit, 1.0f, native::image::screen_dpi()), graphics::to_page_unit(as<float>(data_->size_.height()), page_unit, 1.0f, native::image::screen_dpi()));
}

xtd::drawing::imaging::encoder_parameters image::get_encoder_parameter_list(xtd::guid encoder) const noexcept {
  xtd::drawing::imaging::encoder_parameters result;
  for (auto encoder_parameter : data_->encoder_parameter_list_.params()) {
    if (encoder_parameter.encoder().guid() == encoder)
      result.params().push_back(encoder_parameter);
  }
  return result;
}

size_t image::get_frame_count(const xtd::drawing::imaging::frame_dimension& dimension) const {
  for (auto frame : data_->frame_dimensions)
    if (frame.first == dimension.guid()) return frame.second;
  throw argument_exception(csf_);
}

int32 image::get_pixel_format_size(xtd::drawing::imaging::pixel_format pixfmt) noexcept {
  return (static_cast<int32>(pixfmt) >> 8) & 0xFF;
}

xtd::drawing::imaging::property_item image::get_property_item(int32 propid) {
  for (auto property_tiem : data_->property_items_)
    if (property_tiem.id() == propid) return property_tiem;
  throw argument_exception(csf_);
}

xtd::drawing::image image::get_thmbnail_image(int32 thumb_width, int32 thunb_height) noexcept {
  return image(*this, thumb_width, thunb_height);
}

bool image::is_alpha_pixel_format(xtd::drawing::imaging::pixel_format pixfmt) noexcept {
  return (pixfmt & xtd::drawing::imaging::pixel_format::alpha) == xtd::drawing::imaging::pixel_format::alpha;
}

bool image::is_canonical_pixel_format(xtd::drawing::imaging::pixel_format pixfmt) noexcept {
  return (pixfmt & xtd::drawing::imaging::pixel_format::canonical) == xtd::drawing::imaging::pixel_format::canonical;
}

bool image::is_extended_pixel_format(xtd::drawing::imaging::pixel_format pixfmt) noexcept {
  return (pixfmt & xtd::drawing::imaging::pixel_format::extended) == xtd::drawing::imaging::pixel_format::extended;
}

void image::rotate_flip(xtd::drawing::rotate_flip_type rotate_flip_type) {
  native::image::rotate_flip(handle(), static_cast<int32>(rotate_flip_type));
}

void image::save(const ustring& filename) const {
  native::image::save(data_->handle_, filename);
}

void image::save(const ustring& filename, const imaging::image_format& format) const {
  native::image::save(data_->handle_, filename, to_raw_format(format));
}

void image::save(std::ostream& stream, const imaging::image_format& format) const {
  native::image::save(data_->handle_, stream, to_raw_format(format));
}

void image::update_properties() {
  data_->flags_ = static_cast<imaging::image_flags>(native::image::flags(data_->handle_));
  
  data_->horizontal_resolution_ = native::image::horizontal_resolution(data_->handle_);
  
  std::vector<std::tuple<xtd::byte, xtd::byte, xtd::byte, xtd::byte>> palette_entries;
  native::image::color_palette(data_->handle_, palette_entries, data_->palette_.flags_);
  for (auto [a, r, g, b] : palette_entries)
    data_->palette_.entries_.push_back(color::from_argb(a, r, g, b));
    
  data_->pixel_format_ = static_cast<imaging::pixel_format>(native::image::pixel_format(data_->handle_));
  
  int32 physical_width, physical_height;
  native::image::physical_dimension(data_->handle_, physical_width, physical_height);
  data_->physical_dimension_ = drawing::size_f(static_cast<float>(physical_width), static_cast<float>(physical_height));
  
  data_->property_id_list_ = native::image::property_id_list(data_->handle_);
  
  for (const native::image::property_item& i : native::image::property_items(data_->handle_)) {
    imaging::property_item item;
    item.id(i.id);
    item.len(i.len);
    item.value(i.value);
    data_->property_items_.push_back(item);
  }
  
  data_->raw_format_ = to_image_format(native::image::raw_format(data_->handle_));
  
  int32 width, height;
  native::image::size(data_->handle_, width, height);
  data_->size_ = drawing::size(width, height);
  
  data_->vertical_resolution_ = native::image::vertical_resolution(data_->handle_);
}
