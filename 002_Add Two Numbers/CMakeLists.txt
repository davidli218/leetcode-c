cmake_minimum_required(VERSION 3.16)
project(add_two_numbers C)

set(CMAKE_C_STANDARD 11)

aux_source_directory(. DIR_SRCS)

add_executable(${PROJECT_NAME} ${DIR_SRCS})