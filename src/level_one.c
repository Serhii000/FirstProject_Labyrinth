#include "../inc/LIB_FUN.h"

void fog(int y, int x)
{
    int yup_fog = y - 4; // limited visibility implementation | реализация ограничения видимости
    int ydown_fog = y + 4;
    int xleft_fog = x - 7;
    int xrigth_fog = x + 7;

    while (yup_fog <= ydown_fog)
    {
        if (yup_fog < 2)
            yup_fog = 2;

        if (ydown_fog >= 22)
            ydown_fog = 21;

        if (xleft_fog < 2)
            xleft_fog = 2;

        if (xrigth_fog >= 85)
            xrigth_fog = 84;

        while (xleft_fog <= xrigth_fog)
        {
            mvprintw(yup_fog, xleft_fog, "%c", ' ');
            xleft_fog++;
        }

        xleft_fog = x - 7;
        yup_fog++;
    }
}
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
        fog(y_P, x_P);

        int y_up = y_P - 3;
        int y_down = y_P + 3;
        int x_left = x_P - 6;
        int x_rigth = x_P + 6;

        while (y_up < y_down)
        {
            if (y_up < 0)
                y_up = 0;

            if (y_down > 23)
                y_down = 23;

            if (x_left >= 0) // condition when values are within acceptable limits | условие когда значения в допустимых границах
            {

                while (x_left <= x_rigth && x_rigth <= 86)
                {
                    mvprintw(y_up, x_left, "%c", labytinth[y_up][x_left]);
                    x_left++;
                }
            }
            if (x_left < 0) // conditions when the borders are shifted to the left | условия когда границы сдвинуты влево
            {
                x_left = 0;

                while (x_left < x_rigth && x_rigth <= 86)
                {
                    mvprintw(y_up, x_left, "%c", labytinth[y_up][x_left]);
                    x_left++;
                }
            }
            if (86 < x_rigth) // conditions when the borders are shifted to the right | условия когда границы сдвинуты вправо.
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
                ex1t = true;

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
