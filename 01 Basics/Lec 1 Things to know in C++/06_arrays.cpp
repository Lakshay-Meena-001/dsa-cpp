#include <bits/stdc++.h> // includes all standard libraries
using namespace std;

/*
    ==============================================================
                             ARRAYS – THEORY
    ==============================================================
    ✔ Array is a collection of elements of the same data type.
    ✔ Elements are stored in contiguous memory locations.
    ✔ Indexing starts from 0.
    ✔ Useful in DSA for storing multiple values and performing operations.

    1️⃣ 1D Array:
        - Stores elements in a single line.
        - Access using arr[index].

    2️⃣ 2D Array:
        - Matrix-like structure with rows and columns.
        - Access using arr[row][column].

    ✔ Common Operations:
        - Traversal
        - Update
        - Search
        - Sum / Average
    ==============================================================
*/

int main()
{
    // ----------------- 1D ARRAY -----------------
    cout << "Enter 4 elements for a 1D array: ";
    int arr[4]; // declaring an array of size 4

    // Taking input using loop (better than writing separately)
    for (int i = 0; i < 4; i++)
    {
        cin >> arr[i];
    }

    // Printing array elements
    cout << "1D Array elements are: ";
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // ----------------- 2D ARRAY -----------------
    int arr2D[2][2] = {{1, 2}, {3, 4}}; // 2x2 matrix

    // Printing 2D array
    cout << "2D Array elements are: " << endl;
    for (int i = 0; i < 2; i++)       // loop for rows
    {
        for (int j = 0; j < 2; j++)   // loop for columns
        {
            cout << arr2D[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
