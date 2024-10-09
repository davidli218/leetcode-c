cmake_minimum_required(VERSION 3.16)

project(LeetCode C)

set(CMAKE_C_STANDARD 11)

file(GLOB SUBDIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "[0-9]*/CMakeLists.txt")

foreach (FILE_PATH ${SUBDIRS})
    get_filename_component(DIR ${FILE_PATH} DIRECTORY)
    add_subdirectory(${DIR})
endforeach ()
