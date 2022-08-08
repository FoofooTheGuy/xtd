#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Folder browser box example");
    controls().push_back(button1);
    
    button1.location({10, 10});
    button1.text("Folder...");
    button1.click += [&] {
      if (folder_browser_box::show(selected_path, *this) == forms::dialog_result::ok)
        label1.text(ustring::format("Path = {}", selected_path));
    };
    
    label1.parent(*this);
    label1.text("Path = ");
    label1.auto_size(true);
    label1.location({10, 40});
  }
  
private:
  button button1;
  label label1;
  ustring selected_path;
};

int main() {
  application::run(form1 {});
}
