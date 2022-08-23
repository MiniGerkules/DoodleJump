#pragma once

typedef enum {
    BLACK = 0, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE
} Colors;

typedef enum {
    BRIGHT = 1, NORMAL
} Intensities;

void ChangeBgColor(const Colors newColor);
void ChangeSymColor(const Colors newColor, const Intensities newIntensity);
