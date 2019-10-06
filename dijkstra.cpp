#include<bits/stdc++.h>
using namespace std;
#define max_node 100
struct Struct
{
    int s_time;
    int f_time;
    int color;
    int parent;
};
Struct node[max_node];

priority_queue <int, vector<int>, greater<int> > Q;
//queue<int> Q;

int Time;
int v, e;

void add_edge(list<pair<int, int> > adj_list[], int m, int n, int wt){
    adj_list[m].push_back(make_pair(n, wt));
}

void dfs_visit(list<pair<int, int> > adj_list[], int s){

    node[s].color = 1;
    //cout << s << " ";
    Time++;
    node[s].s_time = Time;
    list<pair<int, int> >::iterator it;
    for (it = adj_list[s].begin(); it != adj_list[s].end(); it++)
        if (node[it->first].color == 0){
            node[it->first].parent = s;
            dfs_visit(adj_list, it->first);
        }
    node[s].color = 2;
    Time++;
    node[s].f_time = Time;
    //S.push(s);
    Q.push(s);
}

void dfs(list<pair<int, int> > adj_list[], int s){
    for (int i = 0; i < v; i++)
        node[i].color = 0;
    dfs_visit(adj_list, s);
    for(int i=0; i<v; i++){
        if(node[i].color == 0){
            dfs_visit(adj_list, i);
        }
    }
}

void dijkstra(list<pair<int, int> > adj_list[], int s){
    int dist[v];
    int parent[v];
    for(int i=0; i<v; i++){
        dist[i] = INT_MAX;
    }
    dist[s] = 0;
    stack<int> St;
    while(Q.empty() != true){
        int u = Q.top();
        Q.pop();
        list<pair<int, int> >::iterator itr;
        if(dist[u] != INT_MAX){
            for(itr = adj_list[u].begin(); itr != adj_list[u].end(); itr++){
                if(dist[itr->first] > dist[u] + itr->second){
                    dist[itr->first] = dist[u] + itr->second;
                }
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
    cout<<"Enter number of vertices/nodes: ";
    cin>>v;
    cout<<"Enter number of edges: ";
    cin>>e;
    cout<<"Enter the connected pairs and their distance(first source then destination, then weight): "<<endl;

    list<pair<int, int> > adj_list[v];

    for(int i=0; i<e; i++){
        int m,n,wt;
        cin>>m>>n>>wt;
        add_edge(adj_list, m, n, wt);
    }

    cout<<"Enter node to start traversing: ";
    int s;
    cin>>s;
    dfs(adj_list, s);
    dijkstra(adj_list, s);

    return 0;
}
