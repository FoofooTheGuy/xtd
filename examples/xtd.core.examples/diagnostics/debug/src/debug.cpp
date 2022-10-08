// Specify -DDEBUG when compiling or add #define DEBUG in the source file.

#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

int main() {
  debug::listeners().push_back(make_shared<ostream_trace_listener>(console::out));
  debug::auto_flush(true);
  debug::indent();
  debug::write_line("Entering Main");
  console::write_line("Hello World.");
  debug::write_line("Exiting Main");
  debug::unindent();
}

// This code produces the following output :
//
//     Entering Main
// Hello World.
//     Exiting Main
