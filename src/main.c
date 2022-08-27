#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

#include "Game.h"
#include "Console.h"

bool set_signals_handlers(void);
void terminate_program(const char *msg);

int main(void) {
    if (!set_signals_handlers())
        terminate_program("ERROR! Can't set signals handlers!");
    else if (!all_right_with_console())
        terminate_program("ERROR! Can't get the size of console!");

    return 0;
}

bool set_signals_handlers(void) {
    sigset_t blocked;
    sigemptyset(&blocked);
    sigaddset(&blocked, SIGINT);
    sigaddset(&blocked, SIGTERM);

    struct sigaction act;
    memset(&act, 0, sizeof(act));
    act.sa_handler = stop_the_game;
    act.sa_mask = blocked;

    bool setted = true;
    setted = setted && !sigaction(SIGINT, &act, 0);
    setted = setted && !sigaction(SIGTERM, &act, 0);

    return setted;
}

void terminate_program(const char *msg) {
    change_sym_color(RED, BRIGHT);
    puts(msg);
    exit(EXIT_FAILURE);
}
