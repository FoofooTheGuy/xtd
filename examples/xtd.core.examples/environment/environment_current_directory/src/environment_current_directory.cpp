#include <xtd/xtd>

using namespace xtd;
using namespace xtd::io;

int main() {
  environment::current_directory(environment::get_folder_path(environment::special_folder::desktop));
  console::write_line("Directory entry:   " + path::get_full_path("."));
}

// This code produces the following output :
//
// Directory entry:   /!---OMITTED---!/Desktop/.
