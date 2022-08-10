#include "inc/LIB_FUN.h"

int main()
{

    initscr();

    int y, x;
    getmaxyx(stdscr, y, x);

    if ( y < 25 || x < 110 )
    {
      endwin();
      printf("!!!!!!!!!!!!!!!!!!!!!!!!!!\n!!!TERMINAL IS TO SMALL!!!\n!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
      return 0;
    }

    curs_set(0);

    startscreen();

    menu();
    

    endwin();

    return 0;
}
