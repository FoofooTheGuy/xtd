#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Color picker example");
      
      test_zone.parent(*this);
      test_zone.location({10, 50});
      test_zone.border_style(border_style::fixed_3d);
      test_zone.double_buffered(true);
      test_zone.paint += [&](object& sender, paint_event_args& e) {
        e.graphics().fill_rectangle(hatch_brush(hatch_style::wide_checker_board, color::from_argb(0x54, 0x54, 0x54), color::from_argb(0xA8, 0xA8, 0xA8)), e.clip_rectangle());
        e.graphics().fill_rectangle(solid_brush(color_picker.color()), e.clip_rectangle());
        control_paint::draw_border(test_zone, e.graphics(), test_zone.border_style(), test_zone.border_sides(), application::style_sheet().system_colors().control_text(), e.clip_rectangle());
      };

      color_picker.parent(*this);
      color_picker.color(color::red);
      color_picker.location({10, 10});
      color_picker.color_changed += [&] {
        test_zone.invalidate();
      };
    }
    
  private:
    forms::color_picker color_picker;
    panel test_zone;
  };
}

int main() {
  application::run(examples::form1());
}
