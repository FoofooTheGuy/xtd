#define TRACE
#include <xtd/xtd>

using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Trace form example");
    
    button1.auto_repeat(true);
    button1.auto_size(true);
    button1.location({10, 10});
    button1.parent(*this);
    button1.text("Write line...");
    button1.click += [&] {
      static int counter = 0;
      xtd::diagnostics::trace::write_line("Write line {}...", ++counter);
    };
  }
  
private:
  button button1;
};

auto main()->int {
  trace_form trace_form;
  trace_form.back_color(xtd::drawing::color::navy);
  trace_form.fore_color(xtd::drawing::color::white);
  application::run(form1 {});
}
