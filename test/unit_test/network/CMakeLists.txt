# network unit tests
add_executable (
  network_test
  main.cpp
  socket_test.cpp
)

# dependencies
target_link_libraries(
  network_test PUBLIC unit_test
)
add_test(NAME network_test COMMAND network_test)


