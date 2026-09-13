#include <bits/stdc++.h>
using namespace std;

/*
    ==============================================================
                           PATTERN LOGIC
    ==============================================================
    Problem: Print an inverted right-angled triangle of stars

    Pattern Example (rows = 4):
    * * * *
    * * *
    * *
    *

    Steps to solve:
    1️⃣ Step 1: Count number of rows (outer loop)
    2️⃣ Step 2: For each row i, print (rows - i) stars (inner loop)
    3️⃣ Step 3: Move to the next line after each row
    4️⃣ Step 4: Repeat until all rows are printed

    Observation:
    - Column input is not required
    - Number of stars in each row decreases by 1
    ==============================================================
*/

void printPattern(int rows)
{
    for (int i = 0; i < rows; i++) // Outer loop for rows
    {
        for (int j = 0; j < rows - i; j++) // Inner loop prints decreasing stars
        {
            cout << "* ";
        }
        cout << endl;
    }

    /*
        Example:
        rows = 4
        Output:
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
