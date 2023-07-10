#include <xtd/console>
#include <xtd/date_time>
#include <xtd/startup>
#include <vector>

using namespace std;
using namespace xtd;

class program {
public:
  static auto main() {
    vector<double> hours = {.08333, .16667, .25, .33333, .5, .66667, 1, 2, 29, 30, 31, 90, 365};
    date_time date_value(2009, 3, 1, 12, 0, 0);
    
    for (double hour : hours)
      console::write_line("{0:u} + {1} hour(s) = {2:u}", date_value, hour, date_value.add_hours(hour));
  }
};

startup_(program);

// This code can produces the following output:
//
// 2009-03-01 12:00:00 + 0.08333 hour(s) = 2009-03-01 12:04:59
// 2009-03-01 12:00:00 + 0.16667 hour(s) = 2009-03-01 12:10:00
// 2009-03-01 12:00:00 + 0.25 hour(s) = 2009-03-01 12:15:00
// 2009-03-01 12:00:00 + 0.33333 hour(s) = 2009-03-01 12:19:59
// 2009-03-01 12:00:00 + 0.5 hour(s) = 2009-03-01 12:30:00
// 2009-03-01 12:00:00 + 0.66667 hour(s) = 2009-03-01 12:40:00
// 2009-03-01 12:00:00 + 1 hour(s) = 2009-03-01 13:00:00
// 2009-03-01 12:00:00 + 2 hour(s) = 2009-03-01 14:00:00
// 2009-03-01 12:00:00 + 29 hour(s) = 2009-03-02 17:00:00
// 2009-03-01 12:00:00 + 30 hour(s) = 2009-03-02 18:00:00
// 2009-03-01 12:00:00 + 31 hour(s) = 2009-03-02 19:00:00
// 2009-03-01 12:00:00 + 90 hour(s) = 2009-03-05 06:00:00
// 2009-03-01 12:00:00 + 365 hour(s) = 2009-03-16 17:00:00
