#include <iostream>
#include <vector>
using namespace std;

//--------------------------------------------------
// Problem: can_place_flowers_lc_605.cpp
// Pattern : Greedy Simulation
// Constraint:
// 1. Adjacent flowers are not allowed
// 2. Modify flowerbed while traversing
// Time : O(n)
// Space: O(1)
//--------------------------------------------------

bool canPlaceFlowersOptimal(vector<int> &flowerbed, int n)
{
    int count = 0;
    int size = flowerbed.size();

    for (int i = 0; i < size; i++)
    {
        int left = (i == 0) ? 0 : flowerbed[i - 1];
        int right = (i == size - 1) ? 0 : flowerbed[i + 1];

        // Plant only if both neighbours are empty.
        if (flowerbed[i] == 0 && left == 0 && right == 0)
        {
            flowerbed[i] = 1; // Update immediately to avoid future conflicts.
            count++;

            if (count >= n)
            {
                return true;
            }
        }
    }

    return count >= n;
}

int main()
{
    int size;
    cin >> size;

    vector<int> flowerbed(size);

    for (int i = 0; i < size; i++)
    {
        cin >> flowerbed[i];
    }

    int n;
    cin >> n;

    cout << (canPlaceFlowersOptimal(flowerbed, n) ? "true" : "false");

    return 0;
}