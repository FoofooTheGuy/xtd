#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("List box example");
      client_size({360, 240});

      list_box_left.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom);
      list_box_left.location({20, 20});
      list_box_left.parent(*this);
      list_box_left.size({150, 200});
      list_box_left.double_click += [this](const control& sender, const event_args& e) {
        if (list_box_left.selected_index() != -1) {
          list_box_right.items().push_back(list_box_left.selected_item());
          list_box_right.selected_index(0);
          list_box_left.items().erase_at(list_box_left.selected_index());
        }
      };

      list_box_right.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom | anchor_styles::right);
      list_box_right.location({190, 20});
      list_box_right.parent(*this);
      list_box_right.sorted(true);
      list_box_right.size({150, 200});
      list_box_right.double_click += [this](const control& sender, const event_args& e) {
        if (list_box_right.selected_index() != -1) {
          list_box_left.items().push_back(list_box_right.selected_item());
          list_box_left.selected_index(0);
          list_box_right.items().erase_at(list_box_right.selected_index());
        }
      };
      
      list_box_left.items().push_back_range({"draw", "cut", "paste", "delete", "open", "close", "remove", "edit", "find", "increment", "decrement", "write", "read", "post", "build", "make", "release", "create", "choose", "erase"});
      list_box_left.selected_index(0);
    }
    
  private:
    list_box list_box_left;
    list_box list_box_right;
  };
}

int main() {
  application::run(examples::form1());
}
