#include "../inc/LIB_FUN.h"

void print_des()
{
    mvprintw(3, 5, "Hello lost soul! The Labyrinth welcomes you!");
    mvprintw(5, 3, "This is a simple game in the terminal.");
    mvprintw(6, 4, "Developed on the basis of the C++ programming language with the ncurses library.");
    mvprintw(8, 3, "Like any other maze, this one is just as confusing and dark.");
    mvprintw(9, 3, "But the rules of the game are simple. Find the key and exit. No more no less ;)");
    mvprintw(10, 3, "I will tell you a little about the buttons:");
    mvprintw(11, 4, "- up: up arrow;");
    mvprintw(12, 4, "- down: down arrow;");
    mvprintw(13, 4, "- right: arrow to the right;");
    mvprintw(14, 4, "- left: arrow to the left;");
    mvprintw(15, 3, "So, movement, as in all normal people.");
    mvprintw(16, 3, "There is also an (Enter) button. After all, we will have to somehow pick up the key and pull the door.");
    mvprintw(18, 3, "And if you get bored, you can always exit the game by pressing the (e) button. (E) is the exit.");
    mvprintw(19, 3, "Of course, in each maze there is a button, thanks to which you can get out of it.");
    mvprintw(20, 3, " It's a labyrinth, suddenly you lose the way out...");
    mvprintw(21, 3, "In general, that's all.");
    mvprintw(23, 3, "I am Petrov Serhiy, the developer of this game, I am happy to present you my first project.");

    refresh();
    getchar();
}
