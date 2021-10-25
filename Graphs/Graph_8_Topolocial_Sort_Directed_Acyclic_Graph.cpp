#include<iostream>
#include<vector>
#include<stack>
using namespace std; 



void printGraph(vector<int> graph[], int vertices)
{
    for(size_t i {0} ; i< vertices; i++)
    {
        for (auto u: graph[i])
        {
            cout << i << " ---> " << u << " ";
        }
        cout << endl;
    }
}

void ToplogicalSort(vector<int> graph[], bool visited[], stack<int> &s, int curr_node)
{   
    visited[curr_node] = true;

    for (auto u: graph[curr_node])
    {
        if (visited[u] == false)
        {
            ToplogicalSort(graph, visited, s, u);
            
        }
    }
    s.push(curr_node);
    

}

void DFSEntry(vector<int> graph[], int vertices)
{
    bool visited[6];
    stack<int> s;

    for (int i = 0;i < vertices; i++)
    {
        visited[i] = false;
    }

    for (auto x : visited)
    {
        //cout << x << " " ;
    }


    for (size_t i{0} ; i < vertices; i ++)
    {
        //cout << " i = " << i << endl;
        if (visited[i] == false)
        {
            //cout << "unvisited i " << i << endl;
            ToplogicalSort(graph, visited, s, i);
            
        }
        
    }

    for(size_t i{0}; i < vertices ; i++)
    {
        int t = s.top();
        s.pop();
        cout << t << " ";
    }


}

void addDirectedEdge(vector<int> graph[], int u, int v)
{
    graph[u].push_back(v);
}

int main()
{
    const int v = 6; 
    vector<int> graph[v];

    addDirectedEdge(graph, 2, 3);
    addDirectedEdge(graph, 3, 1);
    addDirectedEdge(graph, 4, 0);
    addDirectedEdge(graph, 4, 1);
    addDirectedEdge(graph, 5, 0);
    addDirectedEdge(graph, 5, 2);

    DFSEntry(graph, v);

}
