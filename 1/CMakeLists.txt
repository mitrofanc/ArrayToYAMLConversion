cmake_minimum_required(VERSION 3.28)
project(lab1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g -fsanitize=address,undefined")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(utils src/utils.cpp)

add_library(conversion src/lab1_conversion.cpp)
target_link_libraries(conversion utils)

add_library(dialog src/lab1_dialog.cpp)
target_link_libraries(dialog utils conversion)

add_executable(lab1 src/main.cpp)
target_link_libraries(lab1 dialog)

enable_testing()

find_package(GTest REQUIRED)

add_executable(tests tests/test.cpp)

target_link_libraries(tests GTest::GTest GTest::Main utils conversion dialog)

add_test(NAME AllTests COMMAND tests)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif()