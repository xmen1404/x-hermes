add_library(config INTERFACE)

target_sources(
  config PUBLIC
  config.h
)

# dependencies
target_include_directories(config INTERFACE ${CMAKE_SOURCE_DIR})
target_link_libraries(config INTERFACE base)
