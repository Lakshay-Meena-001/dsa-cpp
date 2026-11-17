#include <bits/stdc++.h>
using namespace std;

/*
    ==============================================================
                         DIAMOND-LIKE STAR PATTERN
    ==============================================================
    Problem: Print a pattern that increases then decreases
    Example (rows = 5):

    *
    * *
    * * *
    * * * *
    * * * * *
    * * * *
    * * *
    * *
    *

    Steps to solve:
    1️⃣ Outer loop runs i from 0 to 2*rows-2 (total lines)
    2️⃣ Determine stars to print in current line:
       - If i < rows: stars = i + 1
       - Else: stars = 2*rows - i - 1
    3️⃣ Inner loop prints stars for current line
    4️⃣ Move to next line
    ==============================================================
*/

void printPattern(int rows)
{

    for (int i = 1; i <= 2 * rows - 1; i++)
    {
        int stars = i <= rows ? i : 2 * rows - i;

        for (int j = 1; j <= stars; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    /*
        Example: rows = 5
        Output:
        *
        * *
        * * *
        * * * *
        * * * * *
        * * * *
        * * *
        * *
        *
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
