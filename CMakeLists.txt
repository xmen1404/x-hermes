cmake_minimum_required(VERSION 3.22)

project (x-hermes)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Ensure the standard is required
set(CMAKE_CXX_EXTENSIONS OFF)       # Disable compiler-specific extensions (like GNU extensions)

# env path
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/build/build/Release/generators")

# core implementation
add_subdirectory(core/network)
add_subdirectory(core/config)
add_subdirectory(core/base)

# tests
include(CTest)
enable_testing()

add_subdirectory(test/benchmark)
add_subdirectory(test/unit_test)



