cmake_minimum_required(VERSION 3.3)

project("gotchas")

set(CMAKE_CXX_STANDARD 11)

find_package(Boost COMPONENTS REQUIRED unit_test_framework)
IF (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif()

set(gotchas_SOURCES run_tests.cpp
    add_f.cpp)

add_executable(run_add_test ${gotchas_SOURCES})
target_link_libraries(run_add_test boost_unit_test_framework)

enable_testing()
add_test(add_tests run_add_test)
