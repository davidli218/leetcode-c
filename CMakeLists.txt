cmake_minimum_required(VERSION 3.16)

project(LeetCode C)

set(CMAKE_C_STANDARD 11)

file(GLOB SUB_DIR_LIST RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)

foreach (SUB_DIR ${SUB_DIR_LIST})
    if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${SUB_DIR}/CMakeLists.txt)
        add_subdirectory(${SUB_DIR})
    endif ()
endforeach ()
