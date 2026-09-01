#include <bits/stdc++.h>
using namespace std;

/*
    ==============================================================
                           PATTERN LOGIC
    ==============================================================
    Problem: Print a centered pyramid of stars

    Example Pattern (rows = 4):
           * 
         * * * 
       * * * * * 
     * * * * * * * 

    Steps to solve:
    1️⃣ Step 1: Outer loop runs from i = 0 to rows-1
    2️⃣ Step 2: Print spaces before stars: rows - i - 1 spaces
    3️⃣ Step 3: Print stars: (2 * i + 1) stars in each row
    4️⃣ Step 4: Move to next line after each row

    Observation:
    - No cols input required
    - The number of stars increases by 2 each row
    - Spaces decrease by 1 each row
    ==============================================================
*/

void printPattern(int rows)
{
    for (int i = 0; i < rows; i++) // Outer loop for rows
    {
        // Print leading spaces
        for (int j = 0; j < rows - i - 1; j++)
        {
            cout << "  "; // 2 spaces for alignment
        }

        // Print stars
        for (int j = 0; j < (2 * i + 1); j++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    /*
        Example: rows = 4
        Output:
               * 
             * * * 
           * * * * * 
         * * * * * * * 
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
