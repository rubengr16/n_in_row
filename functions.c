#include <stdio.h>
#include "define.h"

void print(const char board[N][N]) //because matrix are always passed as pointer
{   int i;
    int j;

    printf("\n |"); //top right corner empty
    for(i = 0; i < N; i++)
        printf("%d|", i + 1); //columns' number

    for(i = 0; i < N; i++)
    {
        printf("\n"); //new line after printing all the columns of the row
        for(j = 0; j < (N + 1) * 2; j++)
            printf("-"); //horizontal separator
        printf("\n%d|", i + 1); //new line for printing new row + row's number
        for (j = 0; j < N; j++)
            printf("%c|", board[i][j]); //prints element + vertical separator
    }
    printf("\n");
    for(j = 0; j < (N + 1) * 2; j++)
        printf("-");
}

void print_separator()
{
    int i;

    printf("\n");
    for(i = 0; i < 80; i++)
        printf("=");
}

void initiate(char board[N][N])
{   int i; //variables to control the matrix
    int j;

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            board[i][j] = EMPTY; //set - as empty square
}

void erase(char board[N][N], char token)
{   int row;
    int column;

    do
    {
        printf("\nYou are out of tokens, please select one to move: ");
        read_row(&row);
        read_column(&column);
    }while(!is_token(board, row, column, token));
    board[row - 1][column - 1] = EMPTY;
}

void read_row(int *row)
{
    do
    {
        printf("\nEnter a row [1, %d]: ", N);
        scanf("%d", row);
    } while (*row < 1 || *row > N); //test N > row > 1
}                                   //*variable access to value contained on pointer's memory direction

void read_column(int *column)
{
    do
    {
        printf("\nEnter a column [1, %d]: ", N);
        scanf("%d", column);
    } while (*column < 1 || *column > N);
}

int is_token(char board[N][N], int row, int column, char token)
{
    return board[row - 1][column - 1] == token ? 1 : 0;
}

int is_empty(char board[N][N], int row, int column)
{
    return board[row -1][column - 1] == EMPTY ? 1 : 0;
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
    for(i = 0; board[i][i] == token && i < N && count < N; i++) //in antidiagonal ((0,0), (1,1)..., (N - 1,N - 1))
        count++;

    if(count < N)
        count = 0;
    for(i = 0, j = N - 1; board[i][j] == token && i < N && j >= 0 && count < N; i++, j--) //main diagonal((0,N -1)...(N -1,0))
        count++;

    return count == N ? 1 : 0;
}

void set_token(char board[N][N], char token)
{
    int row;
    int column;

    do
    {
        printf("\nPlease select where to set your token: ");
        read_row(&row); //&variable pass pointer to function
        read_column(&column);
    }while(!is_empty(board, row, column));

    board[row - 1][column - 1] = token;
}

void move_token(char board[N][N], char token)
{
    erase(board, token);
    set_token(board, token);
}