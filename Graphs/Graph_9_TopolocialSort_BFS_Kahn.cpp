#include<iostream>
#include<vector>
#include<queue>
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

vector<int> ToplogicalSort(vector<int> graph[], int vertices)
{   
   vector<int> indgree(vertices, 0);
   for(size_t i{0}; i < vertices; i++)
   {
       for(auto u: graph[i])
       {
           indgree[u]++;
       }
   }


   queue<int> q;

   for (size_t i{0}; i < vertices; i++)
   {
       if (indgree[i] == 0)
       {
           q.push(i);
       }
   }


    // BFS
   vector<int> res;

   while(q.empty() == false)
   {
       int node = q.front();
       q.pop();

       res.push_back(node);

       for (auto u: graph[node])
       {
           indgree[u]--;
           if (indgree[u] == 0)
           {
               q.push(u);
           }
       } 
   }

   return res;
    

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

   vector<int> res = ToplogicalSort(graph, v);

    for(auto x: res)
    {
        cout << x << " ";
    }
}
