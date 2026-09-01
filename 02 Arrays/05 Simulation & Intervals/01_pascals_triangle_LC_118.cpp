#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> result;

    for (int row = 0; row < numRows; row++)
    {
        // ek 1D vector lo usme row + 1 elements honge aur sabhi elements ko 1 se initialize karenge
        vector<int> currentRow(row + 1, 1);

        // Fill only the middle elements.
        for (int j = 1; j < row; j++)
        {
            currentRow[j] =
                result[row - 1][j - 1] +
                result[row - 1][j];
        }

        result.push_back(currentRow);
    }

    return result;
}

int main()
{
    int numRows = 5;

    vector<vector<int>> result = generate(numRows);

    for (const auto &row : result)
    {
        for (int value : row)
        {
            cout << value << " ";
        }

        cout << '\n';
    }

    return 0;
}