#include <iostream>
#include <vector>
using namespace std;

//--------------------------------------------------
// Problem : Matrix Diagonal Sum (LC 1572)
// Pattern : Diagonal Traversal
//
// Time  : O(n)
// Space : O(1)
//
// Learning:
// 1. Main Diagonal -> matrix[i][i]
// 2. Secondary Diagonal -> matrix[i][n-1-i]
// 3. Avoid double counting the center element.
//--------------------------------------------------

int diagonalSum(const vector<vector<int>> &matrix)
{
    int n = matrix.size();

    int sum = 0;

    // Traverse every row.
    for (int i = 0; i < n; i++)
    {
        // Add main diagonal element.
        sum += matrix[i][i];

        // Add secondary diagonal element
        // only if it is a different cell.
        if (i != n - 1 - i)
        {
            sum += matrix[i][n - 1 - i];
        }
    }

    return sum;
}

int main()
{
    int n;

    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    // Input square matrix.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << diagonalSum(matrix);

    return 0;
}