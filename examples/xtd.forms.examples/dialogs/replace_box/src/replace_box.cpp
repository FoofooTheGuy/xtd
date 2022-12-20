#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Replace box example");
    
    find_button.parent(*this);
    find_button.text("replace...");
    find_button.location({10, 10});
    find_button.click += [&] {
      replace_box::show(*this, "Gammasoft", "xtd", "Replace", [&](object& sender, const find_event_args& e) {
        diagnostics::debug::write_line(ustring::format("Find next : find string [{}], match case [{}], whole word [{}]", e.find_string(), e.match_case(), e.whole_word()));
      }, [&](object& sender, const replace_event_args& e) {
        diagnostics::debug::write_line(ustring::format("Replace : find string [{}], replace string [{}], match case [{}], whole word [{}]", e.find_string(), e.replace_string(), e.match_case(), e.whole_word()));
      }, [&](object& sender, const replace_event_args& e) {
        diagnostics::debug::write_line(ustring::format("Replace all : find string [{}], replace string [{}], match case [{}], whole word [{}]", e.find_string(), e.replace_string(), e.match_case(), e.whole_word()));
      });
    };
  }
  
private:
  button find_button;
};

int main() {
  debug_form df;
  application::run(form1 {});
}
