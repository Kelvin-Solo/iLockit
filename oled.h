#pragma once

void oled_init(void);

void clear_screen(void);

void oled_display(int X, int Y, int size, char text[10]);
