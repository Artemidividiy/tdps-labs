cmake_minimum_required(VERSION 3.21)
project(labs)

set(CMAKE_CXX_STANDARD 20)

add_executable(labs main.cpp lab1/Table.cpp lab1/Table.h lab1/Element.cpp lab1/Element.h lab2/Drawer.cpp lab2/Drawer.h lab3/Solution.cpp lab3/Solution.h)
