cmake_minimum_required(VERSION 3.16)
project(LeetCode C)

set(CMAKE_C_STANDARD 11)
set(IGNORE_LIST cmake-build-debug CMakeLists.txt README.md)

execute_process(
        COMMAND ls ${PROJECT_SOURCE_DIR}
        OUTPUT_VARIABLE ROOT_LIST)

string(REPLACE "\n" ";" “SUB_DIRS” ”${ROOT_LIST}“)

foreach (DIR ${SUB_DIRS})
    list(FIND IGNORE_LIST ${DIR} FLAG)
    if (FLAG EQUAL -1)
        add_subdirectory(${PROJECT_SOURCE_DIR}/${DIR})
    endif ()
endforeach ()