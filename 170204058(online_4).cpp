#include<bits/stdc++.h>

int board[20], count=1;

int main()
{
    int n, i ,j;
    void queen(int row, int n);
    printf("Enter number of queens : ");
    scanf("%d", &n);
    queen(1, n);
    return 0;
}
void print(int n)
{
    int i, j;
    printf("\nSolution %d : ", count ++);
    for(i=1; i<=n; i++)
    {
        printf("\n%d", i);
        for(j=1; j<=n; j++)
        {
            if(board[i] == j)
            {
                printf("\t Q");
            }
            else
            {
                printf("\t -");
            }
        }
    }
}
int place(int row, int column)
{
    int i;
    for(i=1; i<=row; i++)
    {
        if(board[i] == column)
            return 0;
        else
        {
            if(abs(board[i] - column) == abs(i - row))
            {
                return 0;
            }
        }
    }
    return 1;
}
void queen(int row, int n)
{
    int column;
    for(column =1; column <=n; column++)
    {
        if(place(row, column))
        {
            board[row] = column;
            if(row == n)
                print(n);
            else
                queen(row+1, n);
        }
    }
}

