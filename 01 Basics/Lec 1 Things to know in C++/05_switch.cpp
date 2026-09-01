#include <bits/stdc++.h> // includes all standard libraries
using namespace std;

/*
    ==================================================================
                         SWITCH–CASE THEORY
    ==================================================================
    ✔ switch is used when you need to compare ONE variable
      with MULTIPLE constant values.

    ✔ It is cleaner and faster than multiple if–else statements,
      especially when your conditions are simple fixed values.

    ✔ Each "case" must end with a 'break' to avoid FALL-THROUGH.
      (Without break, the next cases will also run.)

    ✔ 'default' runs when no case matches (like else).

    ------------------------------------------------------------------
    Interview Tip:
    - switch works only with:
        int, char, enum, short, long (integral types)
      (NOT with strings or floating values)
    ------------------------------------------------------------------
*/

int main()
{
    cout << "Enter a day number (1-7): ";
    int day;
    cin >> day;

    // ----------------- SWITCH–CASE BEGINS -----------------

    switch (day)
    {
    case 1:
        cout << "Monday";
        break;   // stops execution here

    case 2:
        cout << "Tuesday";
        break;

    case 3:
        cout << "Wednesday";
        break;

    case 4:
        cout << "Thursday";
        break;

    case 5:
        cout << "Friday";
        break;

    case 6:
        cout << "Saturday";
        break;

    case 7:
        cout << "Sunday";
        break;

    default:
        // runs if day is NOT 1–7
        cout << "Invalid Input! Please enter a number from 1 to 7.";
    }

    // ----------------- SWITCH–CASE ENDS -----------------

    return 0;
}
