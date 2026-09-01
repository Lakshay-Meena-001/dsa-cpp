#include <bits/stdc++.h>
using namespace std;

/*
ALPHABET PYRAMID

Pattern for rows = 4:

      A
    A B A
  A B C B A
A B C D C B A

Steps to solve:
1️⃣ Loop from i = 0 to rows-1
2️⃣ Print leading spaces: rows - i - 1
3️⃣ Print ascending characters from 'A' to the peak
4️⃣ Print descending characters from the peak back to 'A'
5️⃣ Move to next line after each row
*/

void printPattern(int rows)
{
    for (int i = 0; i < rows; i++)
    {
        // Step 2: print leading spaces
        for (int j = 0; j < rows - i - 1; j++)
            cout << "  ";

        char ch = 'A';
        int breakPoint = (2 * i + 1) / 2;

        // Step 3 & 4: print ascending and descending characters
        for (int j = 1; j <= 2 * i + 1; j++)
        {
            cout << ch << " ";
            if (j <= breakPoint)
            {
                ch++;
            }
            else
            {
                ch--;
            }
        }

        // Step 5: move to next line
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
