#include <bits/stdc++.h>
using namespace std;

/*
MIRRORED HOLLOW TRIANGLE PATTERN

Example for rows = 4:

*      *
**    **
***  ***
********
***  ***
**    **
*      *

Logic/Steps:
1️⃣ The pattern has a top and bottom half forming a diamond-like mirror.
2️⃣ Iterate from i = 1 to 2*rows - 1 (top half and bottom half together)
   - Determine the number of stars for each row:
       • stars = i if i <= rows
       • stars = 2*rows - i if i > rows
   - Determine the number of spaces in the middle:
       • Start with sp = 2*rows - 2
       • Decrease by 2 until the middle row, then increase by 2
3️⃣ Print left stars, middle spaces, and right stars for each row.
4️⃣ Move to the next line after each row.
*/

void printPattern(int rows)
{
    int sp = 2 * rows - 2;

    for (int i = 1; i <= 2 * rows - 1; i++)
    {
        int stars = (i <= rows) ? i : 2 * rows - i;

        // Left stars
        for (int j = 1; j <= stars; j++)
            cout << '*';

        // Middle spaces
        for (int j = 1; j <= sp; j++)
            cout << ' ';

        // Right stars
        for (int j = 1; j <= stars; j++)
            cout << '*';

        cout << '\n';

        // Adjust spaces
        if (i < rows)
            sp -= 2;
        else
            sp += 2;
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
