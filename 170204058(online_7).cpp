#include <bits/stdc++.h>
using namespace std;

#define INF 9999999
int dist[100][100],V;

void floydWarshall ()
{
	 int i, j, k;


	for (k = 1; k <= V; k++)
	{
		for (i = 1; i <=V; i++)
		{
			for (j = 1; j <= V; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	//printSolution(dist);
}


int main()
{

    int m,x,y;
    cin>>V>>m;
    for (int i = 1; i <= V; i++)
	{
		for (int j = 1 ;j <= V; j++)
		{
			if(i==j)
                dist[i][j] = 0;
            else dist[i][j] = INF;
		}

	}
    for(int i= 0; i<m;i++)
    {
        cin>>x>>y;
        dist[x][y] = 1;
    }
    int sum=0,cnt =V*V-V;
	floydWarshall();
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			sum+=dist[i][j];
			//cout<<dist[i][j]<<" ";
		}
		//cout<<endl;

	}
	cout<<sum/(cnt*1.0)<<endl;
	return 0;
}


