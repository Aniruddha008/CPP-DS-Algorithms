#include<iostream>
#include<cstring>
using namespace std;

//global array
int t[102][1002];

int minSubsetSumDiff(int a[], int c, int n)
{


    //Initialize the base case
    for(int i = 0; i < n+1; i++)
    {
        for(int j = 0; j< c+1; j++)
        {
            // 0th row: where number of elements remain 0 in the array
            if(i == 0)
            {
                t[i][j] = false;
            }

            // 0th column: where sum remains 0 
            if(j == 0)
            {
                t[i][j] = true;
            }
        }
    }

    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j< c+1; j++)
        {
            if(a[i - 1] <= j)
            {
                //max changes to ||
                t[i][j] = t[i - 1][j - a[i - 1]] + t[i-1][j];
            }
            else 
            {
                t[i][j] = t[i-1][j];
            }
             
        }
    }

    for(int i = 0; i < n+1; i++)
    {
        for(int j = 0; j< c+1; j++)
        {
    
            cout<<" "<< t[i][j]<<" ";

        }
        cout<<"\n";
    }

    
  
        


    cout << endl;
    return t[n][c];
    
}

int main()
{
    int array[] = {1,1,1,1,1};
    int size = sizeof(array) / sizeof(array[0]);
    int sum = 0;
    memset(t, -1, sizeof(t));
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }

    int req_diff = 3;
    int s1 = (sum + req_diff) / 2;
    
    cout << "Minimum subset sum difference " << endl << minSubsetSumDiff(array, s1, size) ; 
    
}