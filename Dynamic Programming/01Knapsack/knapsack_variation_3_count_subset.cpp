#include<iostream>
#include<cstring>
using namespace std;


//global array 
int t[102][1002];

int countSubset(int a[], int c, int n)
{
    

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < c + 1; j++)
        {
            
            if (i == 0)  t[i][j] = 0;
            if (j == 0)  t[i][j] = 1;
        }
    }

    for(int i = 1; i < n + 1; i++)
    {
        for(int j = 1; j < c + 1; j++)
        {
            if (a[i - 1] <= j)
            {
                // || changes to +
                t[i][j] = t[i - 1][j - a[i - 1]] + t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i- 1][j];
            }
        }
    }


    return t[n][c];
}

int main()
{
    int array[] = {2, 3, 5, 6, 8, 10};

    int size = sizeof(array) / sizeof(array[0]);

    int sum = 10;

    memset(t, -1, sizeof(t));
    cout << countSubset(array, sum, size) << endl;
    return 0;
}