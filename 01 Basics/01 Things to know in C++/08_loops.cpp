#include <bits/stdc++.h> // includes all standard libraries
using namespace std;

/*
    ==============================================================
                             LOOPS – THEORY
    ==============================================================
    ✔ Loops are used to repeat a block of code multiple times.
    ✔ They help avoid writing repetitive code.
    ✔ Common types:
        1️⃣ for loop      : Known number of iterations
        2️⃣ while loop    : Condition checked before each iteration
        3️⃣ do-while loop : Condition checked after each iteration

    ✔ Loops are heavily used in DSA for:
        - Array / vector traversal
        - Searching & sorting
        - Pattern printing
        - Repeated computations
    ==============================================================
*/

int main()
{
    // ----------------- FOR LOOP -----------------
    // Used when we know how many times we want to repeat
    cout << "For loop output (0 to 10): ";
    for (int i = 0; i <= 10; i++)
    {
        cout << i << " ";
    }
    cout << endl;

    // ----------------- WHILE LOOP -----------------
    // Used when we may not know exact number of iterations
    cout << "While loop output (0 to 10): ";
    int i = 0;
    while (i <= 10)
    {
        cout << i << " ";
        i++;
    }
    cout << endl;

    // ----------------- DO-WHILE LOOP -----------------
    // Executes at least once even if condition is false
    cout << "Do-while loop output (0 to 10): ";
    int x = 0;
    do
    {
        cout << x << " ";
        x++;
    } while (x <= 10);
    cout << endl;

    // ----------------- INTERVIEW TIP -----------------
    // 1. For loop is preferred for counting and fixed iterations
    // 2. While loop is preferred when iteration depends on a condition
    // 3. Do-while loop is useful for menus or prompts that must run once

    return 0;
}
