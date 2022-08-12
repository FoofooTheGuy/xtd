#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Status bar example");
      client_size({820, 500});
      
      status_bar1.parent(*this);
      status_bar1.panels().push_back_range({status_bar_panel1, status_bar_panel2, status_bar_panel3, status_bar_panel4});
      status_bar1.show_panels(true);
      
      status_bar_panel1.auto_size(xtd::forms::status_bar_panel_auto_size::contents);
      status_bar_panel1.border_style(xtd::forms::status_bar_panel_border_style::sunken);
      status_bar_panel1.tool_tip_text("Status one tool tip text");

      status_bar_panel2.auto_size(xtd::forms::status_bar_panel_auto_size::contents);
      status_bar_panel2.border_style(xtd::forms::status_bar_panel_border_style::sunken);

      status_bar_panel3.auto_size(xtd::forms::status_bar_panel_auto_size::spring);
      status_bar_panel3.border_style(xtd::forms::status_bar_panel_border_style::sunken);

      status_bar_panel4.auto_size(xtd::forms::status_bar_panel_auto_size::contents);
      status_bar_panel4.border_style(xtd::forms::status_bar_panel_border_style::sunken);
      
      timer1.interval_milliseconds(50);
      timer1.tick += [&] {
        progress_bar1.value(progress_bar1.value() < progress_bar1.maximum() ? progress_bar1.value() + 1 : progress_bar1.minimum());
      };
      timer1.enabled(true);
    }
    
  private:
    static image image_from_color(const color& color) {
      bitmap bitmap(16, 16);
      auto g = graphics::from_image(bitmap);
      g.fill_ellipse(solid_brush(color), 0, 0, bitmap.width(), bitmap.height());
      g.draw_ellipse(pens::black(), 0, 0, bitmap.width() - 1, bitmap.height() - 1);
      return bitmap;
    }

    forms::status_bar status_bar1;
    status_bar_panel status_bar_panel1 = status_bar_panel::create_panel("Status one", image_from_color(color::light_green));
    status_bar_panel status_bar_panel2 = status_bar_panel::create_panel("Status two");
    status_bar_panel status_bar_panel3 = status_bar_panel::create_panel("Status three");
    timer timer1;
    progress_bar progress_bar1;
    status_bar_panel status_bar_panel4 = status_bar_panel::create_control(progress_bar1);
  };
}

int main() {
  application::run(examples::form1 {});
}
