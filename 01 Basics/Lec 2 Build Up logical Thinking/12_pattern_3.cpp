#include <bits/stdc++.h>
using namespace std;

/*
    ==============================================================
                           PATTERN LOGIC
    ==============================================================
    Problem: Print a number triangle

    Pattern Example (rows = 5):
    1
    1 2
    1 2 3
    1 2 3 4
    1 2 3 4 5

    Steps to solve:
    1️⃣ Step 1: Count number of rows (outer loop)
    2️⃣ Step 2: For each row, print numbers from 1 to current row number (inner loop)
    3️⃣ Step 3: Move to the next line after each row
    4️⃣ Step 4: Repeat until all rows are printed

    Observation: 
    - In row i, print numbers 1 to i
    - Column input is NOT needed for this pattern
    ==============================================================
*/

void printPattern(int rows)
{
    for (int i = 1; i <= rows; i++) // Outer loop for rows
    {
        for (int j = 1; j <= i; j++) // Inner loop prints numbers
        {
            cout << j << " ";
        }
        cout << endl;
    }

    /*
        Example:
        rows = 5
        Output:
        1
        1 2
        1 2 3
        1 2 3 4
        1 2 3 4 5
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
