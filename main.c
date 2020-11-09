#include <stdio.h>
#include <stdlib.h>
#include "define.h"

int main()
{   char board[N][N];
    char player[2] = {'X', 'O'};
    int victoria = 0;

    initiate(board);
    print(board);
}