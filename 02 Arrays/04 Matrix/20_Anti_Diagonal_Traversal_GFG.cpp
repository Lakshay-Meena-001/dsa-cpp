#include <iostream>
#include <vector>
using namespace std;

// Problem : 20_Anti_Diagonal_Traversal_GFG.cpp
// Pattern : Diagonal Grouping
// Approach : Group elements by (row + column)
//            and print every diagonal.
//
// Time  : O(rows × cols)
// Space : O(rows × cols)
//
// Learning:
// 1. Diagonal Number = row + column
// 2. Group elements by diagonal
// 3. No reversal required

vector<vector<int>> antiDiagonalTraversal(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> diagonals(rows + cols - 1);

    // Group elements.

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            diagonals[i + j].push_back(matrix[i][j]);
        }
    }

    return diagonals;
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

    vector<vector<int>> answer = antiDiagonalTraversal(matrix);

    for (auto diagonal : answer)
    {
        for (int value : diagonal)
        {
            cout << value << " ";
        }

        cout << endl;
    }

    return 0;
}