#include<iostream>
#include<vector>
using namespace std; 


void addDirectedEdge(vector<int> graph[], int u, int v)
{
    graph[u].push_back(v);
}

void printDirectedGraph(vector<int> graph[], int vertices)
{
    for(size_t i{0}; i < vertices; i++)
    {
        for (auto u: graph[i])
        {
            cout << i << " ---> " << u << ",    " ;
        }
        cout << endl;
    }
}

bool CycleDetectUndirectedGraph(vector<int> graph[], bool visited[], bool dfs_visited[], int source)
{

    // mark the current node as visted in both arrays
    int curr_node = source;
    visited[curr_node] = true;
    dfs_visited[curr_node] = true;

    for (auto u : graph[curr_node])
    {
        if (visited[u] == false)
        {
            if (CycleDetectUndirectedGraph(graph, visited, dfs_visited, u) == true) 
            {
                return true;
            }
        }
        else if (visited[u] && dfs_visited[u] == true)
        {
            return true;
        }
    }

    // you did not find any further children of the current node
    dfs_visited[curr_node] = false;
    return false;
}


bool DFSEntry(vector<int> graph[], int vertices)
{
    bool visited[9] = {false, false, false, false, false, false, false, false, false};
    bool dfs_visited[9] = {false, false, false, false, false, false, false, false, false};

    for (size_t i{0} ; i< vertices ; i++)
    {
        if (visited[i] == false)
        {
            if (CycleDetectUndirectedGraph(graph, visited, dfs_visited, i) == true)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    const int v = 9;
    vector<int> graph[9];

    addDirectedEdge(graph, 0, 1);
    addDirectedEdge(graph, 1, 2);
    addDirectedEdge(graph, 2, 3);
    addDirectedEdge(graph, 2, 5);
    addDirectedEdge(graph, 3, 4);
    addDirectedEdge(graph, 6, 1);
    addDirectedEdge(graph, 6, 7);
    addDirectedEdge(graph, 7, 8);
    addDirectedEdge(graph, 8, 6);

    //printDirectedGraph(graph, v);

    cout << "Cycle detected? " << DFSEntry(graph, v);
    return 0;

}







