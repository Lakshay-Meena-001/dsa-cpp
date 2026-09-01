#include <iostream>
#include <vector>
using namespace std;

// Problem : _Spiral_Matrix_LC_54
// Pattern : Boundary Shrinking + Simulation
//
// Time  : O(rows × cols)
// Space : O(1) (Ignoring output array)
//
// Learning:
// 1. Four Boundary Pointers
// 2. Boundary Shrinking
// 3. Simulation

vector<int> spiralOrder(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> answer;

    // Four boundaries.

    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;

    // Continue until boundaries cross each other.

    while (top <= bottom && left <= right)
    {
        // Traverse Top Row.

        for (int j = left; j <= right; j++)
        {
            answer.push_back(matrix[top][j]);
        }

        // Top row is finished.
        top++;

        // Traverse Right Column.

        for (int i = top; i <= bottom; i++)
        {
            answer.push_back(matrix[i][right]);
        }

        // Right column is finished.
        right--;

        // Traverse Bottom Row.
        // Check boundary to avoid duplicates.

        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
            {
                answer.push_back(matrix[bottom][j]);
            }

            bottom--;
        }

        // Traverse Left Column.
        // Check boundary to avoid duplicates.

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                answer.push_back(matrix[i][left]);
            }

            left++;
        }
    }

    return answer;
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

    vector<int> answer = spiralOrder(matrix);

    for (int value : answer)
    {
        cout << value << " ";
    }

    return 0;
}