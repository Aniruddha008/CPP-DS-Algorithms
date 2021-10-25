#include<iostream>
#include<cstring>
using namespace std;


//global array 
int t[102][1002];

bool equalSum(int a[], int c, int n)
{
    if (c %2 != 0) return false; //odd sum

    int sum = c / 2;


    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)  t[i][j] = true;
            if (i == 0)  t[i][j] = false;
        }
    }

    for(int i = 1; i < n + 1; i++)
    {
        for(int j = 1; j < sum + 1; j++)
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


    return t[n][sum];
}

int main()
{
    int array[] = {15, 5, 10, 20};
    int sum = 0;

    int size = sizeof(array) / sizeof(array[0]);

    for(int i = 0; i < size; i++)
    {
        sum += array[i];
    }

    memset(t, -1, sizeof(t));
    cout << equalSum(array, sum, size) << endl;
    return 0;
}