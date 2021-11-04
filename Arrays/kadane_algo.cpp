#include<iostream>
#include<vector>
using namespace std;


int kadane_algo(vector<int> arr)
{
    int max_sum = INT16_MIN;
    int curr_sum = 0;

    for (size_t i{0}; i < arr.size(); i++)
    {
        curr_sum = curr_sum + arr[i];

       /* if(curr_sum > max_sum)
        {
            max_sum = curr_sum;
        }
       */
      
        max_sum = max(curr_sum, max_sum);

        if (curr_sum < 0)
        {
            curr_sum = 0;

        }


    }

    return max_sum;
}

int main()
{
    vector<int> v {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "maximum sum sub array = " << kadane_algo(v) << endl;
}