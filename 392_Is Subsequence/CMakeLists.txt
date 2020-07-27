cmake_minimum_required(VERSION 3.16)
project(Is_Subsequence C)

set(CMAKE_C_STANDARD 11)

aux_source_directory(. DIR_SRCS)

add_executable(Is_Subsequence ${DIR_SRCS})