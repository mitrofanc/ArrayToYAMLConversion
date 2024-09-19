cmake_minimum_required(VERSION 3.28)
project(lab1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g -fsanitize=address,undefined")
#add_executable(lab1 main.cpp
#        lab1_conversion.cpp
#        lab1_conversion.h
#        lab1_dialog.cpp
#        lab1_dialog.h
#        utils.cpp
#        utils.h)

add_library(utils utils.h utils.cpp)
add_library(conversion lab1_conversion.h lab1_conversion.cpp)
add_library(dialog lab1_dialog.h lab1_dialog.cpp)

link_libraries(utils conversion dialog)
add_executable(main main.cpp)