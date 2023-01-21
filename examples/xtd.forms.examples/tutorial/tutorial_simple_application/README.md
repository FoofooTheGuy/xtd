## A simple application

First we create the very basic [xtd_forms](https://codedocs.xyz/gammasoft71/xtd/group__gui.html) program.

```c++
#include <xtd/xtd.forms>

using namespace xtd::forms;

namespace tutorial {
  class simple : public form {
  public:
    simple() {
      text("Simple");
      start_position(form_start_position::center_screen);
    }

    static auto main() {
      xtd::forms::application::run(simple());
    }
  };
}

startup_(tutorial::simple);
```

This very basic example shows a small window on the screen. The window is centered.

```c++
start_position(form_start_position::center_screen);
```

This method centers the form on the screen, both horizontally and vertically.

```c++
startup_(tutorial::simple);
```

The code behind startup_ macro can be replaced by :

```c++
auto main(int argc, char* argv[])->int {
  tutorial::simple::main();
  return xtd::environment::exit_code();
}
```

This example can be build on Windows, macOS or Linux operating system with CMake.

```cmake
cmake_minimum_required(VERSION 3.3)

project(simple)
find_package(xtd.forms REQUIRED)
add_sources(src/simple.cpp)
target_type(GUI_APPLICATION)
```

See [cmake](https://cmake.org) for more information.

![Screenshot](../../../../docs/pictures/examples/tutorial/simple.png)

Figure: simple
