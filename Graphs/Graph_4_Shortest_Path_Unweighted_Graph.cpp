#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


void ShortestPath(vector<int> graph[], int source, int v)
{
    //1. Keep distances from all all vertices to source as infinity except the source itself
    int distance[6];
    for (size_t i{0}; i< v; i++)
    {
        if (i == 0) 
        {
            distance[source] = 0;
        }
        else 
        {
            distance[i] = INT_MAX;
        } 
        
    }
    
/*    for(size_t i {0} ; i < size(distance); i++)
    {
        cout <<  distance[i] << " ";
    }
*/

    //2. Implement BFS
    vector<int> visited;
    queue<int> q;
    q.push(source);
    visited.push_back(source);

    while(q.empty() == false)
    {
        int curr = q.front();
        int qsize = q.size();
        q.pop();
        
        
        for(auto x: graph[curr])
        {
            if (!count(visited.begin(), visited.end(), x))
            {
                distance[x] = distance[curr] + 1;
                q.push(x);
                visited.push_back(x);
            }   
        }
            
        
    }

    cout << endl;
    for(auto x: visited)
    {
        cout << x << " ";
    }

    cout << endl;
    for (size_t i{0}; i < size(distance); i++)
    {
        cout << distance[i] << " ";
    }


}

void SHortestPath2(vector<int> graph[], int source, int v)
{   
    
    int distance[6];

    for (size_t i{0}; i< v; i++)
    {
        distance[i] = INT_MIN;
    }
    distance[source] = 0;


    queue<int> q;
    bool visited[6] = {false, false, false, false, false, false};
    q.push(source);
    visited[source] = true;

    cout << source << " ";

    while(q.empty() == false)
    {
        int curr = q.front();
        q.pop();

        for(auto x: graph[curr])
        {
            if(visited[x] == false)
            {
                distance[x] = distance[curr] + 1;
                q.push(x);
                visited[x] = true;
                cout << x << " ";
            }
        }
    }

    cout << endl;
    for (size_t i{0}; i < size(distance); i++)
    {
        cout << distance[i] << " ";
    }


}



void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);

}

void printGraph(vector<int> graph[], int v)
{
    for(size_t i{0}; i< v; i++)
    {
        for(auto x: graph[i])
        {
            cout << i << " " << x << " ";
        }
        cout << endl;
    }
}

int main()
{
    const int v = 6; 
    vector<int> graph[v];
    
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 4, 5);

    //printGraph(graph, v);   

    cout << "Shortespath using BFS: " << endl;
    ShortestPath(graph, 0, v);
    cout << endl;
    cout << "Shortespath using BFS: with hash " << endl;
    SHortestPath2(graph, 0, 6);
    

    return 0;

}