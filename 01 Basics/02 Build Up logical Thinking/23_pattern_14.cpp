#include <bits/stdc++.h>
using namespace std;

/*
DECREASING ALPHABET TRIANGLE

Example for rows = 4:

A B C D
A B C
A B
A

Steps to solve:
1️⃣ Loop from i = 0 to rows-1
2️⃣ For each row, print characters from 'A' up to 'A' + (rows - i - 1)
3️⃣ Print a space after each character
4️⃣ Move to next line after printing each row
*/

void printPattern(int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (char ch = 'A'; ch < 'A' + (rows - i); ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
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
