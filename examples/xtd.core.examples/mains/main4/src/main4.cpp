#include <xtd/xtd>

using namespace std;
using namespace xtd;

namespace examples {
  class program {
  public:
    static auto main(const vector<ustring>& args) {
      // Write arguments to the console output
      for (ustring arg : args)
        console::write_line(arg);
        
      return 42;
    }
  };
}

startup_(examples::program);
// startup_(examples::program); is same as :
//
// auto main(int argc, char* argv[])->int {
//   return examples::program::main({argv + 1, argv + argc});
// }


// This code produces the following output if one two "three four" five are entered on command line:
//
// one
// two
// three four
// five
