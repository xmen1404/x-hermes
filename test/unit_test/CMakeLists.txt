# base dependencies for all unit_test
add_library (unit_test INTERFACE)

find_package(Catch2 REQUIRED)
find_package(glog REQUIRED)
find_package(yaml-cpp REQUIRED)

target_include_directories (
  unit_test INTERFACE ${CMAKE_SOURCE_DIR}
)

target_link_libraries (
  unit_test INTERFACE
  Catch2::Catch2WithMain
  glog::glog
  yaml-cpp::yaml-cpp
)

add_subdirectory(network)
add_subdirectory(config)
add_subdirectory(base)

