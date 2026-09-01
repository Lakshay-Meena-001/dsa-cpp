#include <bits/stdc++.h>
using namespace std;

/*
    ==============================================================
                     CONTINUOUS NUMBER TRIANGLE
    ==============================================================
    Example (rows = 5):

    1
    2 3
    4 5 6
    7 8 9 10
    11 12 13 14 15

    Steps to solve:
    1️⃣ Initialize num = 1 (starting number)
    2️⃣ Loop through rows i = 1 to rows
    3️⃣ For each row, print i numbers and increment num after printing
    4️⃣ Move to next line
    ==============================================================
*/

void printPattern(int rows)
{
    int num = 1; // starting number

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << num++ << " ";
        }
        cout << endl;
    }

    /*
        Sample Output (rows = 5):
        1
        2 3
        4 5 6
        7 8 9 10
        11 12 13 14 15
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
