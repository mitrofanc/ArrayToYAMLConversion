cmake_minimum_required(VERSION 3.28)
project(lab1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fsanitize=address,undefined")
add_executable(lab1 main.cpp
        lab1_conversion.cpp
        lab1_conversion.h
        lab1_dialog.cpp
        lab1_dialog.h
        utils.cpp
        utils.h)
