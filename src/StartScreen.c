#include "../inc/LIB_FUN.h"

void startscreen()
{   

    //char ** mas = (char**)malloc(sizeof(char*) * 14);

    char ** start = (char**)malloc(sizeof(char*) * 14);

    
    start[0] = "##########################################################################################################";
    start[1] = "##########################################################################################################";
    start[2] = "########~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~########";
    start[3] = "######### ====================================================================================== #########";
    start[4] = "######### =   LL         AAA    BBBBB    Y    Y   RRRRR    II   NNN   NN   TTTTTTTT   HH   HH  = #########";
    start[5] = "######### =   LL       AA   A   BB   B    Y  Y    RR   R   II   NN N  NN      TT      HH   HH  = #########";
    start[6] = "######### =   LL       AAaaaA   BBBBB      YY     RRrrR    II   NN  N NN      TT      HHHHHHH  = #########";
    start[7] = "######### =   LL       AA   A   BB   B     YY     RR  R    II   NN  N NN      TT      HH   HH  = #########";
    start[8] = "######### =   LLLLLL   AA   A   BBBBB      YY     RR   R   II   NN   NNN      TT      HH   HH  = #########";
    start[9] = "######### ====================================================================================== #########";
    start[10] = "########~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~########";
    start[11] = "##########################################################################################################";
    start[12] = "################################          PRESS ENTER          ###########################################";
    start[13] = "##########################################################################################################";


    int c = 5, mas_c = 0;

    while( c != 19 )  
    {
        mvprintw(c, 3, start[mas_c]);
        c++;
        mas_c++;
    }

    refresh();

    int key = 0;

    while ( key != K_ENTER )
    {
        key = getchar();
    }

    free(start);
    start = NULL;

    clear();
    
    
}
/*













##########################################################################################################
##########################################################################################################
########~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~########
######### ====================================================================================== #########                                                                    
######### =   LL         AAA    BBBBB    Y    Y   RRRRR    II   NNN   NN   TTTTTTTT   HH   HH  = #########
######### =   LL       AA   A   BB   B    Y  Y    RR   R   II   NN N  NN      TT      HH   HH  = #########
######### =   LL       AAaaaA   BBBBB      YY     RRrrR    II   NN  N NN      TT      HHHHHHH  = #########
######### =   LL       AA   A   BB   B     YY     RR  R    II   NN  N NN      TT      HH   HH  = #########
######### =   LLLLLL   AA   A   BBBBB      YY     RR   R   II   NN   NNN      TT      HH   HH  = #########
######### ====================================================================================== #########
########~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~########
##########################################################################################################
##########################################################################################################
##########################################################################################################
    */ 
