cmake_minimum_required(VERSION 3.10)
project(DoodleJump LANGUAGES C)

set(HEADERS
    src/Console.h
    src/Doodle.h
    src/Game.h
)
set(SOURCES
    src/Console.c
    src/Doodle.c
    src/Game.c
    src/main.c
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
