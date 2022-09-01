#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cursor.h"


typedef struct {
    ushort row;
    ushort column;
} Cursor;

static Cursor cursor = { 0, 0 };


static ushort min(const ushort first, const ushort second) {
    return first < second ? first : second;
}


void set_cursor(const ushort newRow, const ushort newColumn) {
    cursor.row = min(newRow, console_size.rowsNum);
    cursor.column = min(newColumn, console_size.colsNum);

    printf("%s%hu%c%hu%c", "\x1b[", cursor.row, ';', cursor.column, 'H');
}

void move_cursor(const short rowBias, const short columnBias) {
    if (rowBias < 0)
        printf("%s%d%c", "\x1b[", -rowBias, 'A');
    else if (rowBias > 0)
        printf("%s%hd%c", "\x1b[", rowBias, 'B');

    if (columnBias > 0)
        printf("%s%hd%c", "\x1b[", columnBias, 'C');
    else if (columnBias < 0)
        printf("%s%d%c", "\x1b[", -columnBias, 'D');
}

void hide_cursor(void) {
    printf("\x1b[?25l");
}

void show_cursor(void) {
    printf("\x1b[?25h");
}
