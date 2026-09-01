#include <bits/stdc++.h>
using namespace std;

/*
    ==============================================================
                           INVERTED PYRAMID STAR
    ==============================================================
    Problem: Print an inverted centered pyramid of stars

    Example Pattern (rows = 5):
    * * * * * * *
      * * * * *
        * * *
         * *
          *

    Steps to solve:
    1️⃣ Outer loop runs from i = 0 to rows-1
    2️⃣ Print leading spaces: i spaces (2 spaces each for alignment)
    3️⃣ Print stars: (2*(rows - i) - 1) stars
    4️⃣ Move to next line after each row

    Observation:
    - No cols input required
    - Number of stars decreases by 2 each row
    - Spaces increase by 1 each row
    ==============================================================
*/

void printPattern(int rows)
{
    for (int i = 0; i < rows; i++) // Outer loop for rows
    {
        // Print leading spaces
        for (int j = 0; j < i; j++)
        {
            cout << "  "; // 2 spaces for alignment
        }

        // Print stars
        for (int j = 0; j < 2 * (rows - i) - 1; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    /*
        Example: rows = 5
        Output:
        * * * * * * *
          * * * * *
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
