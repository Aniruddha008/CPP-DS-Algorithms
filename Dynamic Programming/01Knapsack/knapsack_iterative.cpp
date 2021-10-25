#include<iostream>
#include<cstring>
using namespace std;

//gloabl matrix
int t[102][1002];

int knapsack(int weight[], int val[], int c, int n)
{
    //base condition 
    /*
    
    thats why we have an extra row and column
    
    if either i or j is 0 thenthe element is 0
            j1 j2 j3
         0   0  0  0
    i1   0
    i2   0
    i3   0


    
    */
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < c + 1; j++)
        {
            if ( i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
            
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < c + 1; j++)
        {
            if ( weight[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] +  t[i - 1][j - weight[i - 1]], t[i - 1][j]);       
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
            
        }
    }

    return t[n][c];


}



int main()
{
    int weights[4] = {1, 3, 2, 4};
    int values[4] = {1, 4, 5, 2};
    int capcity = 4;
    int size = (sizeof(weights) / sizeof(weights[0]));

    memset(t, -1, sizeof(t));
    //initialize every element of the matrix to -1.
    cout << "Size: "<< size << endl;
    cout << "Capacity: "<< capcity << endl;

    int max_profit = knapsack(weights, values, capcity, size);
    cout << "Maximum Profit: "<< max_profit;


    return 0;
}