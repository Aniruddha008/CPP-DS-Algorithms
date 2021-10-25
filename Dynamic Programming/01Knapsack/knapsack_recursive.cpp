#include<iostream>
#include<stdio.h>
using namespace std;


int knapsack(int w[], int v[], int cap, int n)
{
    //Base condition check
    if (n == 0 || cap == 0)
    {
        return 0;
    }

    if (w[n - 1] <= cap)
    {
        // reurn the max of value + knapsack for next iteration and only knapsackfor next iteration
        return max(v[n - 1] + knapsack(w, v, cap - w[n - 1], n - 1), knapsack(w, v, cap, n - 1));
    }
    else //if w[n - 1] > cap 
    {
        return knapsack(w, v, cap, n - 1);
    }

   
}

int main()
{
    int weights[4] = {1, 3, 5, 8};
    int values[4] = {1, 4, 5, 7};
    int capcity = 8;
    int size = (sizeof(weights) / sizeof(weights[0]));

    cout << "Size: "<< size << endl;
    cout << "Capacity: "<< capcity << endl;

    int max_profit = knapsack(weights, values, capcity, size);
    cout << "Maximum Profit: "<< max_profit;

    return 0;
}