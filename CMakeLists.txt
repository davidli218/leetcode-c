cmake_minimum_required(VERSION 3.16)
project(LeetCode C)

set(CMAKE_C_STANDARD 11)

file(GLOB SUB_DIR_LIST "${CMAKE_CURRENT_SOURCE_DIR}/*[0-9]*")

foreach (DIR ${SUB_DIR_LIST})
    add_subdirectory(${DIR})
endforeach ()