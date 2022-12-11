#include <xtd/xtd>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::io;

int main() {
  bitmap bitmap(300, 300);
  auto graphics = graphics::from_image(bitmap);
  graphics.draw_string("Hello World!", {system_fonts::default_font(), 32, font_style::bold | font_style::italic}, solid_brush(color::dark(color::spring_green, 2.0 / 3)), rectangle::offset({{0, 0}, bitmap.size()}, {2, 2}), string_format().alignment(string_alignment::center).line_alignment(string_alignment::center));
  graphics.draw_string("Hello World!", {system_fonts::default_font(), 32, font_style::bold | font_style::italic}, brushes::spring_green(), rectangle::inflate({{0, 0}, bitmap.size()}, {-2, -2}), string_format().alignment(string_alignment::center).line_alignment(string_alignment::center));
  bitmap.save(path::combine(path::get_temp_path(), "hello_world_png.png"));
  process::start(path::combine(path::get_temp_path(), "hello_world_png.png"));
}
