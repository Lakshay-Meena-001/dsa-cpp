#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem : 19_Diagonal_Traverse_LC_498.cpp
// Pattern : Diagonal Grouping
// Approach : Group elements by (row + column), then
//            reverse alternate diagonals while building answer.
//
// Time  : O(rows × cols)
// Space : O(rows × cols)
//
// Learning:
// 1. Diagonal Number = row + column
// 2. Group elements by diagonal
// 3. Reverse alternate diagonals

vector<int> findDiagonalOrder(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> diagonals(rows + cols - 1);

    // Group elements by diagonal.

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            diagonals[i + j].push_back(matrix[i][j]);
        }
    }

    vector<int> answer;

    // Build final traversal.

    for (int d = 0; d < diagonals.size(); d++)
    {
        if (d % 2 == 0)
        {
            reverse(diagonals[d].begin(), diagonals[d].end());
        }

        for (int value : diagonals[d])
        {
            answer.push_back(value);
        }
    }

    return answer;
}

// Driver

int main()
{
    int rows, cols;

    cin >> rows >> cols;

    vector<vector<int>> matrix(rows,
                               vector<int>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    vector<int> answer = findDiagonalOrder(matrix);

    for (int value : answer)
    {
        cout << value << " ";
    }

    return 0;
}