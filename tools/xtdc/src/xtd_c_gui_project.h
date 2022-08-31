#pragma once
#include "base_project.h"

namespace xtdc_command {
  class xtd_c_gui_project : public base_project {
  public:
    explicit xtd_c_gui_project(const xtd::ustring& path) : base_project(path) {}
    
    void create(const xtd::ustring& name, bool create_solution) const {
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "properties") : xtd::io::path::combine(current_path(), "properties"));
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "resources") : xtd::io::path::combine(current_path(), "resources"));
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "src") : xtd::io::path::combine(current_path(), "src"));
      xtd::io::file::copy(xtd::io::path::combine(get_base_path(), "icons", "xtd_forms.icns"), xtd::io::path::combine(current_path(), (create_solution ? name : ""), "resources", xtd::ustring::format("{}.icns", name)));
      xtd::io::file::copy(xtd::io::path::combine(get_base_path(), "icons", "xtd_forms.ico"), xtd::io::path::combine(current_path(), (create_solution ? name : ""), "resources", xtd::ustring::format("{}.ico", name)));
      xtd::io::file::copy(xtd::io::path::combine(get_base_path(), "icons", "xtd_forms.png"), xtd::io::path::combine(current_path(), (create_solution ? name : ""), "resources", xtd::ustring::format("{}.png", name)));
      if (create_solution) create_xtd_c_gui_solution_cmakelists_txt(name);
      create_xtd_c_gui_application_properties(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_xtd_c_gui_cmakelists_txt(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_xtd_c_gui_source(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
    }
    
  private:
    static xtd::ustring get_base_path() noexcept {return __XTD_RESOURCES_PATH__;}
    
    void create_xtd_c_gui_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.3)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        "find_package(xtd_c REQUIRED)",
        "add_projects(",
        xtd::ustring::format("  {}", name),
        ")",
        "",
        "# Install",
        "install_package()",
      };
      xtd::io::file::write_all_lines(xtd::io::path::combine(current_path(), "CMakeLists.txt"), lines);
    }
    
    void create_xtd_c_gui_application_properties(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines{
        xtd::ustring::format("target_icon(resources/{})", name),
        xtd::ustring::format("target_name(\"{}\")", name),
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "properties", "target_properties.cmake"), lines);
    }
    
    void create_xtd_c_gui_cmakelists_txt(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.3)",
        "",
        "# Project",
        xtd::ustring::format("project({})", name),
        "find_package(xtd_c REQUIRED)",
        "add_sources(",
        "  src/form1.c",
        ")",
        "target_type(C_GUI_APPLICATION)",
        "",
        "# Install",
        "install_component()",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void create_xtd_c_gui_source(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "#include <xtd_c/xtdc.h>",
        "",
        "int main() {",
        "  xtd_forms_control* form1 = xtd_forms_form_create();",
        "  xtd_forms_control_text(form1, \"form1\");",
        "  xtd_forms_control_client_size(form1, (xtd_drawing_size){800, 450});",
        "",
        "  xtd_forms_application_run(XTD_FORMS_FORM(form1));",
        "",
        "  xtd_forms_control_destroy(form1);",
        "  return EXIT_SUCCESS;"
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "form1.c"), lines);
    }
  };
}
