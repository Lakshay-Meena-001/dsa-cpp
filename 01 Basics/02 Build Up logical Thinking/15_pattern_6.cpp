#include <bits/stdc++.h>
using namespace std;

/*
    ==============================================================
                           PATTERN LOGIC
    ==============================================================
    Problem: Print an inverted right-angled triangle of numbers

    Pattern Example (rows = 5):
    1 2 3 4 5
    1 2 3 4
    1 2 3
    1 2
    1

    Steps to solve:
    1️⃣ Step 1: Count number of rows (outer loop)
    2️⃣ Step 2: For each row i, print numbers from 1 to (rows - i) (inner loop)
    3️⃣ Step 3: Move to the next line after each row
    4️⃣ Step 4: Repeat until all rows are printed

    Observation:
    - Column input is not required
    - Numbers decrease per row
    ==============================================================
*/

void printPattern(int rows)
{
    for (int i = 0; i < rows; i++) // Outer loop for rows
    {
        for (int j = 1; j <= rows - i; j++) // Inner loop prints numbers 1 to rows-i
        {
            cout << j << " ";
        }
        cout << endl;
    }

    /*
        Example:
        rows = 5
        Output:
        1 2 3 4 5
        1 2 3 4
        1 2 3
        1 2
        1
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
