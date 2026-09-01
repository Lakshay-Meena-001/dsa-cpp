#include <bits/stdc++.h>
using namespace std;

/*
CONCENTRIC NUMBER RECTANGLE PATTERN

Example for rows = 4, cols = 4:

4 4 4 4 4 4 4
4 3 3 3 3 3 4
4 3 2 2 2 3 4
4 3 2 1 2 3 4
4 3 2 2 2 3 4
4 3 3 3 3 3 4
4 4 4 4 4 4 4

Logic/Steps:
1️⃣ Total rows in output = 2*rows - 1, total cols = 2*cols - 1.
2️⃣ For each cell, calculate distance from all four edges:
   top = i, left = j, right = (2*cols-2)-j, bottom = (2*rows-2)-i.
3️⃣ Value at each cell = rows - min(top, bottom, left, right)
4️⃣ Print the value for each cell, then move to next row.
*/

void printPattern(int rows, int cols)
{
    for (int i = 0; i < 2 * rows - 1; i++)
    {
        for (int j = 0; j < 2 * cols - 1; j++)
        {
            int top = i;
            int left = j;
            int right = (2 * cols - 2) - j;
            int bottom = (2 * rows - 2) - i;

            int val = rows - min({top, bottom, left, right});
            cout << val << " ";
        }
        cout << '\n';
    }
}

int main()
{
    int rows, cols, testCases;

    cout << "Enter number of test cases: ";
    cin >> testCases;

    while (testCases--)
    {
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;
        cout << "\nPattern Output:\n";
        printPattern(rows, cols);
    }

    return 0;
}
