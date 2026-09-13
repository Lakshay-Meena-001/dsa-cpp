#include <bits/stdc++.h>
using namespace std;

/*
ALPHABET TRIANGLE WITH REPEATED LETTERS

Example for rows = 4:

A
B B
C C C
D D D D

Steps to solve:
1️⃣ Loop from i = 0 to rows-1
2️⃣ For each row, determine the character as 'A' + i
3️⃣ Print that character (i + 1) times with a space
4️⃣ Move to the next line after printing each row
*/

void printPattern(int rows)
{
    for (int i = 0; i < rows; i++)
    {
        char ch = 'A' + i;
        for (int j = 0; j <= i; j++)
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
