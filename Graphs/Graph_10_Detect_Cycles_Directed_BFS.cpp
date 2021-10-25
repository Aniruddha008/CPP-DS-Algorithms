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

bool ToplogicalSort(vector<int> graph[], int vertices)
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
   // keep a counter
   int counter = 0;

   while(q.empty() == false)
   {
       int node = q.front();
       q.pop();
  
       for (auto u: graph[node])
       {

           indgree[u] = indgree[u] - 1;
           if (indgree[u] == 0)
           {
               q.push(u);
           }

       }
        counter++; 
   }

  if (counter == vertices) return false;
   else return true;

}




void addDirectedEdge(vector<int> graph[], int u, int v)
{
    graph[u].push_back(v);
}

int main()
{
    const int v = 6; 
    vector<int> graph[v];

    addDirectedEdge(graph, 0, 1);
    addDirectedEdge(graph, 1, 2);
    addDirectedEdge(graph, 2, 3);
    addDirectedEdge(graph, 3, 1);


cout << endl;
   cout << "is a cycle present? : " << ToplogicalSort(graph, v);

   
}
