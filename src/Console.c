#include <stdio.h>
#include <unistd.h>

#include <termios.h>
#include <sys/ioctl.h>

#include "Console.h"


static const char *reset_console_effects = "\e[0m";
static const short UNDEFINED_SIZE = -1;

static short rowsNum = UNDEFINED_SIZE;
static short colsNum = UNDEFINED_SIZE;


void change_bg_color(const Colors newColor) {
    char changer[] = "\e[4?m";

    changer[3] = 48 + newColor; // 48 == '0'

    printf("%s", changer);
}

void change_sym_color(const Colors newColor, const Intensities newIntensity) {
    char changer[] = "\e[3?;?m";

    changer[3] = 48 + newColor; // 48 == '0'
    changer[5] = 48 + newIntensity;

    printf("%s", changer);
}

static void set_sizes_of_teminal(void);
bool all_right_with_console(void) {
    if (rowsNum != UNDEFINED_SIZE || colsNum != UNDEFINED_SIZE)
        set_sizes_of_teminal();

    return rowsNum != UNDEFINED_SIZE && colsNum != UNDEFINED_SIZE;
}


static void set_sizes_of_teminal(void) {
    struct winsize size;

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size)) {
        rowsNum = UNDEFINED_SIZE;
        colsNum = UNDEFINED_SIZE;
    } else {
        rowsNum = size.ws_row;
        colsNum = size.ws_col;
    }
}
