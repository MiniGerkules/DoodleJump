#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

#include "Game.h"
#include "Console/MainOptions.h"

void terminate_program(const char *msg);

int main(void) {
    if (!set_console_sizes())
        terminate_program("ERROR! Can't get the size of console!");

    return EXIT_SUCCESS;
}

void terminate_program(const char *msg) {
    change_sym_color(RED, BRIGHT);
    puts(msg);
    exit(EXIT_FAILURE);
}
