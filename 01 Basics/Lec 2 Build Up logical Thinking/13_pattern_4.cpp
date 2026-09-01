#include <bits/stdc++.h>
using namespace std;

/*
    ==============================================================
                           PATTERN LOGIC
    ==============================================================
    Problem: Print a number triangle where each row contains
             the same number repeated

    Pattern Example (rows = 5):
    1
    2 2
    3 3 3
    4 4 4 4
    5 5 5 5 5

    Steps to solve:
    1️⃣ Step 1: Count number of rows (outer loop)
    2️⃣ Step 2: For each row i, print the number i (inner loop)
               repeated i times
    3️⃣ Step 3: Move to the next line after each row
    4️⃣ Step 4: Repeat until all rows are printed

    Observation:
    - Column input is not required
    - Row number equals the value printed in that row
    ==============================================================
*/

void printPattern(int rows)
{
    for (int i = 1; i <= rows; i++) // Outer loop for rows
    {
        for (int j = 1; j <= i; j++) // Inner loop prints same number i
        {
            cout << i << " ";
        }
        cout << endl;
    }

    /*
        Example:
        rows = 5
        Output:
        1
        2 2
        3 3 3
        4 4 4 4
        5 5 5 5 5
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
