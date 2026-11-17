#include <bits/stdc++.h>
using namespace std;

/*
HOLLOW DIAMOND STAR PATTERN

Example for rows = 4:

********
***  ***
**    **
*      *
**    **
***  ***
********

Logic/Steps:
1️⃣ The pattern has two halves: top and bottom.
2️⃣ Top half: iterate from i = rows down to 1
   - Print stars for the left block (boundary only if not full row)
   - Print spaces in the middle
   - Print stars for the right block (same as left)
3️⃣ Bottom half: iterate from i = 2 up to rows
   - Same logic as top half
4️⃣ Move to the next line after each row.
*/

void printPattern(int rows)
{
    if (rows <= 0)
    {
        return;
    }

    for (int i = rows; i >= 1; i--)
    {
        // Left stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        // Middle spaces
        for (int j = 1; j <= 2 * (rows - i); j++)
        {
            cout << " ";
        }

        // Right stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        cout << endl;
    }

    for (int i = 2; i <= rows; i++)
    {
        // Left stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        // Middle spaces
        for (int j = 1; j <= 2 * (rows - i); j++)
        {
            cout << " ";
        }

        // Right stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
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
