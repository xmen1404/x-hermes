# network unit tests
add_executable (
  message_test
  message_test.cpp
)

# dependencies
target_link_libraries(message_test PRIVATE unit_test)
target_include_directories(message_test PRIVATE ${CMAKE_SOURCE_DIR}/core/base)
add_test(NAME message_test COMMAND message_test)


