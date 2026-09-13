#include <bits/stdc++.h> // includes all standard libraries
using namespace std;

/*
    ==============================================================
                             FUNCTIONS – THEORY
    ==============================================================
    ✔ A function is a block of code that performs a specific task.
    ✔ Functions help in:
        - Code reusability
        - Modular programming
        - Easier debugging
    ✔ Function Types:
        1️⃣ void function: Does not return any value
        2️⃣ return type function: Returns a value (int, float, string, etc.)
    
    ✔ Function Parameter Passing:
        - Pass by Value: Copies the value. Original variable is NOT changed
        - Pass by Reference: Passes the address. Original variable CAN change
    ✔ Functions are heavily used in DSA for:
        - Repeated operations on arrays/vectors
        - Recursion (factorial, fibonacci, tree traversal)
        - Utility/helper functions
    ==============================================================
*/

// ----------------- PASS BY VALUE -----------------
void printName(string str)
{
    // The original string in main() is NOT changed
    cout << "Your name is: " << str << endl;
}

// ----------------- PASS BY REFERENCE -----------------
int sum2(int &n1, int &n2)
{
    // Changes here affect original variables in main()
    n1 += 5;
    n2 += 5;
    return n1 + n2;
}

int main()
{
    // ----------------- FUNCTION EXAMPLES -----------------

    // Example 1: Pass by Value
    string s;
    cout << "Enter your name: ";
    getline(cin, s); // input string with spaces
    printName(s);    // call function

    // Example 2: Pass by Reference
    cout << "Enter 2 numbers: ";
    int n1, n2;
    cin >> n1 >> n2;

    int addition = sum2(n1, n2); // original n1 and n2 are modified
    cout << "The sum of 2 numbers after modification is: " << addition << endl;
    cout << "Modified n1 = " << n1 << ", n2 = " << n2 << endl;

    return 0;
}
