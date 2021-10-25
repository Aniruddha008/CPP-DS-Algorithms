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
                t[i][j] = t[i - 1][j - a[i - 1]] || t[i-1][j];
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

    
    int diff = INT_MAX;;
    for(int j = 0; j< c /2 +1; j++)
        {
    
           if (t[n][j] == 1)
           {   
               int curr_diff = c - 2 * j; 
               if (curr_diff < diff)
               diff = curr_diff;
           }

        }
        


    cout << endl;
    return diff;
    
}

int main()
{
    int array[] = {1, 6, 11, 5};
    int size = sizeof(array) / sizeof(array[0]);
    int sum = 0;
    memset(t, -1, sizeof(t));
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }

    
    cout << "Minimum subset sum difference " << endl << minSubsetSumDiff(array, sum, size) ; 
    
}