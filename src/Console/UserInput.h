#pragma once
#include <stdbool.h>


typedef enum {
    CANT_GET_INPUT, NO_CONTROLE_INPUT, MOVE_LEFT, MOVE_RIGHT, STOP_THE_GAME
} UserInput;

bool prepare_console(void);
UserInput get_user_input(void);
