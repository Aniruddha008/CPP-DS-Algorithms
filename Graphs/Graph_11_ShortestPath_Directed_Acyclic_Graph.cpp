#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void addEdge(vector<pair<int, int>> graph[], int u, int v, int wt)
{
    graph[u].push_back(make_pair(v, wt));    
}


void TopoSort(vector<pair<int, int>> graph[], bool visited[], stack<int> &s, int curr_node)
{
    visited[curr_node] = true;
    
    for(auto u: graph[curr_node])
    {
        if (visited[u.first] == false)
        {
            TopoSort(graph, visited, s, u.first);
        }
    }
    s.push(curr_node);

    

} 

void ShortestPath(int source, stack<int> &s, vector<pair<int, int>> graph[], int distance[], int vertices)
{
    while (s.empty() == false)
    {
        int curr_node = s.top();
        //cout << "Current node == " << curr_node << endl;
        s.pop();

    
    if (distance[curr_node] != INT_MAX) 
        {
            
            for (auto u: graph[curr_node])
            {
                int distance_to_u = distance[curr_node] + u.second;
                if (distance_to_u < distance[u.first])
                {
                    //cout << "test " << endl;
                    distance[u.first] = distance_to_u;
                    //cout << u.first << " "  << distance[u.first] << " ";
                }
            }

        }
    }
    //cout << distance[0] << endl; 

   


}

void DFSEntry(vector<pair<int, int>> graph[], int vertices, int start)
{
    bool visited[] = {false, false, false, false, false, false};
    stack<int> s;
    for (size_t i{0}; i< vertices; i++)
    {
        if(visited[i] == false)
        {
            TopoSort(graph, visited, s, i);
        }
    }

/*
    Topo sort is working properly

    for (size_t i{0}; i < 6; i++)
    {
        int node = s.top();
        cout << node << endl;
        s.pop();
    }
*/
    int distance[6] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX};

    distance[start] = 0;


    ShortestPath(start, s, graph, distance, vertices);
   
   for(size_t i{0} ; i< vertices; i++)
   {
       cout << i << " : " << distance[i] << endl;
   }
 

}

int main()
{

    vector<pair<int, int>> graph[6];

    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 4, 1);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 2, 3, 6);
    addEdge(graph, 4, 2, 2);
    addEdge(graph, 4, 5, 4);
    addEdge(graph, 5, 3, 1);

    DFSEntry(graph, 6, 0);


}

