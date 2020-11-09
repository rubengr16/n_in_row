#include <stdio.h>
#include <stdlib.h>
#include "define.h"


void initiate(char board[N][N])
{   int i; //variables to control the matrix
    int j;

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            board[i][j] = '-'; //set - as empty square
}

void print(char board[N][N])
{   int i;
    int j;

    for(i = 0; i < N; i++)
    {   for (j = 0; j < N; j++)
            printf(" %c ", board[i][j]); //prints
        printf("\n"); //new line after printing all the columns of the file line
    }
}

int victory(char board[N][N], char token)
{
    int i;
    int j;
    int count = 0;

    for(i = 0; i < N && count < N; i++) //N in row in horizontal
    {
        count = 0;
        for(j = 0; board[i][j] == token && j < N; j++)
            count++;
    }


    for(i = 0; i < N && count < N; i++) //N in row in vertical
    {
        count = 0;
        for(j = 0; board[j][i] == token && j < N; j++)
            count++;
    }

    if(count < N)
        count = 0;
    for(i = 0; board[i][i] == token && i < N && count < N; i++); //in antidiagonal ((0,0), (1,1)..., (N,N))

    if(count < N)
        count = 0;
    for(i = 0, j = N; board[i][j] == token && i < N && j > 0 && count < N; i++, j++); //main diagonal((0,N)...(N,0))

    return count == N ? 1 : 0;
}

