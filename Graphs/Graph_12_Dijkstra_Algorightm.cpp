#include<iostream>
#include<vector>
#include<queue>
using namespace std;


void addEdge(vector<pair<int, int>> graph[], int u, int v,int wt)
{
    graph[u].push_back(make_pair(v, wt));
    graph[v].push_back(make_pair(u, wt));
}

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


vector<int> Dijkstra(vector<pair<int, int>> graph[], int V, int source)
{
    vector<int> distance(V, INT_MAX);

    distance[source] = 0;


    //priority_queue <int, vector<int>, greater<int>> minHeap;
    /*
    1. create a min heap which takes (distance from source, Node)
    
    */

    priority_queue < pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>> > minHeap;
    //minHeap.push(make_pair(distance[source], source));
    minHeap.push({distance[source], source});

    while (minHeap.empty() == false)
    {
        int distanceFromSource = minHeap.top().first;
        int Node = minHeap.top().second;

        minHeap.pop();

        for(auto u: graph[Node])
        {
            int next = u.first;
            int dis = u.second;

            if (distance[next] > distance[Node] + dis)
            {
                distance[next] =  distance[Node] + dis;
                //minHeap.push(make_pair(distance[next], next));
                minHeap.push({distance[next], next});
            }
        }

    }

    return distance;

}


int main()
{
    const int V = 5;
    vector<pair<int, int> > adj[V];
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 3, 1);
    addEdge(adj, 1, 4, 5);
    addEdge(adj, 1, 2, 4);
    addEdge(adj, 2, 4, 1);
    addEdge(adj, 3, 2, 3);
    printGraph(adj, V);

    vector<int> distance = Dijkstra(adj, V, 0);

    for (auto i: distance)
    {
        cout << i << " ";
    } 

    return 0;
}