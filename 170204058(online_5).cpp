#include<bits/stdc++.h>
#define n 3
#define amount 6
#define max 999
void display(int arr[amount+1]);
void Change(int d[n+1], int c[amount+1], int s[amount+1]);
void Set(int d[n+1], int s[amount+1]);
//int n=3, amount=6;
int main()
{

    int d[n+1] = {0,1,3,4};
    int c[amount+1];
    int s[amount+1];

    Change(d, c, s);
    printf("\n c[p]\n");
    display(c);

    printf("\n s[p]\n");
    display(s);

    printf("\nMinimum number of coins required to make change for amount %d --> %d\n", amount, c[amount]);

    printf("\nSet of Coins\n");
    Set(d, s);

    return 0;
}

void Change(int d[n+1], int c[amount+1], int s[amount+1])
{
    int i, p, min, coin;

    c[0]=0;
    s[0]=0;

    for(p=1; p<=amount; p++)
    {
        min = max;
        for(i=1; i<=n; i++)
        {
            if(d[i] <= p)
            {
                if(1 + c[p - d[i]] < min)
                {
                    min = 1 + c[p - d[i]];
                    coin = i;
                }
            }
        }
        c[p] = min;
        s[p] = coin;
    }
}

void Set(int d[n+1], int s[amount+1])
{
    int x = amount;
    while(x > 0)
    {
        printf("\nUse of coin : %d\n", d[s[x]]);
        x = x - d[s[x]];
    }
}

void display(int arr[amount+1])
{
    int y;
    for(y=0; y<=amount; y++)
    {
        printf("%3d", arr[y]);
    }
    printf("\n");
}
