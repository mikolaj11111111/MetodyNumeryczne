cmake_minimum_required(VERSION 3.10)
project(NumericalLibrary)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")
file(GLOB TESTS "tests/*.cpp")

add_library(numerical STATIC ${SOURCES})

add_executable(test_all ${TESTS})
target_link_libraries(test_all numerical)

enable_testing()
add_test(NAME NumericalTests COMMAND test_all)