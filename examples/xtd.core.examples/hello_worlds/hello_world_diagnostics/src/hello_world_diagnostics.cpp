#define TRACE
#include <xtd/xtd.core>

using namespace xtd::diagnostics;

int main() {
  trace::write_line("Hello, World!");
}

// This code can produces the following output debug:
//
// Hello, World!
