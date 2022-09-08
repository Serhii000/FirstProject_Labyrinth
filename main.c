#include "inc/LIB_FUN.h"

int main()
{
	int menu_ret;
	char lvl_ret;
	int y, x;

	initscr();
	getmaxyx(stdscr, y, x);

	if (y < 25 || x < 110)
	{
		endwin();
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!\n!!!TERMINAL IS TO SMALL!!!\n!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		return 0;
	}

	curs_set(0);
	startscreen();
	menu_ret = menu();
	if (menu_ret == 9)
	{
		clear();
		lvl_ret = level_1();
	}

	if (lvl_ret == 'W')
		endingscr();

	endwin();

	return 0;
}
