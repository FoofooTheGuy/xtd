#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Replace dialog example");
    
    replace_button.parent(*this);
    replace_button.text("replace...");
    replace_button.location({10, 10});
    replace_button.click += [&] {
      replace_dialog.show(*this);
    };
    
    replace_dialog.title("Replace");
    replace_dialog.find_string("Gammasoft");
    replace_dialog.replace_string("xtd");
    replace_dialog.find_next += [&](object& sender, const find_event_args& e) {
      diagnostics::debug::write_line(ustring::format("Find next : find string [{}], match case [{}], search direction [{}], whole word [{}]", e.find_string(), e.match_case(), e.search_direction(), e.whole_word()));
    };
    replace_dialog.replace += [&](object& sender, const replace_event_args& e) {
      diagnostics::debug::write_line(ustring::format("Replace : find string [{}], replace string [{}], match case [{}], whole word [{}]", e.find_string(), e.replace_string(), e.match_case(), e.whole_word()));
    };
    replace_dialog.replace_all += [&](object& sender, const replace_event_args& e) {
      diagnostics::debug::write_line(ustring::format("Replace all : find string [{}], replace string [{}], match case [{}], whole word [{}]", e.find_string(), e.replace_string(), e.match_case(), e.whole_word()));
    };
  }
  
private:
  button replace_button;
  xtd::forms::replace_dialog replace_dialog;
};

int main() {
  application::run(form1());
}
