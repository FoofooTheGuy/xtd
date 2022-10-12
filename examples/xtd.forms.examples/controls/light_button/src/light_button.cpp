#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Light button example");
      controls().push_back_range({light_button1, light_button2, light_button3});
      
      light_button1.auto_check(false);
      light_button1.click += [&] {
        //light_button1.checked(!light_button1.checked());
        light_button1.text(ustring::format("{}", light_button1.check_state()));
      };
      light_button1.location({30, 30});
      light_button1.text(ustring::format("{}", light_button1.check_state()));
      light_button1.width(130);
      
      light_button2.check_state_changed += [&] {
        light_button2.text(ustring::format("{}", light_button2.check_state()));
      };
      light_button2.checked(true);
      light_button2.location({30, 80});
      light_button2.width(130);
      
      light_button3.auto_size(true);
      light_button3.check_state_changed += [&] {
        light_button3.text(ustring::format("{}", light_button3.check_state()));
      };
      light_button3.check_state(forms::check_state::indeterminate);
      light_button3.three_state(true);
      light_button3.location({30, 130});
      light_button3.width(130);
    }
    
  private:
    light_button light_button1;
    light_button light_button2;
    light_button light_button3;
  };
}

int main() {
  application::enable_visual_styles();
  application::run(examples::form1 {});
}
