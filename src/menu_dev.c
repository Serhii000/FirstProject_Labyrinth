#include "../inc/LIB_FUN.h"

void print_dev()
{
    mvprintw(3, 3, "The team that worked on the project:");
    mvprintw(4, 4, "- Team Lead: Artur Novotarskyi;");
    mvprintw(5, 4, "- Developer: Petrov Serhii;");
    mvprintw(6, 4, "- Level designer: Marushchak Mykyta");
    mvprintw(7, 3, "__________________________________________");
    mvprintw(9, 10, "We tried our best :)");

    refresh();
    getchar(); 
}
