#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem: rotate_image_lc_48.cpp
// Pattern : Matrix Rearrangement
// Constraint:
// 1. Matrix is n x n
// 2. Rotate in-place
// Time : O(n²)
// Space: O(1)

void rotateImageOptimal(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // Transpose matrix.
    for (int i = 0; i < n; i++)
    {
        // Start from i+1 to avoid swapping twice.
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse every i.
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    rotateImageOptimal(matrix);

    for (const auto &i : matrix)
    {
        for (int value : i)
        {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Problem:
Ek N x N square matrix diya gaya hai.
Matrix ko 90 degree clockwise rotate karna hai.

Input:
[
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
]

Output:
[
  [7, 4, 1],
  [8, 5, 2],
  [9, 6, 3]
]

Approach: Transpose + Reverse

Steps:
1. Matrix ka size n calculate karo.
2. Sabse pehle matrix ka transpose find karo.
3. Transpose karne ke liye nested loops use karo.
4. Outer loop i = 0 se n-1 tak chalega.
5. Inner loop j = i + 1 se n-1 tak chalega.
6. Har position par:
   - matrix[i][j] aur matrix[j][i] ko swap karo.
   - Isse is aur jumns interchange ho jayenge.
7. Transpose complete hone ke baad har i ko reverse karo.
8. Har i ke liye:
   - reverse(matrix[i].begin(), matrix[i].end())
9. Finally, matrix 90 degree clockwise rotate ho jayega.

TC: O(n²) - Transpose karne mein O(n²) time lagta hai.
     Har i ko reverse karne mein O(n) time lagta hai.
     N is hain, isliye reversing ka total O(n²) hai.
     Overall Time Complexity O(n²) hai.

SC: O(1) - Koi extra matrix ya data structure use nahi hua.
     Swapping aur reversing in-place hoti hai.
     Auxiliary Space Complexity O(1) hai.

Important:
- Ye approach Transpose + Reverse par based hai.
- Transpose mein matrix[i][j] ko matrix[j][i] se swap karte hain.
- Inner loop j = i + 1 se start hota hai.
- Isse diagonal elements dobara swap nahi hote.
- Transpose ke baad har i ko reverse karte hain.
- Transpose + Reverse se matrix 90 degree clockwise rotate hota hai.
- Original matrix modify hota hai (In-place operation).
- Ye approach sirf square matrix (N x N) ke liye hai.
*/