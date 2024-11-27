# socket_test
add_executable (
  network_test
  main.cpp
  socket_test.cpp
)
target_link_libraries(
  network_test PUBLIC unit_test
)
add_test(NAME network_test COMMAND network_test)


