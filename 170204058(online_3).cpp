#include<bits/stdc++.h>
int color,edge,i,j,x,y,n, front = -1, rear = -1;
int mat[100][100], a[100];
int main()
{
    int color,edge,i,j,x,y,n, front = -1, rear = -1;
    int mat[100][100], a[100];
    printf("\nEnter number of nodes: ");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        scanf("%d", &color);
    }
    // printf("\nEnter number of edges : ");
    // scanf("%d", &edge);
    for(i=1; i<=n-1; i++)
    {
        scanf("%d", &x);
        scanf("%d", &y);
        mat[x][y] = 1;
        mat[y][x] = 1;
    }
    if(color == 0)
    {

    }
}

struct vertex
{
    int color;
    int parent;
    int d;
    vertex()
    {
        color = 0;
        parent = -1;
        d = 2*pow(10, 13);
    }
};
vertex branch[100];
void push(int val)
{
    if(front==-1)
        front = 0;
    rear++;
    a[rear] = val;
}
void pop()
{
    if(front==-1 || front>rear)
        return;
    front++;
}
int top()
{
    return a[front];
}
bool isEmpty()
{
    if(front==-1 || front>rear)
        return true;
    return false;
}
void bfs(int u)
{
    push(u);
    branch[u].color = 1;
    branch[u].d = 0;
    branch[u].parent = -1;
    while(!isEmpty())
    {
        int v = top();
        pop();
        for(i=1; i<=n; i++)
        {
            if(mat[v][i]==1)
            {
                if(branch[i].color==0)
                {
                    branch[i].color = 1;
                    branch[i].d = branch[v].d+1;
                    branch[i].parent = v;
                    push(i);
                }
            }
        }
        branch[v].color = 2;
    }
}
