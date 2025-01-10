# network unit tests
add_executable (
  config_test
  config_test.cpp
)

# dependencies
target_link_libraries(config_test PRIVATE unit_test)
target_include_directories(config_test PRIVATE ${CMAKE_SOURCE_DIR}/core/config)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/config_test.yaml DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME config_test COMMAND config_test)


