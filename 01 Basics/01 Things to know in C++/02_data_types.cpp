#include <bits/stdc++.h>
using namespace std;

/*
    ====================================================================
                    C++ DATATYPES – FULL BEGINNER GUIDE
    ====================================================================

    C++ datatypes are divided into 3 main groups:

    1) **PRIMARY / BUILT-IN / FUNDAMENTAL DATATYPES**
       → These are basic datatypes provided by the language.

    2) **DERIVED DATATYPES**
       → Made from primary datatypes.

    3) **USER-DEFINED DATATYPES**
       → Created by the programmer.

    --------------------------------------------------------------------
                    ***DSA-RELEVANT modern types included***
    --------------------------------------------------------------------
    - vector
    - pair
    - string
    - size_t
    --------------------------------------------------------------------

    NOTE:
    This covers everything needed for **DSA, interviews, and beginner learning**.
    No advanced, confusing, or unnecessary types included.
*/

int main() {

    /* ******************************************************************
                1) PRIMARY / FUNDAMENTAL DATATYPES
       ******************************************************************

       These are the basic built-in datatypes. Used everywhere.
    */

    int a = 10;                    // Normally used integer
    long b = 1000000L;             // Bigger integer
    long long c = 100000000000LL;  // Used in DSA for big values
    float f = 3.14f;               // Decimal (7 digits precision)
    double d = 3.1415926535;       // More precise decimal (15 digits)
    char ch = 'A';                 // Single character
    bool flag = true;              // true / false
    string s = "Hello";            // Text (dynamic)

    cout << "\n--- PRIMARY DATATYPES ---\n";
    cout << "int: " << a << endl;
    cout << "long: " << b << endl;
    cout << "long long: " << c << endl;
    cout << "float: " << f << endl;
    cout << "double: " << d << endl;
    cout << "char: " << ch << endl;
    cout << "bool: " << flag << endl;
    cout << "string: " << s << endl;



    /* ******************************************************************
                2) DERIVED DATATYPES
       ******************************************************************

       These are built using primary datatypes.

       Includes:
       ✔ Arrays
       ✔ Pointers
       ✔ References
       ✔ Functions
       ✔ Function Pointers (not needed for beginners)
    */

    cout << "\n--- DERIVED DATATYPES ---\n";

    // ----- 1) ARRAY -----
    // Fixed size collection of same type
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Array element arr[2] = " << arr[2] << endl;

    // ----- 2) POINTER -----
    // Stores address of a variable
    int x = 50;
    int* ptr = &x;      // pointer to int
    cout << "Pointer value (*ptr) = " << *ptr << endl;
    cout << "Pointer address (&x) = " << ptr << endl;

    // ----- 3) REFERENCE -----
    // Another name for a variable
    int y = 100;
    int &ref = y;
    cout << "Reference value: " << ref << endl;

    // ----- 4) FUNCTION -----
    // A block of code that runs when called (see note: main() itself is function)

    // ----- 5) FUNCTION POINTER (NOT required for beginner or DSA)
    // So skipping.



    /* ******************************************************************
                3) USER-DEFINED DATATYPES
       ******************************************************************

       Created using C++ keywords.

       Includes:
       ✔ struct
       ✔ class
       ✔ enum
       ✔ union
       ✔ typedef
    */

    cout << "\n--- USER-DEFINED DATATYPES ---\n";

    // ----- 1) STRUCT -----
    // Used to group different datatypes together
    struct Student {
        string name;
        int age;
    };

    Student st = {"Rahul", 20};
    cout << "Struct Example → " << st.name << ", " << st.age << endl;

    // ----- 2) CLASS -----
    // Same as struct but members private by default
    class Car {
    public:
        string model;
        int year;
    };

    Car c1;
    c1.model = "BMW";
    c1.year = 2020;
    cout << "Class Example → " << c1.model << ", " << c1.year << endl;

    // ----- 3) ENUM -----
    // Stores fixed set of integer values
    enum Day { MON, TUE, WED, THU, FRI };
    Day today = WED;
    cout << "Enum Example (WED as number): " << today << endl;

    // ----- 4) UNION -----
    // Shares memory between members (only one used at a time)
    union Money {
        int coins;
        float amount;
    };

    Money m;
    m.coins = 50;        
    cout << "Union Example → Coins: " << m.coins << endl;

    // ----- 5) TYPEDEF -----
    // Gives nickname to datatype (useful for readability)
    typedef long long ll;
    ll big = 999999999LL;
    cout << "typedef Example → ll value: " << big << endl;



    /* ******************************************************************
                MODERN & SPECIAL (Only DSA-Relevant)
       ******************************************************************
       Modern C++ has many datatypes, but only a few are important
       for **DSA and interview coding**.

       ✔ vector         → dynamic array
       ✔ pair           → store two values
       ✔ size_t         → used for index, size
       ✔ nullptr        → modern null pointer keyword
    */

    cout << "\n--- MODERN + SPECIAL (DSA RELEVANT) ---\n";

    // ----- VECTOR -----
    // Dynamic array that grows automatically (MOST used in DSA)
    vector<int> v = {1, 2, 3};
    cout << "Vector first element: " << v[0] << endl;

    // ----- PAIR -----
    pair<int, string> p = {1, "One"};
    cout << "Pair Example → " << p.first << ", " << p.second << endl;

    // ----- SIZE_T -----
    // Used for sizes of containers (always non-negative)
    size_t sz = v.size();
    cout << "size_t Example → vector size: " << sz << endl;

    // ----- nullptr -----
    int* p2 = nullptr;   // better than using NULL
    cout << "nullptr Example → pointer = " << p2 << endl;


    return 0;
}
