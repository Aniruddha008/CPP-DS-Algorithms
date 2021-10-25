#include<iostream>
#include<cstring>
using namespace std;


//global array 
int t[102][1002];

int subSetSum(int a[], int c, int n)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < c + 1; j++)
        {
            if (j == 0)  t[i][j] = true;
            if (i == 0)  t[i][j] = false;
        }
    }

    for(int i = 1; i < n + 1; i++)
    {
        for(int j = 1; j < c + 1; j++)
        {
            if (a[i - 1] <= j)
            {
                //max changes to ||
                t[i][j] = t[i - 1][j - a[i - 1]] || t[i - 1][j];
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
    int array[5] = {2, 3, 7, 8, 10};
    int sum = 11;

    int size = sizeof(array) / sizeof(array[0]);

    memset(t, -1, sizeof(t));
    cout << subSetSum(array, sum, size) << endl;
    return 0;
}