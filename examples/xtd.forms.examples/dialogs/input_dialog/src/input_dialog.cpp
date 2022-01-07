#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Input dialog example");
      controls().push_back_range({button1, label1});
      
      button1.location({10, 10});
      button1.text("Text...");
      button1.click += [&] {
        input_dialog input_dialog;
        input_dialog.text("Caption text");
        input_dialog.message("Message text");
        input_dialog.value(label1.text());
        if (input_dialog.show_sheet_dialog(*this) == dialog_result::ok)
          label1.text(input_dialog.value());
      };
      
      label1.location({10, 50});
      label1.auto_size(true);
      label1.text("Default value");
    }
    
  private:
    button button1;
    label label1;
  };
}

int main() {
  application::run(examples::form1());
}
