#pragma once
#include "base_project.h"

namespace xtdc_command {
  class xtd_unit_test_application_project : public base_project {
  public:
    explicit xtd_unit_test_application_project(const xtd::ustring& path) : base_project(path) {}

    void create(const xtd::ustring& name, bool create_solution) const {
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "properties") : xtd::io::path::combine(current_path(), "properties"));
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "src") : xtd::io::path::combine(current_path(), "src"));
      if (create_solution) create_xtd_unit_test_application_solution_cmakelists_txt(name);
      create_xtd_unit_test_application_application_properties(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_xtd_unit_test_application_cmakelists_txt(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_xtd_unit_test_application_source(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
    }
    
  private:
    void create_xtd_unit_test_application_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.3)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        "find_package(xtd REQUIRED)",
        "add_projects(",
        xtd::ustring::format("  {}", name),
        ")",
        "",
        "# Install",
        "install_package()",
      };
      xtd::io::file::write_all_lines(xtd::io::path::combine(current_path(), "CMakeLists.txt"), lines);
    }
    
    void create_xtd_unit_test_application_application_properties(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines{
        xtd::ustring::format("target_default_namespace(\"{}\")", name),
        xtd::ustring::format("target_name(\"{}\")", name),
        xtd::ustring::format("target_startup(tunit_main_)", name),
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "properties", "target_properties.cmake"), lines);
    }
    
    void create_xtd_unit_test_application_cmakelists_txt(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.3)",
        "",
        "# Project",
        xtd::ustring::format("project({})", name),
        "find_package(xtd REQUIRED)",
        "add_sources(",
        "  src/unit_test1.cpp",
        ")",
        "target_type(TEST_APPLICATION)",
        "",
        "# Install",
        "install_component()",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void create_xtd_unit_test_application_source(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "#include <xtd/xtd.tunit>",
        "",
        "using namespace xtd::tunit;",
        "",
        xtd::ustring::format("namespace {} {{", name),
        "  class test_class_(unit_test1) {",
        "  public:",
        "    void test_method_(test_method1) {",
        "      assert::ignore(\"Hello, World!\");",
        "    }",
        "  };",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "unit_test1.cpp"), lines);
    }
  };
}
