#include <stdbool.h>
#include <signal.h>
#include <string.h>
#include "Game.h"

bool set_signals_handlers(void);

int main(void) {
    set_signals_handlers();

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

    sigaction(SIGINT, &act, 0);
    sigaction(SIGTERM, &act, 0);
}
