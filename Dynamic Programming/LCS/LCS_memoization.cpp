#include<iostream>
#include<cstring>
#include<string>
using namespace std;


//global table
int t[102][1002];

int LCS(string X, string Y, int n, int m)
{
    //base condition
    if( n == 0 || m == 0) return 0;
    
    //DP
    if(t[n][m] != -1) return t[n][m];

    if (X[n - 1] == Y[m - 1]) return t[n][m] = 1 + LCS(X, Y, n - 1, m - 1);
    else return t[n][m] = max(LCS(X, Y, n, m - 1), LCS(X, Y, n - 1, m)) ;

}

int main()
{
    memset(t, -1, sizeof(t));

    string X = "AGCD";
    string Y = "ABCD";
    int n, m;
    n = X.length();
    m = Y.length();



    cout << "LCS = " << LCS(X, Y, n, m) << endl;
    return 0;

}