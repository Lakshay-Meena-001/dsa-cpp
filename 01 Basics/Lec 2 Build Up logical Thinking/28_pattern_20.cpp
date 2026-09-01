#include <bits/stdc++.h>
using namespace std;

/*
HOLLOW RECTANGLE PATTERN

Example for rows = 4, cols = 4:

* * * *
*     *
*     *
* * * *

Logic/Steps:
1️⃣ Iterate through each row (i = 1 to rows).
2️⃣ Iterate through each column (j = 1 to cols).
3️⃣ Print '*' if:
   • It is the first or last row (i == 1 or i == rows)
   • It is the first or last column (j == 1 or j == cols)
   Otherwise, print a space ' '.
4️⃣ Move to the next line after each row.
*/

void printPattern(int rows, int cols)
{
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= cols; j++)
        {
            if (i == 1 || j == 1 || i == rows || j == cols)
                cout << "*" << " ";
            else
                cout << "  ";
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
