file(GLOB SOURCES "*.c")

get_filename_component(DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE "_" "-" TARGET_NAME ${DIR_NAME})

add_executable(${TARGET_NAME} ${SOURCES})
