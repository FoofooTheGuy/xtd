#include <xtd/xtd>

using namespace std;
using namespace xtd;

class program {
public:
  static void main() {
    date_time local_date = date_time::now();
    vector<ustring> locale_names = {"en_US", "en_GB", "fr_FR", "de_DE", "ru_RU"};
    
    for (auto locale_name : locale_names) {
      try {
        locale::global(locale(locale_name + ".utf-8"));
        console::write_line("{}: {}", locale_name, local_date.sprintf("%x %T"));
      } catch (const exception& e) {
        console::write_line(ustring::format("Make sure {} locale is installed on your system :\n\n{}\n", locale_name, e.what()), "Exception");
      }
    }
  }
};

startup_(program);

// This code can produces the following output:
//
// en_US: 01/02/2022 10:59:07
// en_GB: 02/01/2022 10:59:07
// fr_FR: 02.01.2022 10:59:07
// de_DE: 02.01.2022 10:59:07
// ru_RU: 02.01.2022 10:59:07
