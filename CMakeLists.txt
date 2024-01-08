cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) #если закомментить эту строку, то ничего не изменится
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        my_test
        my_test.cpp
        quadratic_equation.cpp
        quadratic_equation.h
)
target_link_libraries(
        my_test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(my_test)