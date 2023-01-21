#include <xtd/xtd>

using namespace xtd;

namespace examples {
  class program {
  public:
    static void main() {
      // Write arguments to the console output
      for (ustring arg : environment::get_command_line_args())
        console::write_line(arg);
        
      // return 42
      environment::exit_code(42);
    }
  };
}

startup_(examples::program);
// startup_(examples::program); is same as :
//
// auto main(int argc, char* argv[])->int {
//   examples::program::main();
//   return environment::exit_code();
// }


// This code produces the following output if one two "three four" five are entered on command line:
//
// /!---OMITTED---!/main1
// one
// two
// three four
// five
