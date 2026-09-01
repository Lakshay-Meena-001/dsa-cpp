#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getWinner(vector<int>& arr, int k)
{
    int winner = arr[0];
    int wins = 0;

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > winner)
        {
            winner = arr[i];
            wins = 1;
        }
        else
        {
            wins++;
        }

        if (wins == k)
        {
            return winner;
        }
    }

    return *max_element(arr.begin(), arr.end());
}

int main()
{
    vector<int> arr = {2, 1, 3, 5, 4, 6, 7};

    int k = 2;

    cout << getWinner(arr, k) << '\n';

    return 0;
}