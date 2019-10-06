#include<bits/stdc++.h>
int max(int a, int b);
int i,j,m,n,c[20][20];
char x[20],y[20],b[20][20];

int max(int a, int b)
{
    return (a > b)? a : b;
}

void print(int i,int j)
{
    if(i==0 || j==0)
        return;
    if(b[i][j]=='c')
    {
        print(i-1,j-1);
        printf("%c",x[i-1]);
    }
    else if(b[i][j]=='u')
        print(i-1,j);
    else
        print(i,j-1);
}

void lcs()
{
    m=strlen(x);
    n=strlen(y);
    for(i=0; i<=m; i++)
        c[i][0]=0;
    for(i=0; i<=n; i++)
        c[0][i]=0;

    //c, u and l denotes cross, upward and downward directions respectively
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
void length()
{
    int XLen = strlen(x);
    int YLen = strlen(y);

    int L[XLen + 1][YLen + 1];
    int r, c, i;

    /*
     * find the length of the LCS
     */
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
    printf("Enter 1st sequence:");
    scanf("%s",x);
    printf("Enter 2nd sequence:");
    scanf("%s",y);
    printf("\nThe Longest Common Subsequence is : ");
    lcs();
    print(m,n);
    length();
    return 0;
}
