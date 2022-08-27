#pragma once
#include <stdbool.h>

typedef enum {
    BLACK = 0, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE
} Colors;

typedef enum {
    BRIGHT = 1, NORMAL
} Intensities;

void change_bg_color(const Colors newColor);
void change_sym_color(const Colors newColor, const Intensities newIntensity);
bool all_right_with_console(void);
