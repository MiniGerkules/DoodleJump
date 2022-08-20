cmake_minimum_required(VERSION 3.10)
project(DoodleJump LANGUAGES C)

set(HEADERS
    src/Doodle.h
)
set(SOURCES
    src/main.c
    src/Doodle.c
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
