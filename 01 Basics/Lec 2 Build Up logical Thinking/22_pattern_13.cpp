#include <bits/stdc++.h>
using namespace std;

/*
    ==============================================================
                     ALPHABET TRIANGLE
    ==============================================================
    Example (rows = 4):

    A
    A B
    A B C
    A B C D

    Steps to solve:
    1️⃣ Loop through rows i = 1 to rows
    2️⃣ For each row, print characters from 'A' to ('A' + i - 1)
    3️⃣ Print a space after each character
    4️⃣ Move to next line after each row
    ==============================================================
*/

void printPattern(int rows)
{
    for (int i = 1; i <= rows; i++)
    {
        for (char ch = 'A'; ch < 'A' + i; ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }

    /*
        Sample Output (rows = 4):
        A
        A B
        A B C
        A B C D
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
