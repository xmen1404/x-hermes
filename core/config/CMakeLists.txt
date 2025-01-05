add_library(config INTERFACE)

target_sources(
  config PUBLIC
  config.h
)

# dependencies
target_include_directories(config INTERFACE ${CMAKE_SOURCE_DIR}/core)

find_package(yaml-cpp REQUIRED)
target_link_libraries (
  config INTERFACE
  base
  yaml-cpp::yaml-cpp
  glog::glog
)
# target_link_libraries(config INTERFACE yaml-cpp)
