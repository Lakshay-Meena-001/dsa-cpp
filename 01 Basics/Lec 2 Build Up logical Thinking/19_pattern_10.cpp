#include <bits/stdc++.h>
using namespace std;

/*
    ==============================================================
                         0-1 TRIANGLE PATTERN
    ==============================================================
    Example (rows = 5):

    1
    0 1
    1 0 1
    0 1 0 1
    1 0 1 0 1

    Steps to solve:
    1️⃣ Loop through rows i = 0 to rows-1
    2️⃣ Determine starting value of row:
       - if row index i is even, start = 1
       - if row index i is odd, start = 0
    3️⃣ Inner loop runs j = 0 to i, print current value
    4️⃣ Alternate value using: start = 1 - start
    5️⃣ Move to next line
    ==============================================================
*/

void printPattern(int rows)
{
    for (int i = 0; i < rows; i++)
    {
        int start = (i % 2 == 0) ? 1 : 0; // Decide starting value

        for (int j = 0; j <= i; j++)
        {
            cout << start << " ";
            start = 1 - start; // Alternate 0 and 1
        }
        cout << endl;
    }

    /*
        Example: rows = 5
        Output:
        1
        0 1
        1 0 1
        0 1 0 1
        1 0 1 0 1
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
