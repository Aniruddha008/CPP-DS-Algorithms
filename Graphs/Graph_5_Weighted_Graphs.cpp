#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<pair<int, int>> graph[], int u, int v, int wt)
{
    graph[u].push_back(make_pair(v, wt));
    graph[v].push_back(make_pair(u, wt));
}

/*
void printGraph(vector <pair<int, int>> graph[], int vertices)
{
    int vertex, weight;
    for (size_t node{0}; node < vertices; node++)
    {
        for(auto x: graph[node])
        {
            cout << "Hello" << " ";

        }
    }
}
*/

void printGraph(vector<pair<int,int> > adj[], int V)
{
    int v, w;
    for (int u = 0; u < V; u++)
    {
        cout << "Node " << u << " makes an edge with \n";
        for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
        {
            v = it->first;
            w = it->second;
            cout << "\tNode " << v << " with edge weight ="
                 << w << "\n";
        }
        cout << "\n";
    }
}

int main()
{
    const int V = 5;
    vector<pair<int, int> > adj[V];
    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 20);
    addEdge(adj, 1, 2, 30);
    addEdge(adj, 1, 3, 40);
    addEdge(adj, 1, 4, 50);
    addEdge(adj, 2, 3, 60);
    addEdge(adj, 3, 4, 70);
    printGraph(adj, V);

    return 0;
}
