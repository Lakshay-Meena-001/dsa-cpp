#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Problem : 28_Lucky_Numbers_In_A_Matrix_LC_1380.cpp
// Pattern : Precomputation
// Approach :
// 1. Find minimum element of every row.
// 2. Find maximum element of every column.
// 3. Traverse matrix and check whether
//    current element is row minimum
//    as well as column maximum.
//
// Time  : O(rows × cols)
// Space : O(rows + cols)
//
// Learning:
// 1. Row Minimum Precomputation
// 2. Column Maximum Precomputation
// 3. Compare Precomputed Information

vector<int> luckyNumbers(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> rowMin(rows, INT_MAX);
    vector<int> colMax(cols, INT_MIN);

    //--------------------------------------------------
    // Pass 1 : Find minimum of every row.
    //--------------------------------------------------

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            rowMin[i] = min(rowMin[i], matrix[i][j]);
        }
    }

    //--------------------------------------------------
    // Pass 2 : Find maximum of every column.
    //--------------------------------------------------

    for (int j = 0; j < cols; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            colMax[j] = max(colMax[j], matrix[i][j]);
        }
    }

    //--------------------------------------------------
    // Pass 3 : Find Lucky Numbers.
    //--------------------------------------------------

    vector<int> answer;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == rowMin[i] &&
                matrix[i][j] == colMax[j])
            {
                answer.push_back(matrix[i][j]);
            }
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

    vector<int> answer = luckyNumbers(matrix);

    for (int value : answer)
    {
        cout << value << " ";
    }

    return 0;
}