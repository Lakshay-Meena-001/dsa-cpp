#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex)
{
    vector<int> currentRow(1, 1);

    for (int row = 1; row <= rowIndex; row++)
    {
        vector<int> nextRow(row + 1, 1);

        for (int j = 1; j < row; j++)
        {
            nextRow[j] =currentRow[j - 1] +currentRow[j];
        }

        currentRow = nextRow;
    }

    return currentRow;
}

int main()
{
    int rowIndex = 4;

    vector<int> result = getRow(rowIndex);

    for (int value : result)
    {
        cout << value << " ";
    }

    cout << '\n';

    return 0;
}
