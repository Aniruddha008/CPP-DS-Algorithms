#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

//global matrix
int t[102][1002];

int ShortestCommonSupersequence(string X, string Y, int n, int m)
{

    //base codnition
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < m+1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < m+1; j++)
        {
            cout << " " << t[i][j];
        }
        cout << endl;
    }
    
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else 
            {
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);
            }
        }
        
    }   


    string lcs = " ";
    string scs = " ";
    int i = n;
    int j = m;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs.push_back(X[i - 1]);
            scs.push_back(X[i - 1]);
            i-- ;
            j-- ;
        }
        else 
        {
            

            if (t[i][j - 1] >  t[i - 1][j])
            {
                scs.push_back(Y[j - 1]);
                j--;
            }
            else 
            {
                scs.push_back(X[i - 1]);
                i--;
            }
        }
    }
    

    reverse(lcs.begin(), lcs.end());
    reverse(scs.begin(), scs.end());
    cout << "lcs = " << lcs << endl;
    cout << "scs = " << scs;
    cout<< endl;
    return n + m - t[n][m];

}

int main()
{
    memset(t, -1, sizeof(t));

    string X = "ACBCF";
    string Y = "ABCDAF";

    int n = X.length();
    int m = Y.length();

    cout << "X = " << X << "length of X: " << n << endl;
    cout << "Y = " << Y << "length of Y: " << m << endl;
    
    cout << "Shortest Common Supersequence: " << endl<< ShortestCommonSupersequence(X, Y, n, m);
}