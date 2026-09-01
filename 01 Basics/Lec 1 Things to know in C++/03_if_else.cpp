#include <bits/stdc++.h> // includes all standard libraries (good for CP)
using namespace std;

/*
    =====================================================================
                        IF / ELSE / ELSE-IF THEORY
    =====================================================================

    ✔ if statement:
        - Checks a condition.
        - Runs code ONLY if the condition is TRUE.

    ✔ else statement:
        - Runs only when the above 'if' condition is FALSE.

    ✔ else-if ladder:
        - Used when there are MULTIPLE conditions to check.
        - Conditions are checked one by one from TOP → BOTTOM.
        - As soon as one condition becomes TRUE, remaining are skipped.

    ---------------------------------------------------------------------
    INTERVIEW NOTES:
    - Only one block runs in the ladder.
    - Conditions must be in correct order (most specific → least specific).
    - Else block is optional.
    - Good for marking ranges (age groups, grades, salary, etc.)
    ---------------------------------------------------------------------
*/

int main()
{
    // -------------------- SIMPLE IF–ELSE EXAMPLE --------------------
    cout << "Enter your age: ";
    int age;
    cin >> age;

    cout << "Your age is: " << age << endl;

    if (age >= 18)                     // condition 1
    {
        cout << "You are an adult." << endl;
    }
    else                               // runs when age < 18
    {
        cout << "You are a minor." << endl;
    }



    // -------------------- ELSE-IF LADDER (BEGINNER EXAMPLE) --------------------
    /*
        Checking Age Category:

        age < 13         → Child
        13 to 19         → Teenager
        20 to 59         → Adult
        60 or above      → Senior Citizen
    */

    cout << "\nChecking age category..." << endl;

    if (age < 13)
    {
        cout << "Category: Child" << endl;
    }
    else if (age >= 13 && age <= 19)
    {
        cout << "Category: Teenager" << endl;
    }
    else if (age >= 20 && age <= 59)
    {
        cout << "Category: Adult" << endl;
    }
    else   // age >= 60
    {
        cout << "Category: Senior Citizen" << endl;
    }



    // -------------------- ANOTHER COMMON INTERVIEW EXAMPLE --------------------
    // Grading system based on marks

    cout << "\nEnter your marks (0-100): ";
    int marks;
    cin >> marks;

    cout << "Your marks: " << marks << endl;

    if (marks >= 90)
        cout << "Grade: A" << endl;
    else if (marks >= 75)
        cout << "Grade: B" << endl;
    else if (marks >= 50)
        cout << "Grade: C" << endl;
    else if (marks >= 33)
        cout << "Grade: D" << endl;
    else
        cout << "Grade: FAIL" << endl;



    cout << "\nThank You!" << endl;

    return 0;
}
