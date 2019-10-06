#include<bits/stdc++.h>
char X[20],Y[20];
int max(int a, int b);
void findLCS(char *X, char *Y, int XLen, int YLen);

int max(int a, int b)
{
    return (a > b)? a : b;
}

void findLCS(char *X, char *Y, int XLen, int YLen)
{
    int L[XLen + 1][YLen + 1];
    int x, y, i;

    /*
     * find the length of the LCS
     */
    for(x = 0; x <= XLen; x++)
    {

        for(y = 0; y <= YLen; y++)
        {

            if(x == 0 || y == 0)
            {

                L[x][y] = 0;

            }
            else if(X[x - 1] == Y[y - 1])
            {

                L[x][y] = L[x - 1][y - 1] + 1;

            }
            else
            {

                L[x][y] = max(L[x - 1][y], L[x][y - 1]);
            }
        }
    }

    /*
     * Print LCS
     */
    x = XLen;
    y = YLen;
    i = L[x][y];

    char LCS[i+1];

    /*
     * setting the NULL character at the end of LCS character array.
     * as we know in C programming language, NULL character is used
     * to denote the end of a string
     */
    LCS[i] = '\0';

    while(x > 0 && y > 0)
    {

        if(X[x - 1] == Y[y - 1])
        {

            LCS[i - 1] = X[x - 1];

            i--;
            x--;
            y--;

        }
        else if(L[x - 1][y] > L[x][y - 1])
        {

            x--;

        }
        else
        {

            y--;

        }

    }

    //print result
    printf("Length of the LCS: %d\n", L[XLen][YLen]);
    printf("LCS: %s\n", LCS);
}

int main(void)
{
    //the two sequences
    printf("Enter 1st sequence:");
    scanf("%s",X);
    printf("Enter 2nd sequence:");
    scanf("%s",Y);

    //length of the sequences
    int XLen = strlen(X);
    int YLen = strlen(Y);

    findLCS(X, Y, XLen, YLen);

    return 0;
}
