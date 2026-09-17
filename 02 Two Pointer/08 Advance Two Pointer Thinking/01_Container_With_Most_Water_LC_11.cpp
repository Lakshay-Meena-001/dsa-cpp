#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int> &height)
{
    int L = 0;
    int R = height.size() - 1;

    int ans = 0;

    while (L < R)
    {

        // Width = distance between two pointers
        int width = R - L;

        // Smaller wall decides the water height
        int h = min(height[L], height[R]);

        int area = width * h;
        ans = max(ans, area);

        // Smaller boundary is the bottleneck
        if (height[L] < height[R])
        {
            L++;
        }
        else
        {
            R--;
        }
    }

    return ans;
}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << "Maximum Water Area: "
         << maxArea(height) << endl;

    return 0;
}

/*
Input:
[1,8,6,2,5,4,8,3,7]

Output:
49

Core Pattern:
Two Pointers + Greedy

Mental Model:
Area = width * smaller height

Smaller boundary = bottleneck.
Move the smaller boundary because keeping it fixed
cannot produce a better area after width decreases.

TC: O(n)
SC: O(1)
*/