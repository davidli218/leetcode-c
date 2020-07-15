cmake_minimum_required(VERSION 3.16)
project(Unique_Binary_Search_Trees C)

set(CMAKE_C_STANDARD 11)

aux_source_directory(. DIR_SRCS)

add_executable(Unique_Binary_Search_Trees ${DIR_SRCS})