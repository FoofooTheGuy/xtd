#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form_main : public form {
  public:
    static auto main() {
      application::run(form_main());
    }
    
    form_main() {
      double_buffered(true);
      background_image(images::from_name("xtd", drawing::size(64, 64)));
      text("form with background image example");
      
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
