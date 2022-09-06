#include "../inc/LIB_FUN.h"

char level_1()
{
    char **labytinth = (char **)malloc(sizeof(char *) * 24);

    labytinth[0] = "#######################################################################################";
    labytinth[1] = "#######################################################################################";
    labytinth[2] = "##           #                       #           #                       #  K  #    =||";
    labytinth[3] = "##           #                       #           #                       #     #    =||";
    labytinth[4] = "##     #     #     #############     #     #     #     #############     #     #     ##";
    labytinth[5] = "##     #     #     #           #           #           #           #           #     ##";
    labytinth[6] = "##     #  k  #     #           #           #           #           #           #     ##";
    labytinth[7] = "##     #######     #     #     #########################     #     #############     ##";
    labytinth[8] = "##     #           #     #     #                             #     #           #     ##";
    labytinth[9] = "##     #           #     #     #                             #     #           #     ##";
    labytinth[10] = "##     #     #######     #     #######     #######     #############     #     #     ##";
    labytinth[11] = "##                       #           #     #                             #     #     ##";
    labytinth[12] = "##                       #           #     #                             #     #     ##";
    labytinth[13] = "################################     #     #     #########################     #     ##";
    labytinth[14] = "##                 #           #           #           #                       #     ##";
    labytinth[15] = "##                 #           #           #           #                       #     ##";
    labytinth[16] = "##     #######     #     #     #     ###################     ###################     ##";
    labytinth[17] = "##           #     #     #                 #           #     #                 #     ##";
    labytinth[18] = "##           #     #     #                 #           #     #                 #     ##";
    labytinth[19] = "########     #     #     #     #######     #     #######     #######     #     #     ##";
    labytinth[20] = "#            #           #     #           #                             #           ##";
    labytinth[21] = "#            #           #     #           #                             #           ##";
    labytinth[22] = "#######################################################################################";
    labytinth[23] = "#######################################################################################";

    char player = 'P';

    int y_P = 21;
    int x_P = 2;
    int i = 2;
    int gc;
    bool ex1t = false;

    mvprintw(0, 0, labytinth[0]);
    mvprintw(1, 0, labytinth[1]);
    while (i != 22)
    {
        mvprintw(i, 0, "%c", labytinth[i][0]);
        mvprintw(i, 1, "%c", labytinth[i][1]);
        mvprintw(i, 85, "%c", labytinth[i][85]);
        mvprintw(i, 86, "%c", labytinth[i][86]);
        i++;
    }
    mvprintw(22, 0, labytinth[22]);
    mvprintw(23, 0, labytinth[23]);
    refresh();

    while (true)
    {
        int yup = y_P - 4;
        int ydown = y_P + 4;
        int xleft = x_P - 7;
        int xrigth = x_P + 7;

        while (yup <= ydown)
        {
            if (yup < 2)
            {
                yup = 2;
            }
            if (ydown >= 22)
            {
                ydown = 21;
            }
            if (xleft < 2)
            {
                xleft = 2;
            }
            if (xrigth >= 85)
            {
                xrigth = 84;
            }

            while (xleft <= xrigth)
            {
                mvprintw(yup, xleft, "%c", ' ');
                xleft++;
            }

            xleft = x_P - 7;
            yup++;
        }

        int y_up = y_P - 3;
        int y_down = y_P + 3;
        int x_left = x_P - 6;
        int x_rigth = x_P + 6;

        while (y_up < y_down)
        {
            if (y_up < 0)
            {
                y_up = 0;
            }
            if (y_down > 23)
            {
                y_down = 23;
            }
            if (x_left >= 0) // условие когда значения в допустимых границах
            {

                while (x_left <= x_rigth && x_rigth <= 86)
                {
                    mvprintw(y_up, x_left, "%c", labytinth[y_up][x_left]);
                    x_left++;
                }
            }
            if (x_left < 0) // условия когда границы сдвинуты влево
            {
                x_left = 0;

                while (x_left < x_rigth && x_rigth <= 86)
                {
                    mvprintw(y_up, x_left, "%c", labytinth[y_up][x_left]);
                    x_left++;
                }
            }
            if (86 < x_rigth) // условия когда границы сдвинуты вправо.
            {
                x_rigth = 86;

                while (x_left <= x_rigth)
                {
                    mvprintw(y_up, x_left, "%c", labytinth[y_up][x_left]);
                    x_left++;
                }
            }
            x_left = x_P - 6;
            y_up++;
        }

        mvprintw(y_P, x_P, "%c", player);
        refresh();

        gc = getchar();

        switch (gc)
        {
        case K_UP:
            if (labytinth[y_P - 1][x_P] != '#')
            {
                y_P--;
                break;
            }
            else
                continue;

        case K_DOWN:
            if (labytinth[y_P + 1][x_P] != '#')
            {
                y_P++;
                break;
            }
            else
                continue;

        case K_LEFT:
            if (labytinth[y_P][x_P - 1] != '#')
            {
                x_P--;
                break;
            }
            else
                continue;

        case K_RIGTH:
            if (labytinth[y_P][x_P + 1] != '#' && labytinth[y_P][x_P + 1] != '|')
            {
                x_P++;
                break;
            }
            else
                continue;

        case K_ENTER:
            if (labytinth[y_P][x_P] == 'K')
            {
                ex1t = true;
            }
            if (ex1t == true)
            {
                if (labytinth[y_P][x_P] == '=')
                {
                    free(labytinth);
                    labytinth = NULL;
                    clear();
                    return 'W';
                }
            }
        }

        refresh();

        if (gc == 'e')
        {
            clear();
            return 'e';
        }
    }
}
