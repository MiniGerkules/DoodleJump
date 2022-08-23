#include <stdio.h>
#include <string.h>
#include "Console.h"

static const char *resetEffects = "\e[0m";

void ChangeBgColor(const Colors newColor) {
    char changer[] = "\e[4?m";

    changer[3] = 48 + newColor; // 48 == '0'

    printf("%s", changer);
}

void ChangeSymColor(const Colors newColor, const Intensities newIntensity) {
    char changer[] = "\e[3?;?m";

    changer[3] = 48 + newColor; // 48 == '0'
    changer[5] = 48 + newIntensity;

    printf("%s", changer);
}
