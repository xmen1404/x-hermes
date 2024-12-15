add_library(base INTERFACE)

target_sources (
  base PUBLIC
  message.h
)

target_include_directories(
  base INTERFACE ${CMAKE_SOURCE_DIR}/core
)

# dependencies
find_package(glog REQUIRED)
target_link_libraries(base INTERFACE glog::glog)