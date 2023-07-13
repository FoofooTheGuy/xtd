#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/use_wait_cursor>
#include <thread>

using namespace std::chrono;
using namespace std::this_thread;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Use wait cursor example");
    
    button1.auto_size(true);
    button1.location({10, 10});
    button1.parent(*this);
    button1.text("Do something...");
    button1.click += [] {
      use_wait_cursor wait;
      for (auto count = 0; count < 500; ++count) {
        application::do_events();
        sleep_for(milliseconds(10)); // Simulate work...
      }
    };
  }
  
private:
  button button1;
};

auto main()->int {
  xtd::forms::application::run(form1 {});
}
