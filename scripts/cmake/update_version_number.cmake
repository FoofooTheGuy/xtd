file(READ src/xtd.core/src/xtd/environment_version.cpp ENVIRONMENT_VERSION_API)
string(FIND "${ENVIRONMENT_VERSION_API}" "${XTD_VERSION}" STRING_FOUND)
if (${STRING_FOUND} EQUAL -1)
  message(NOTICE "")
  message(NOTICE "--------------------------------")
  message(NOTICE "--- Version number changed ! ---")
  message(NOTICE "--------------------------------")
  message(NOTICE "")
  
  file(WRITE src/xtd.core/src/xtd/environment_version.cpp
    "// This code was generated by CMake script.\n"
    "//\n"
    "// Changes to this file may cause incorrect behavior and will be lost if the file is regenerated.\n"
    "\n"
    "#include \"../include/xtd/environment.h\"\n"
    "\n"
    "xtd::version xtd::environment::version() {\n"
    "  return xtd::version::parse(\"${XTD_VERSION}\");\n"
    "}\n"
  )
  
  file(WRITE .appveyor.yml
    "# This code was generated by CMake script.\n"
    "#\n"
    "# Changes to this file may cause incorrect behavior and will be lost if the file is regenerated.\n"
    "\n"
    "version: ${XTD_VERSION}.{build}\n"
    "image: Visual Studio 2019\n"
    "\n"
    "environment:\n"
    "  matrix:\n"
    "  - BUILD_OPTION: \"Win32\"\n"
    "  - BUILD_OPTION: \"x64\"\n"
    "\n"
    "install:\n"
    "  - choco install doxygen.install\n"
    "\n"
    "build_script:\n"
    "- cmd: scripts\\appveyor\\build.cmd\n"
    "\n"
    "test_script:\n"
    "- cmd: scripts\\appveyor\\test.cmd\n"
  )
  
  file(WRITE .travis.yml
    "# This code was generated by CMake script.\n"
    "#\n"
    "# Changes to this file may cause incorrect behavior and will be lost if the file is regenerated.\n"
    "\n"
    "language: cpp\n"
    "\n"
    "addons:\n"
    "  homebrew:\n"
    "    packages:\n"
    "    - doxygen\n"
    "\n"
    "matrix:\n"
    "  include:\n"
    "  - env: TEST=\"Build xtd ${XTD_VERSION} on macOS\"\n"
    "    os: osx\n"
    "    osx_image: xcode12.2\n"
    "    script: scripts/travis/build_xtd_on_macos.sh\n"
  )
  
  file(WRITE .circleci/config.yml
    "# This code was generated by CMake script.\n"
    "#\n"
    "# Changes to this file may cause incorrect behavior and will be lost if the file is regenerated.\n"
    "\n"
    "version: 2\n"
    "\n"
    "jobs:\n"
    "  build:\n"
    "    machine:\n"
    "      image: ubuntu-2004:202104-01\n"
    "      \n"
    "    steps:\n"
    "      - checkout\n"
    "      - run: echo \"xtd ${XTD_VERSION} on linux\"\n"
    "      - run:\n"
    "          name: Installing apt\n"
    "          command: 'sudo apt-get update && sudo apt-get install -y sudo && sudo rm -rf /var/lib/apt/lists/*'\n"
    "      - run:\n"
    "          name: Installing gcc\n"
    "          command: 'sudo apt-get update && sudo apt-get install -y gcc g++'\n"
    "      - run:\n"
    "          name: Install cmake\n"
    "          command: 'sudo apt-get update && sudo apt-get install -y cmake'\n"
    "      - run:\n"
    "          name: Install lcov\n"
    "          command: 'sudo apt-get update && sudo apt-get install -y lcov'\n"
    "      - run:\n"
    "          name: Install gsound\n"
    "          command: 'sudo apt-get update && sudo apt-get install -y libgsound-dev'\n"
    "      - run:\n"
    "          name: Install gtk-3\n"
    "          command: 'sudo apt-get update && sudo apt-get install -y libgtk-3-dev'\n"
    "      - run:\n"
    "          name: Install doxygen\n"
    "          command: 'sudo apt-get update && sudo apt-get install -y doxygen'\n"
    "      - run:\n"
    "          name: Build xtd and launch unit tests\n"
    "          command: scripts/circleci/build_xtd_and_launch_unit_tests_on_linux.sh\n"
  )

  file(WRITE install
    "#!/usr/bin/env bash\n"
    "# This code was generated by CMake script.\n"
    "#\n"
    "# Changes to this file may cause incorrect behavior and will be lost if the file is regenerated.\n"
    "\n"
    "export xtd_version=${XTD_VERSION}\n"
    "scripts/install/install.sh \"$@\"\n"
  )
  
  file(WRITE install.cmd
    "@echo off\n"
    ":: This code was generated by CMake script.\n"
    "::\n"
    ":: Changes to this file may cause incorrect behavior and will be lost if the file is regenerated.\n"
    "\n"
    "set xtd_version=${XTD_VERSION}\n"
    "call scripts\\install\\install.cmd %*\n"
  )
endif()
