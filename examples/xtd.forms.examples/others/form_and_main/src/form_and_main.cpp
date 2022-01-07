#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form_main : public form {
  public:
    static void main() {
      application::run(form_main());
    }
    
    form_main() {
      text("form main");
      location({300, 200});
      size({640, 480});
      form_closing += [](object & sender, form_closing_event_args & e) {
        e.cancel(message_box::show("Are you sure you want exit?", "Close form", message_box_buttons::yes_no, message_box_icon::question) == dialog_result::no);
      };
      
      button.parent(*this);
      button.text("Close");
      button.location({10, 10});
      button.click += event_handler(*this, &form::close);
    }
    
  private:
    forms::button button;
  };
}

startup_(examples::form_main);
