#include <bits/stdc++.h>
using namespace std;

// APPROACH 1: BRUTE FORCE
// Har index ke liye:
// 1. Left side ka maximum find karo
// 2. Right side ka maximum find karo
// 3. Water = min(leftMax, rightMax) - height[i]
//
// Time Complexity: O(n^2)
// Space Complexity: O(1)

int trapBrute(vector<int> &height)
{

    int n = height.size();
    int totalWater = 0;

    for (int i = 0; i < n; i++)
    {

        int leftMax = 0;
        int rightMax = 0;

        // Left side ka maximum
        for (int j = 0; j <= i; j++)
        {
            leftMax = max(leftMax, height[j]);
        }

        // Right side ka maximum
        for (int j = i; j < n; j++)
        {
            rightMax = max(rightMax, height[j]);
        }

        // Current position par water
        totalWater += min(leftMax, rightMax) - height[i];
    }

    return totalWater;
}

// APPROACH 2: PREFIX + SUFFIX MAXIMUM
// leftMax[i]  = i ke left tak maximum height
// rightMax[i] = i ke right tak maximum height
//
// Phir:
// water = min(leftMax[i], rightMax[i]) - height[i]
//
// Time Complexity: O(n)
// Space Complexity: O(n)

int trapBetter(vector<int> &height)
{

    int n = height.size();

    if (n == 0)
    {
        return 0;
    }

    vector<int> leftMax(n);
    vector<int> rightMax(n);

    // Build leftMax

    leftMax[0] = height[0];

    for (int i = 1; i < n; i++)
    {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    // Build rightMax

    rightMax[n - 1] = height[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    // Calculate trapped water

    int totalWater = 0;

    for (int i = 0; i < n; i++)
    {

        int waterLevel = min(leftMax[i], rightMax[i]);

        totalWater += waterLevel - height[i];
    }

    return totalWater;
}

// APPROACH 3: TWO POINTER - OPTIMAL
// Left aur Right dono ends se start karenge.
//
// leftMax  = left side ka maximum
// rightMax = right side ka maximum
//
// Agar height[left] <= height[right]:
//     left side process karo
//
// Otherwise:
//     right side process karo
//
// Key idea:
// Smaller boundary water level ko determine karti hai.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

int trapOptimal(vector<int> &height)
{

    int n = height.size();

    if (n == 0)
    {
        return 0;
    }

    int left = 0;
    int right = n - 1;

    int leftMax = 0;
    int rightMax = 0;

    int totalWater = 0;

    while (left <= right)
    {

        // LEFT SIDE PROCESS

        if (height[left] <= height[right])
        {

            // Agar current height naya maximum hai
            if (height[left] >= leftMax)
            {

                leftMax = height[left];
            }

            // Warna current building ke upar water hai
            else
            {

                totalWater += leftMax - height[left];
            }

            left++;
        }

        // RIGHT SIDE PROCESS

        else
        {

            // Agar current height naya maximum hai
            if (height[right] >= rightMax)
            {

                rightMax = height[right];
            }

            // Warna current building ke upar water hai
            else
            {

                totalWater += rightMax - height[right];
            }

            right--;
        }
    }

    return totalWater;
}

// MAIN

int main()
{

    vector<int> height = {4, 2, 0, 3, 2, 5};

    // APPROACH 1: BRUTE

    cout << "Brute Force Answer: "
         << trapBrute(height)
         << endl;

    // APPROACH 2: PREFIX + SUFFIX

    cout << "Better Answer: "
         << trapBetter(height)
         << endl;

    // APPROACH 3: TWO POINTER

    cout << "Optimal Answer: "
         << trapOptimal(height)
         << endl;

    return 0;
}
