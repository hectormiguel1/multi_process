cmake_minimum_required(VERSION 3.15)
project(multi_process C)

set(CMAKE_C_STANDARD 99)

add_executable(multi_process main.c LinkedList.c LinkedList.h)