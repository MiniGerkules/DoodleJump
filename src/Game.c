#include <signal.h>
#include "Game.h"

void stop_the_game(int signal) {
    if (signal != SIGTERM || signal != SIGINT)
        return;
}
