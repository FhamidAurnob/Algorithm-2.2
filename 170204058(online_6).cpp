#include<bits/stdc++.h>
using namespace std;

#define max_edge 1000

struct Edge
{
    int source;
    int destination;
    int weight;
};
Edge E[max_edge];

int v, e, P;

void bellman_ford(int s){
    int dist[v];
    int parent[v];
    for(int i=0; i<v; i++){
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    dist[s] = 0;

    for(int i=1; i<v-1; i++){
        for(int j=0; j<e; j++){

            int u = E[j].source;
            int v = E[j].destination;
            int weight = E[j].weight;

            if(dist[u] + weight < dist[v]){
                    dist[v] = dist[u] + weight;
            }

        }

        for(int j=0; j<e; j++){

            int u = E[j].source;
            int v = E[j].destination;
            int weight = E[j].weight;

            if(dist[u] + weight < dist[v]){
                cout<<"Negative weighted cycle exists! :o ";
                return;
            }
        }

    }

    for (int i = 0; i < v; i++){
        if(dist[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }

}

int main()
{
    cout<<"Enter number of cities: ";
    cin>>v;
    cout<<"Enter number of roads: ";
    cin>>e;
    cout<<"Enter specified profit ratio: ";
    cin>>P;
    cout<<"Enter the starting city, ending city, income, expense (weight)): "<<endl;

    for(int i=0; i<e; i++){
        int m,n,wt;
        cin>>m>>n>>wt;

        E[i].source = m;
        E[i].destination = n;
        E[i].weight = wt;
    }

    cout<<"Enter starting city: ";
    int s;
    cin>>s;

    bellman_ford(s);

    return 0;
}


