cmake_minimum_required(VERSION 3.10)
project(NumericalLibrary)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directory
include_directories(numerical_lib/include)

# Collect source files
file(GLOB SOURCES "numerical_lib/src/*.cpp")
file(GLOB TESTS "numerical_lib/tests/*.cpp")
file(GLOB EXAMPLES "numerical_lib/examples/*.cpp")

# Create static library
add_library(numerical STATIC ${SOURCES})

# Test executable
add_executable(test_all ${TESTS})
target_link_libraries(test_all numerical)

# Example executables
add_executable(example_linear_systems numerical_lib/examples/example_linear_systems.cpp)
target_link_libraries(example_linear_systems numerical)

add_executable(example_interpolation numerical_lib/examples/example_interpolation.cpp)
target_link_libraries(example_interpolation numerical)

# Enable testing
enable_testing()
add_test(NAME NumericalTests COMMAND test_all)

# Installation
install(TARGETS numerical DESTINATION lib)
install(DIRECTORY numerical_lib/include/ DESTINATION include)

# Print status
message(STATUS "Numerical Library configured successfully")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Source files found: ${SOURCES}")