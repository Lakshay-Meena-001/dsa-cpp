#include <iostream>
#include <vector>
using namespace std;

//--------------------------------------------------
// Problem : Difference Between Ones and Zeros
//           in Row and Column (LC 2482)
//
// Pattern : Row + Column Precomputation
//
// Time  : O(rows × cols)
// Space : O(rows + cols)
//
// Learning:
// 1. Row preprocessing
// 2. Column preprocessing
// 3. Reuse computed information
//--------------------------------------------------

vector<vector<int>> onesMinusZeros(const vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    vector<int> rowOnes(rows, 0);
    vector<int> rowZeros(rows, 0);

    vector<int> colOnes(cols, 0);
    vector<int> colZeros(cols, 0);

    //--------------------------------------------------
    // Count ones and zeros for every row.
    //--------------------------------------------------
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 1)
            {
                rowOnes[i]++;
            }
            else
            {
                rowZeros[i]++;
            }
        }
    }

    //--------------------------------------------------
    // Count ones and zeros for every column.
    //--------------------------------------------------
    for (int j = 0; j < cols; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            if (grid[i][j] == 1)
            {
                colOnes[j]++;
            }
            else
            {
                colZeros[j]++;
            }
        }
    }

    vector<vector<int>> answer(rows, vector<int>(cols));

    //--------------------------------------------------
    // Build answer matrix.
    //--------------------------------------------------
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            answer[i][j] = rowOnes[i] + colOnes[j] - rowZeros[i] - colZeros[j];
        }
    }

    return answer;
}

void printMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int value : row)
        {
            cout << value << " ";
        }

        cout << endl;
    }
}

int main()
{
    int rows, cols;

    cin >> rows >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> answer = onesMinusZeros(grid);

    printMatrix(answer);

    return 0;
}