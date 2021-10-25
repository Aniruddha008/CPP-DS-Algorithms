#include<iostream>
#include<cstring>
#include<string>
using namespace std;


//global table
int t[102][1002];

int LongestCommonSubstring(string X, string Y, int n, int m)
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
            
            else t[i][j] = 0;
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
    cout << "rETURNING MAX VALUE:" << endl;
    cout << endl;  
    int longest_common_substring = 0; 
    for(int i = 0; i < n+1; i++)
    {
        for(int j = 0; j< m+1; j++)
        {
    
            if (t[i][j] > longest_common_substring)
            {
                longest_common_substring = t[i][j];
            }

        }
        
    }


   return longest_common_substring;
}

int main()
{
    memset(t, -1, sizeof(t));

    string X = "ABCDE";
    string Y = "ABCDCE";
    int n, m;
    n = X.length();
    m = Y.length();

    cout << "n = " << n << endl;
    cout << "m = " << m << endl;

    cout << "LongestCommonSubstring = " << LongestCommonSubstring(X, Y, n, m) << endl;
    return 0;

}