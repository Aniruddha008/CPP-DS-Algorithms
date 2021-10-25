#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

void addEges(vector<int> adj[], int u, int v)
{
    
    adj[v].push_back(u);
    adj[u].push_back(v);
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

void BFS(vector<int> adj[], int start)
{   
    queue<int> q;
    vector<int> visited ;
    q.push(start);
    visited.push_back(start);

   

    
    while (q.empty() == false)
    {
        int curr = q.front();
        q.pop();
        cout << "current element = " << curr << endl;
        
    
        
        for(auto x: adj[curr])
        {
            cout << "test" << endl;
            
            if (!count(visited.begin(), visited.end(), x) )
            {
                visited.push_back(x);
                q.push(x);
            }
                
        }
           
        

    }

    for (auto x: visited)
    {
        cout << x << " ";
    }

}

void BFS2(vector<int> graph[], int source, int v)
{   
    
    bool visited[6];
    for(size_t i{0}; i < v; i++)
    {
        visited[i] = false;
    }

    queue<int> q;
    q.push(source);  
    visited[source] = true;
    cout << source << " ";
    while(q.empty() == false)
    {
        int curr = q.front();
        q.pop();

        for(auto x: graph[curr])
        {
            if (visited[x] == false)
            {
                visited[x] = true;
                q.push(x);
                cout << x << " ";

            }
        }
    }


}

int main()
{
    const int v = 6;
    vector<int> adj[v];
    vector<int> visited;
    addEges(adj, 0, 1);
    addEges(adj, 0, 2);
    addEges(adj, 0, 5);
    addEges(adj, 1, 3);
    addEges(adj, 2, 4);
    addEges(adj, 3, 5);
    addEges(adj, 4, 5);

    //printGraph(adj, v);
    
    BFS(adj, 0);
    cout << endl;
    cout << "BFS using Hash function" << endl;
    BFS2(adj, 0, v);


    return 0;
}