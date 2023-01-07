cmake_minimum_required(VERSION 3.10)
project(DoodleJump LANGUAGES C)

set(HEADERS
    src/Console/MainOptions.h
    src/Console/Cursor.h
    src/Console/UserInput.c
    # src/Doodle.h
    # src/Game.h
)
set(SOURCES
    src/Console/MainOptions.c
    src/Console/Cursor.c
    src/Console/UserInput.c
    # src/Doodle.c
    # src/Game.c
    src/main.c
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
