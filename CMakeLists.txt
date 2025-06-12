cmake_minimum_required(VERSION 3.10)
project(NumericalLibrary)

set(CMAKE_CXX_STANDARD 17)

include_directories(numerical_lib/include)

# Znajdź wszystkie pliki źródłowe biblioteki
file(GLOB SOURCES "numerical_lib/src/*.cpp")

# Utwórz bibliotekę statyczną
add_library(numerical STATIC ${SOURCES})

# Znajdź wszystkie pliki testów
file(GLOB TEST_FILES "numerical_lib/tests/test_*.cpp")

# Utwórz osobny program wykonywalny dla każdego testu
foreach(TEST_FILE ${TEST_FILES})
    # Pobierz nazwę pliku bez ścieżki i rozszerzenia
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
    
    # Utwórz program wykonywalny dla tego testu
    add_executable(${TEST_NAME} ${TEST_FILE})
    
    # Linkuj z biblioteką
    target_link_libraries(${TEST_NAME} numerical)
    
    # Dodaj do testów CTest
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()

# Włącz testowanie
enable_testing()

add_executable(example_interpolation numerical_lib/examples/example_interpolation.cpp)
target_link_libraries(example_interpolation numerical)

add_executable(example_linear_systems numerical_lib/examples/example_linear_systems.cpp)
target_link_libraries(example_linear_systems numerical)
