cmake_minimum_required(VERSION 3.3)

# Project
project(docs)
include(../scripts/cmake/xtd_commands.cmake)
include(../scripts/cmake/xtd_version.cmake)

add_sources(
  README.md
  abstract_class_design.md
  abstract_factory.md
  abstractions_abstract_types_and_interfaces.md
  adapter.md
  architecture.md
  base_classes_for_implementing_abstractions.md
  builder.md
  bridge.md
  capitalisation_conventions.md
  chain_of_responsibility.md
  choosing_between_class_and_struct.md
  class_cleanup.md
  class_initialize.md
  csf.md
  coding_conventions_guidelines.md
  command.md
  common_design_patterns.md
  composite.md
  console_classes.md
  constructor_design.md
  contact.md
  controls.md
  custom_controls.md
  decorator.md
  dependences.md
  design_guidelines.md
  design_guidelines_for_exception.md
  designing_for_extensibility.md
  development_status.md
  development_status_cmake.md
  development_status_themes.md
  development_status_toolkits.md
  development_status_tools.md
  development_status_xtd_core.md
  development_status_xtd_drawing.md
  development_status_xtd_forms.md
  development_status_xtd_tunit.md
  dialogs.md
  documentation.md
  downloads.md
  drag_and_drop.md
  enum_design.md
  event_design.md
  events.md
  events_and_callbacks.md
  examples.md
  exceptions_and_performance.md
  exception_throwing.md
  extending_test.md
  external_tools_libraries_and_toolkits.md
  facade.md
  factory_method.md
  field_design.md
  final.md
  first_programs.md
  flyweight.md
  gallery.md
  gammasoft.md
  general_naming_conventions.md
  getting_started.md
  graphics.md
  hierarchy.md
  home.md
  ignore_test_method.md
  interface_design.md
  interpreter.md
  introduction.md
  iterator.md
  layout_management.md
  license.md
  links.md
  mediator.md
  member_design_guidelines.md
  member_overloading.md
  menus_and_toolbars.md
  memento.md
  names_of_classes_structs_and_interfaces.md
  names_of_libraries_and_dlls.md
  names_of_namespace.md
  names_of_type_members.md
  naming_guidelines.md
  naming_parameters.md
  naming_resources.md
  nested_types.md
  news.md
  non-final_classes.md
  observer.md
  operator_overloads.md
  parameter_design.md
  portability.md
  property_design.md
  protected_members.md
  prototype.md
  proxy.md
  release_notes.md
  running_test.md
  singleton.md
  state.md
  static_class_design.md
  strategy.md
  struct_design.md
  template_method.md
  test_class.md
  test_cleanup.md
  test_initialize.md
  test_method.md
  tetris.md
  tools.md
  translations_status.md
  tutorial.md
  type_design_guidelines.md
  unit_testing_classes.md
  usage_guidelines.md
  using_standard_exception_types.md
  virtual_members.md
  visitor.md
  writing_applications.md
  writing_console_application.md
  writing_gui_application.md
  writing_test_application.md
)
add_sources(
  ../AUTHORS.md
  ../CODE_OF_CONDUCT.md
  ../CONTRIBUTING.md
  ../LICENSE.md
  ../README.md
)
target_type(INTERFACE_LIBRARY)

# Install
if (XTD_INSTALL_RESOURCES)
  install(DIRECTORY pictures/examples/. DESTINATION share/xtd/resources/pictures/examples)
endif ()
