#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include "UserInput.h"

static struct termios oldSettings;
static bool isCanonical = true;

static void restore_console_mode(void) {
    tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);
}

static bool have_stdin_data(void) {
    fd_set tracted_streams;
    FD_ZERO(&tracted_streams);
    FD_SET(STDIN_FILENO, &tracted_streams);

    struct timeval tv = {
        .tv_sec = 0, .tv_usec = 0
    };

    return select(STDIN_FILENO + 1, &tracted_streams, NULL, NULL, &tv) > 0;
}

bool prepare_console(void) {
    if (!isatty(STDIN_FILENO)) {
        fputs("Not a terminal.", stderr);
        return false;
    }

    tcgetattr(STDIN_FILENO, &oldSettings);
    if (atexit(restore_console_mode)) {
        fputs("Can't register the program termination handler.", stderr);
        return false;
    }

    struct termios tattr;
    tcgetattr(STDIN_FILENO, &tattr);
    tattr.c_lflag &= ~(ICANON | ECHO);
    tattr.c_cc[VMIN] = 1;
    tattr.c_cc[VTIME] = 0;
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &tattr)) {
        fputs("Can't prepare a terminal to recieve user input.", stderr);
        return false;
    }

    isCanonical = false;
    return true;
}

static UserInput get_extended_input(void) {
    char sym;
    // Errors or 'Esc' button was pressed
    if (!have_stdin_data() || read(STDIN_FILENO, &sym, 1) == -1)
        return STOP_THE_GAME;

    if (sym != 0x5b) {
        return NO_CONTROLE_INPUT;
    } else {
        read(STDIN_FILENO, &sym, 1);
        switch (sym) {
        case 0x44:
            return MOVE_LEFT;
        case 0x43:
            return MOVE_RIGHT;
        default:
            return NO_CONTROLE_INPUT;
        }
    }
}

UserInput get_user_input(void) {
    if (isCanonical)
        return CANT_GET_INPUT;

    char sym;
    if (read(STDIN_FILENO, &sym, 1) == 0)
        return NO_CONTROLE_INPUT;

    printf("%x\n", sym);

    switch (sym) {
    case 'a':
    case 'A':
        return MOVE_LEFT;

    case 'd':
    case 'D':
        return MOVE_RIGHT;

    case 0x1b: // Extended
        return get_extended_input();

    default:
        return NO_CONTROLE_INPUT;
    }
}
