#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;


//global table
int t[102][1002];

int LCS(string X, string Y, int n, int m)
{
    cout << "inside lcs" << endl;
    //base condition
    for(int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < m+1; j++)
        {
            if (i == 0 || j == 0) t[i][j] = 0;
        }
    }

    cout << "printing matrix after base condition:" << endl;
    cout << endl;
    for(int i = 0; i < n+1; i++)
    {
        for(int j = 0; j< m+1; j++)
        {
    
            cout<<" "<< t[i][j]<<" ";

        }
        cout<<"\n";
    }

    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < m+1; j++)
        {
            if (X[i - 1] == Y[j - 1])  t[i][j] = 1 + t[i - 1][j - 1];
            
            else t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }
    

    cout << "printing matrix after completetion:" << endl;
    cout << endl;
    for(int i = 0; i < n+1; i++)
    {
        for(int j = 0; j< m+1; j++)
        {
    
            cout<<" "<< t[i][j]<<" ";

        }
        cout<<"\n";
    }

    int ptr = t[n][m];
    cout << "ptr: " << t[n][m] << endl;
    cout << n <<"  " <<  m << endl;
    int i = n, j = m;
    
   string lcs = "";
   while (i > 0 && j > 0)
   {
       if(X[i - 1] == Y[j - 1])
       {
           lcs.push_back(X[i - 1]);
           i--;
           j--;


       }
       else 
       {
         if(t[i][j - 1] > t[i - 1][j])
         {
             j--;
         }
         else 
         {
             i--;
         }
       }
           
   }

    reverse(lcs.begin(), lcs.end());
    cout<<"lcs is: "<< lcs << endl;
   return t[n][m];
}

int main()
{
    memset(t, -1, sizeof(t));

    string X = "ACBCF";
    string Y = "ABCDAF";
    int n, m;
    n = X.length();
    m = Y.length();

    cout << "n = " << n << endl;
    cout << "m = " << m << endl;

    cout << "LCS = " << LCS(X, Y, n, m) << endl;
    return 0;

}