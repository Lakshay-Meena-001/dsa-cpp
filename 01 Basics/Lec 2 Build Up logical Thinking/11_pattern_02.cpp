#include <bits/stdc++.h>
using namespace std;

/*
    ==============================================================
                           PATTERN LOGIC
    ==============================================================
    Problem: Print a right-angled triangle of stars

    Pattern Example (rows = 4):
    *
    * *
    * * *
    * * * *

    Steps to solve:
    1️⃣ Step 1: Count number of rows (outer loop)
    2️⃣ Step 2: For each row, print stars equal to the current row number (inner loop)
    3️⃣ Step 3: Move to the next line after each row
    4️⃣ Step 4: Repeat until all rows are printed

    Observation: 
    - In row i, print i stars
    - No need for column input for this specific pattern
    ==============================================================
*/

void printPattern(int rows)
{
    for (int i = 1; i <= rows; i++) // Outer loop for rows
    {
        for (int j = 1; j <= i; j++) // Inner loop prints stars in each row
        {
            cout << "* ";
        }
        cout << endl;
    }

    /*
        Example:
        rows = 4
        Output:
        *
        * *
        * * *
        * * * *
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
