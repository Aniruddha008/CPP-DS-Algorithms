#include<iostream>
#include<vector>
#include<queue>
using namespace std; 



void addEdge(vector<int> graph[], int u, int v)
{
    
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void printGraph(vector<int> adj[], int v)
{
    for (size_t i{0}; i< v; i++)
    {
        for (auto x: adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }

}


bool CycleDetectionDFS(vector<int> graph[], bool visited[], int current_node, int parent)
{
    visited[current_node] = true;

    for (auto u : graph[current_node])
    {
        if (visited[u] == false)
        {
            if (CycleDetectionDFS(graph, visited, u, current_node) == true) return true;
        }
        else if (u != parent)
        {
            return true;
        }
    }

    return false;
}


bool DFSEntry(vector<int> graph[], int vertices)
{
    // 1. create visited array
    bool visited[8]= {false, false, false, false, false, false, false, false};

    /*
    2.  loop from i = 1 to i < (v + 1)
        
        if (ith node not visited)

            call the cycle detection algorithm (vector<int> graph, bool visited[], int current_node, int parent)
            parent = -1 initally which indicates no connections before this node.



        the loop handles diconnected graphs
    */

   for(size_t i{0} ; i < vertices ; i++)
   {
       if (visited[i] == false)
       {
           if (CycleDetectionDFS(graph,visited, i, -1)) return true;
       }

    }

    return false;
}


bool CycleDetectionBFS(vector<int> graph[], bool visited[], int source, int parent)
{
    queue<pair<int, int>> q;
    q.push({source, parent});
    visited[source] = true;

    while (q.empty() == false)
    {
        pair<int, int> p = q.front();
        q.pop();
        int curr = p.first;
        int parent = p.second;

        for (auto x: graph[curr])
        {
            if (visited[x] == false)
            {
                q.push({x , curr});
                visited[x] = true;
            }
            else if (x != parent)
            {
                return true;
            }
        }
    }
    return false;

}


bool BFSEntry(vector<int> graph[], int vertices)
{
    bool visited[8] = {false, false, false, false, false, false, false, false};

    queue<int> q;
    for (size_t i{0}; i < vertices ; i ++)
    {
        if(visited[i] == false)
        {
            if (CycleDetectionBFS(graph, visited, i, -1))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    
    const int vertices = 8; 
    vector<int> graph[8];

    

    addEdge(graph, 0, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 4, 7);
    addEdge(graph, 6, 5);
    addEdge(graph, 6, 7);

    printGraph(graph, vertices);

    cout << "Cycle detection algorithm with DFS:recursive " << endl;
    cout << "Does a cycle exist in this graph? " << DFSEntry(graph, vertices) << endl;

    cout << endl;
    cout << "Cycle detection algorithm with BFS:Iterative " << endl;
    cout << "Does a cycle exist in this graph? " << BFSEntry(graph, vertices) << endl;    
    

    return 0;
}