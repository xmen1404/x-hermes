add_library(network INTERFACE)

target_sources (
  network PUBLIC
  base.h
  message.h
)

target_include_directories (
  network INTERFACE ${CMAKE_SOURCE_DIR}
)

# dependencies
target_link_libraries(network INTERFACE config)
target_link_libraries(network INTERFACE base)

