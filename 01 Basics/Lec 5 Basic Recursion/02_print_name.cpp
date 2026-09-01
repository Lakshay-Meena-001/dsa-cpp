#include <iostream>
using namespace std;

void printName(int n, string name) {
    // Base Case
    if (n == 0) {
        return;
    }

    // Recursive Case
    printName(n - 1, name);

    // Work after recursion
    cout << name << endl;
}

int main() {
    int n;
    string name;

    cout << "Enter a name: ";
    cin >> name;

    cout << "Enter how many times to print: ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative number.";
        return 0;
    }

    printName(n, name);

    return 0;
}

/*
---------------------------------------------------
           RECURSION THEORY FOR THIS CODE
---------------------------------------------------

1. What is Recursion?
   - Recursion means a function calling itself
     to solve smaller versions of the same problem.

2. Two Required Parts in Recursion:
   a) Base Case
      - The point where recursion must stop.
      - In this code: if (n == 0) return;

   b) Recursive Case
      - The self-call with a smaller input.
      - printName(n - 1, name);

3. Logic Used:
   - To print a name 'n' times:
         printName(n)
             calls printName(n-1)
             calls printName(n-2)
             ...
             until n becomes 0 (base case)

4. Flow Example:
   For n = 3:
       printName(3)
          → printName(2)
             → printName(1)
                → printName(0) → stops
   Then printing happens while coming back:
       name
       name
       name

5. Why This Works:
   - Each recursive call reduces n by 1.
   - When we reach the smallest problem (n = 0),
     recursion stops and then prints while returning.

6. Important Notes:
   - Base case prevents infinite recursion.
   - Input must move towards the base case.
   - Recursion helps solve repetitive tasks cleanly.

---------------------------------------------------
*/
