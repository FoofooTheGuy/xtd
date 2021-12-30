#include <xtd/xtd>

using namespace std::chrono;
using namespace xtd;

class program {
public:
  static void main() {
    int window = 10;
    int freq = 60 * 60 * 2; // 2 hours;
    
    date_time d1 = date_time::now();
    
    date_time d2 = d1.add_seconds(2 * window);
    date_time d3 = d1.add_seconds(-2 * window);
    date_time d4 = d1.add_seconds(window / 2);
    date_time d5 = d1.add_seconds(-window / 2);
    
    date_time d6 = (d1.add_hours(2)).add_seconds(2 * window);
    date_time d7 = (d1.add_hours(2)).add_seconds(-2 * window);
    date_time d8 = (d1.add_hours(2)).add_seconds(window / 2);
    date_time d9 = (d1.add_hours(2)).add_seconds(-window / 2);
    
    console::write_line("d1 ({0}) ~= d1 ({1}): {2}", d1, d1, roughly_equals(d1, d1, window, freq));
    console::write_line("d1 ({0}) ~= d2 ({1}): {2}", d1, d2, roughly_equals(d1, d2, window, freq));
    console::write_line("d1 ({0}) ~= d3 ({1}): {2}", d1, d3, roughly_equals(d1, d3, window, freq));
    console::write_line("d1 ({0}) ~= d4 ({1}): {2}", d1, d4, roughly_equals(d1, d4, window, freq));
    console::write_line("d1 ({0}) ~= d5 ({1}): {2}", d1, d5, roughly_equals(d1, d5, window, freq));
    
    console::write_line("d1 ({0}) ~= d6 ({1}): {2}", d1, d6, roughly_equals(d1, d6, window, freq));
    console::write_line("d1 ({0}) ~= d7 ({1}): {2}", d1, d7, roughly_equals(d1, d7, window, freq));
    console::write_line("d1 ({0}) ~= d8 ({1}): {2}", d1, d8, roughly_equals(d1, d8, window, freq));
    console::write_line("d1 ({0}) ~= d9 ({1}): {2}", d1, d9, roughly_equals(d1, d9, window, freq));
  }
  
private:
  static bool roughly_equals(const date_time& time, const date_time& time_with_window, int window_in_seconds, int frequency_in_seconds) {
    int delta = convert::to_int32(duration_cast<seconds>((time_with_window - time).ticks()).count()) % frequency_in_seconds;
    
    delta = delta > window_in_seconds ? frequency_in_seconds - delta : delta;
    
    return math::abs(delta) < window_in_seconds;
  }
};

startup_(program);

// This code can produces the following output:
//
// d1 (Thu Dec 30 16:18:10 2021) ~= d1 (Thu Dec 30 16:18:10 2021): true
// d1 (Thu Dec 30 16:18:10 2021) ~= d2 (Thu Dec 30 16:18:30 2021): false
// d1 (Thu Dec 30 16:18:10 2021) ~= d3 (Thu Dec 30 16:17:50 2021): false
// d1 (Thu Dec 30 16:18:10 2021) ~= d4 (Thu Dec 30 16:18:15 2021): true
// d1 (Thu Dec 30 16:18:10 2021) ~= d5 (Thu Dec 30 16:18:05 2021): true
// d1 (Thu Dec 30 16:18:10 2021) ~= d6 (Thu Dec 30 18:18:30 2021): false
// d1 (Thu Dec 30 16:18:10 2021) ~= d7 (Thu Dec 30 18:17:50 2021): false
// d1 (Thu Dec 30 16:18:10 2021) ~= d8 (Thu Dec 30 18:18:15 2021): true
// d1 (Thu Dec 30 16:18:10 2021) ~= d9 (Thu Dec 30 18:18:05 2021): true
