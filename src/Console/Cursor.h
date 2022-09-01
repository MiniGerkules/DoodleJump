#pragma once
#include "Console.h"


void set_cursor(const ushort newRow, const ushort newColumn);
void move_cursor(const short rowBias, const short columnBias);

void hide_cursor(void);
void show_cursor(void);
