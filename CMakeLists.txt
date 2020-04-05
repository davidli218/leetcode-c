cmake_minimum_required(VERSION 3.16)
project(leetcode C)

set(CMAKE_C_STANDARD 11)

add_executable(leetcode main.c main.h
        "1. Two Sum.c" "1. Two Sum.h"
        "42. Trapping Rain Water.c" "42. Trapping Rain Water.h"
        "11. Container With Most Water.c" "11. Container With Most Water.h")