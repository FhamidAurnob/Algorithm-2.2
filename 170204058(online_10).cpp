#include<bits/stdc++.h>
using namespace std;
int i,j,m,n;

int max(int a, int b)
{
    return (a > b)? a : b;
}
void lcs(char* x,char*y,int size)
{
    m=strlen(x);
    n=strlen(y);
    int c[size][size];
    char b[size][size];
    for(i=0; i<=m; i++)
        c[i][0]=0;
    for(i=0; i<=n; i++)
        c[0][i]=0;

    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
        {
            if(x[i-1]==y[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='c';
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]='u';
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]='l';
            }
        }
}
void length(char* x,char*y)
{
    int XLen = strlen(x);
    int YLen = strlen(y);

    int L[XLen + 1][YLen + 1];
    int r, c, i;


    for(r = 0; r <= XLen; r++)
    {

        for(c = 0; c <= YLen; c++)
        {

            if(r == 0 || c == 0)
            {

                L[r][c] = 0;

            }
            else if(x[r - 1] == y[c - 1])
            {

                L[r][c] = L[r - 1][c - 1] + 1;

            }
            else
            {

                L[r][c] = max(L[r - 1][c], L[r][c - 1]);
            }
        }
    }
    printf("\nLength of the LCS: %d\n", L[XLen][YLen]);

}
int main()
{
    int size;
    printf("Enter size: ");
    scanf("%d",&size);
    char x[size],y[size];
    int c[size][size];
    printf("Enter 1st sequence:");
    scanf("%s",x);
    printf("Enter 2nd sequence:");
    scanf("%s",y);
    lcs(x,y,size);
    length(x,y);
    return 0;
}

