#ifndef LIB_FUN
#define LIB_FUN

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define K_ENTER 13
#define K_UP 65
#define K_DOWN 66
#define K_LEFT 68
#define K_RIGTH 67
#define K_SPACE 32
#define K_ESC 27

void startscreen();
int menu();
void print_dev();
void print_des();
char level_1();
void endingscr();

#endif
