# network unit tests
add_executable (
  network_base_test
  message_test.cpp
)

# dependencies
target_link_libraries(
  network_base_test PUBLIC unit_test
)
add_test(NAME network_base_test COMMAND network_base_test)



