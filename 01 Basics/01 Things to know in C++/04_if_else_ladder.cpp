#include <bits/stdc++.h> // includes all standard libraries
using namespace std;

/*
    ===============================================
         IF / ELSE-IF LADDER – SIMPLE THEORY
    ===============================================

    ✔ Used when we need to check multiple conditions.
    ✔ Conditions are checked TOP → BOTTOM.
    ✔ As soon as one condition becomes TRUE,
      the rest are IGNORED.

    Example usage:
    - grading students
    - age categories
    - salary levels
    - temperature levels

    -----------------------------------------------
          GRADING LOGIC (Example)
          Marks → Grade
          0–24    → F
          25–44   → E
          45–49   → D
          50–59   → C
          60–79   → B
          80–100  → A
    -----------------------------------------------
*/

int main()
{
    cout << "Enter your marks: ";
    int marks;
    cin >> marks;

    cout << "Your marks are: " << marks << endl;

    // ---------------- IF-ELSE LADDER BEGINS ----------------

    if (marks < 0 || marks > 100)
    {
        cout << "Invalid marks! Please enter between 0 and 100." << endl;
    }
    else if (marks <= 24)
    {
        cout << "Grade: F" << endl;
    }
    else if (marks <= 44)
    {
        cout << "Grade: E" << endl;
    }
    else if (marks <= 49)
    {
        cout << "Grade: D" << endl;
    }
    else if (marks <= 59)
    {
        cout << "Grade: C" << endl;
    }
    else if (marks <= 79)
    {
        cout << "Grade: B" << endl;
    }
    else // marks 80–100
    {
        cout << "Grade: A" << endl;
    }

    // ---------------- IF-ELSE LADDER ENDS ----------------

    cout << "Thank You!" << endl;

    return 0;
}
