#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Problem : 23_Sort_Matrix_Diagonally_LC_1329.cpp
// Pattern : Diagonal Grouping
// Approach : Group by (row-col), sort each diagonal,
//            then place values back.
//
// Time  : O(rows × cols × log(min(rows, cols)))
// Space : O(rows × cols)
//
// Learning:
// 1. Main Diagonal Key = row - col
// 2. Group -> Sort -> Write Back
// 3. HashMap + Vector

vector<vector<int>> diagonalSort(vector<vector<int>> matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    unordered_map<int, vector<int>> diagonals;

    // Group elements.

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            diagonals[i - j].push_back(matrix[i][j]);
        }
    }

    // Sort every diagonal.

    for (auto &entry : diagonals)
    {
        sort(entry.second.begin(), entry.second.end());
    }

    // Current index for every diagonal.

    unordered_map<int, int> index;

    // Fill matrix back.

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int key = i - j;

            matrix[i][j] = diagonals[key][index[key]++];
        }
    }

    return matrix;
}

// Driver

int main()
{
    int rows, cols;

    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> answer = diagonalSort(matrix);

    for (const auto &row : answer)
    {
        for (int value : row)
        {
            cout << value << " ";
        }

        cout << endl;
    }

    return 0;
}