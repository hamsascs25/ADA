#include <stdio.h>
#define MAX 20
int board[MAX][MAX];
int N;
int isSafe(int row, int col)
{
    int i, j;
    for(i = 0; i < col; i++)
    {
        if(board[row][i] == 1)
            return 0;
    }
    for(i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if(board[i][j] == 1)
            return 0;
    }
    for(i = row, j = col; i < N && j >= 0; i++, j--)
    {
        if(board[i][j] == 1)
            return 0;
    }
    return 1;
}

int solveNQueens(int col)
{
    int i;
    if(col >= N)
        return 1;
    for(i = 0; i < N; i++)
    {
        if(isSafe(i, col))
        {
            board[i][col] = 1;
            if(solveNQueens(col + 1))
                return 1;
            board[i][col] = 0;
        }
    }
    return 0;
}
void printBoard()
{
    int i, j;
    printf("\nSolution Exists:\n\n");
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(board[i][j] == 1)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}
int main()
{
    int i, j;
    printf("Enter value of N: ");
    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }
    if(solveNQueens(0))
    {
        printBoard();
    }
    else
    {
        printf("No Solution Exists\n");
    }

    return 0;
}
