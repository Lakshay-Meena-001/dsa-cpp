#include <bits/stdc++.h>
using namespace std;

/*
    ==============================================================
                             PATTERN LOGIC – SHORTCUT
    ==============================================================
    1️⃣ Step 1: Count number of rows (outer loop)
    2️⃣ Step 2: Count number of columns or elements in each row (inner loop)
    3️⃣ Step 3: Decide what to print (*, numbers, spaces, etc.)
    4️⃣ Step 4: Observe symmetry, increasing/decreasing values
    5️⃣ Step 5: Use conditions in inner loop for advanced patterns

    ⭐ Interview Tip:
    - Outer loop = row count
    - Inner loop = content of each row
    - Use formula or condition for numbers/spaces
    ==============================================================
*/

// ----------------- SIMPLE RECTANGLE PATTERN -----------------
void rectanglePattern(int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    /*
        Example:
        rows = 3, cols = 4
        Output:
        * * * * 
        * * * * 
        * * * * 
    */
}

// ----------------- RIGHT-ANGLED TRIANGLE PATTERN -----------------
void rightAngledTriangle(int n)
{
    for (int i = 1; i <= n; i++) // row count
    {
        for (int j = 1; j <= i; j++) // elements in row
        {
            cout << "* ";
        }
        cout << endl;
    }

    /*
        Example:
        n = 4
        Output:
        * 
        * * 
        * * * 
        * * * * 
    */
}

// ----------------- INVERTED TRIANGLE PATTERN -----------------
void invertedTriangle(int n)
{
    for (int i = n; i >= 1; i--) // row count
    {
        for (int j = 1; j <= i; j++) // elements in row
        {
            cout << "* ";
        }
        cout << endl;
    }

    /*
        Example:
        n = 4
        Output:
        * * * * 
        * * * 
        * * 
        * 
    */
}

int main()
{
    int testCases;
    cout << "Enter number of test cases: ";
    cin >> testCases;

    while (testCases--)
    {
        int rows, cols;
        cout << "\nEnter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        cout << "\nRectangle Pattern:\n";
        rectanglePattern(rows, cols);

        cout << "\nRight-Angled Triangle Pattern:\n";
        rightAngledTriangle(rows);

        cout << "\nInverted Triangle Pattern:\n";
        invertedTriangle(rows);
    }

    return 0;
}
