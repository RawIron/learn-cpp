cmake_minimum_required(VERSION 3.3)

project("gotchas")

set(CMAKE_CXX_STANDARD 11)

find_package(Boost COMPONENTS REQUIRED unit_test_framework)
IF (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif()


set(gotchas_SOURCES run_tests.cpp
    add_f.cpp)

add_executable(run_tests ${gotchas_SOURCES})
target_link_libraries(run_tests boost_unit_test_framework)


enable_testing()
add_test(NAME overloading_1
         COMMAND run_tests --run_test=overloading/is_double)
add_test(NAME overloading_2
         COMMAND run_tests --run_test=overloading/is_long)
