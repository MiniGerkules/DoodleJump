#include <stdio.h>
#include <unistd.h>

#include <termios.h>
#include <sys/ioctl.h>

#include "Console.h"


static const short UNDEFINED_SIZE = -1;
ConsoleSize console_size = { UNDEFINED_SIZE, UNDEFINED_SIZE };


void change_bg_color(const Colors newColor) {
    char changer[] = "\x1b[4?m";

    changer[3] = '0' + newColor;

    printf("%s", changer);
}

void change_sym_color(const Colors newColor, const Intensities newIntensity) {
    char changer[] = "\x1b[3?;?m";

    changer[3] = '0' + newColor;
    changer[5] = '0' + newIntensity;

    printf("%s", changer);
}

void console_effects_reset(void) {
    printf("\x1b[0m");
}

bool is_console_sizes_valid(void) {
    return console_size.rowsNum != UNDEFINED_SIZE &&
           console_size.colsNum != UNDEFINED_SIZE;
}

static void set_sizes_of_teminal(void);
bool set_console_sizes(void) {
    set_sizes_of_teminal();

    return is_sizes_valid();
}


static void set_sizes_of_teminal(void) {
    struct winsize size;

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size)) {
        console_size.rowsNum = UNDEFINED_SIZE;
        console_size.colsNum = UNDEFINED_SIZE;
    } else {
        console_size.rowsNum = size.ws_row;
        console_size.colsNum = size.ws_col;
    }
}
