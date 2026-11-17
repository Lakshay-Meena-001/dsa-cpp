#include <bits/stdc++.h>
using namespace std;

/*
    ==============================================================
                     MIRRORED NUMBER TRIANGLE
    ==============================================================
    Example (rows = 4):

        1             1
        1 2         2 1
        1 2 3     3 2 1
        1 2 3 4 4 3 2 1

    Steps to solve:
    1️⃣ Loop through rows i = 1 to rows
    2️⃣ Print increasing numbers from 1 to i
    3️⃣ Print spaces in middle: spaces = 2 * (rows - i)
    4️⃣ Print decreasing numbers from i to 1
    5️⃣ Move to next line
    ==============================================================
*/

void printPattern(int rows)
{
    for (int i = 1; i <= rows; i++)
    {
        // Left increasing numbers
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }

        // Middle spaces calculated directly
        for (int j = 1; j <= 2 * (rows - i); j++)
        {
            cout << "  ";
        }

        // Right decreasing numbers
        for (int j = i; j >= 1; j--)
        {
            cout << j << " ";
        }

        cout << endl;
    }

    /*
        Sample Output (rows = 4):
        1             1
        1 2         2 1
        1 2 3     3 2 1
        1 2 3 4 4 3 2 1
    */
}

int main()
{
    int rows, testCases;

    cout << "Enter number of test cases: ";
    cin >> testCases;

    while (testCases--)
    {
        cout << "Enter number of rows: ";
        cin >> rows;

        cout << "\nPattern Output:\n";
        printPattern(rows);
    }

    return 0;
}
