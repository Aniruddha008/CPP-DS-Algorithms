#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;


void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int v)
{
    for (size_t i{0}; i< v; i++)
    {
        for(auto x: adj[i])
        {
            cout << i << " " << x << " ";
        }
        cout << endl;
    }
}

void DFS(vector<int> graph[], int start)
{
    vector<int> visited;
    stack<int> s;

    //push the first element into the stack and add it to the visited list
    s.push(start);
    visited.push_back(start);

    while(s.empty() == false)
    {
        int curr = s.top();
       // cout << "current top: " << curr<< endl;
        s.pop();

/*        
        for(int x: graph[0])
        {
            cout << x << " " << endl;
        }
*/
        for (auto x: graph[curr])
        {
            if (!count(visited.begin(), visited.end(), x))
            {
                //cout << x << " into stack"<< endl;
                s.push(x);
                visited.push_back(x);
            }
        }
    }


    //print the visited list
    for (auto x: visited)
    {
        cout << x << " ";
    }

}

void DFSRecursion(vector<int> graph[], int source, bool visited[])
{
    int curr = source;
    visited[curr] = true;
    cout << source << " ";
    for (auto x: graph[curr])
    {
        if (visited[x] == false)
        {
            DFSRecursion(graph, x, visited);
        }
    }

}

void DFS2(vector<int> graph[], int source, int v)
{
    bool visited[7];

    for (size_t i{0} ; i< v; i++)
    {
        visited[i] = false;
    }

    for (size_t i{0}; i < v; i++)
    {
        if (visited[i] == false)
        {
            DFSRecursion(graph, i, visited);
        }
        
    }
    
}

int main()
{
    const int v = 7;
    vector<int> graph[v];

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 0, 4);
    addEdge(graph, 5, 6);
    addEdge(graph, 6, 4);
    addEdge(graph, 4, 5);

    //printGraph(graph, v);

    cout << endl;
    cout << " DFS using stack: iterative " << endl;
    DFS(graph, 0);

    cout <<endl;
    cout << " DFS using recursion and hash " << endl;
    DFS2(graph, 0, v);

    return 0;
}
