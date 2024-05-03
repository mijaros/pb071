cmake_minimum_required(VERSION 3.5)

project(zapocet)

set(ZAPOCET_SOURCES main.c)
set(CMAKE_C_CFLAGS "-std=c99 -Wall -Wextra -pedantic")
add_executable(${PROJECT_NAME} ${ZAPOCET_SOURCES})
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/libzap.a)
