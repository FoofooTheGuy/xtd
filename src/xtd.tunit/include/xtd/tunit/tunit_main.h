/// @file
/// @brief Contains main entry point.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/startup.h>
#include "../tunit_export.h"

/// @cond
class tunit_export_ __tunit_main final {
public:
  __tunit_main() = delete;
  static int main(int argc, char* argv[]);
};
/// @endcond

#define tunit_main_ \
__tunit_main
