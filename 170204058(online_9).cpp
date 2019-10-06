#include<bits/stdc++.h>
using namespace std;
const int MAX = INT_MAX;
int rep[100000];
vector<int>va;
int edg;
int a[100000];
struct edge
{
    int a, b , c;
} arr[100000];

bool cmp( edge x, edge y )
{
    return x.c < y.c;
}

void makeset(int n)
{
    for(int i=1; i<=n; i++)
        rep[i]=i;
}

int findr( int x )
{
    if( rep[x] == x )
        return x;
    return rep[x] = findr( rep[x] );
}

int unio(int i,int sum)
{
    int x,y;
    x = findr( arr[i].a );
    y = findr( arr[i].b );
    if( x != y )
    {
        rep[x] = y;
        va.push_back(i);
        sum += arr[i].c;
    }
    return sum;
    if(x==y){cout<< "Cycle detected!\n";}

}

int unio2(int i,int sum)
{
    int x,y;
    x = findr( arr[i].a );
    y = findr( arr[i].b );
    if( x != y )
    {
        rep[x] = y;
        sum += arr[i].c;
        edg++;
    }
    return sum;
    if(x==y){cout<< "Cycle detected!\n";}

}

int main()
{
    int n , m;
    cin >> n >> m;

    makeset(n);

    for( int i = 0; i < m; i++ )
    {
        int a, b, c ;
        cin >> a >> b >> c;
        arr[i].a = a;
        arr[i].b = b;
        arr[i].c = c;
    }

    sort( arr, arr+m , cmp );

    int sum=0;
    for(int i=0; i<m; i++)
    {
        sum=unio(i,sum);
    }

    int sec_best_mst=INT_MAX/3;

    sum=0;
    int j;
    for(j=0; j<va.size(); j++)
    {
        makeset(n);
        edg=0;
        for(int i=0; i<m; i++)
        {
            if(i==va[j])
                continue;
            sum=unio2(i,sum);
        }
        if(edg!=n-1)
        {
            sum=0;
            continue;
        }
        if(sec_best_mst>sum)
            sec_best_mst = sum;
        sum=0;
    }
    if(va[j]== MAX){
        cout<<"NO";
    }else{
    cout<<"YES -->"<<sec_best_mst<<"\n";
    }

}

