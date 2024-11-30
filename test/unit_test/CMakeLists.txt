# base dependencies for all unit_test
add_library (unit_test INTERFACE)

find_package(Catch2 REQUIRED)
find_package(glog REQUIRED)

target_include_directories (
  unit_test INTERFACE ${CMAKE_SOURCE_DIR}
)

target_link_libraries (
  unit_test INTERFACE
  Catch2::Catch2WithMain
  glog::glog
)

add_subdirectory(network)

