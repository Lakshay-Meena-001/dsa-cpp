#include <bits/stdc++.h>
using namespace std;

int countPairsWithDifferenceK(vector<int> &arr, int K)
{

    int n = arr.size();

    int i = 0;
    int j = 1;

    int count = 0;

    while (i < n && j < n)
    {

        // i and j should represent different elements
        if (i == j)
        {
            j++;
            continue;
        }

        int diff = arr[j] - arr[i];

        if (diff == K)
        {
            count++;

            // Move both to look for the next pair
            i++;
            j++;
        }
        else if (diff < K)
        {
            // Need a larger difference
            j++;
        }
        else
        {
            // Need a smaller difference
            i++;
        }
    }

    return count;
}

int main()
{

    vector<int> arr = {1, 3, 5, 7, 9};

    int K = 2;

    cout << countPairsWithDifferenceK(arr, K) << endl;

    return 0;
}