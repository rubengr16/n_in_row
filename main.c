#include <stdio.h>
#include "define.h"

int main()
{   char board[N][N];
    char player[2] = {'X', 'O'};

    int round = -1;

    printf("\nWelcome to %d in Row. Let's play!!", N);
    initiate(board);
    print(board);
    do
    {
        print_separator();
        round++;
        printf("\nRound: %d. %c's Turn", round / 2, player[round % 2]);
        if(round / 2 < N)
            set_token(board, player[round % 2]);
        else
            move_token(board, player[round % 2]);
        print(board);
    }while(!victory(board, player[round % 2]));
    print_separator();
    printf("\n%d. %c wins!!",round / 2, player[round % 2]);

    return 0;
}