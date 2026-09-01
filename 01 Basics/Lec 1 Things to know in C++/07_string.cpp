#include <bits/stdc++.h> // includes all standard libraries
using namespace std;

/*
    ==============================================================
                            STRINGS – THEORY
    ==============================================================
    ✔ A string is a sequence of characters.
    ✔ Strings in C++ are objects of the 'string' class.
    ✔ Strings can be accessed like arrays (0-based indexing).
    ✔ Strings are dynamic: length can change during runtime.

    Common Operations:
    1️⃣ Input / Output
    2️⃣ Accessing characters
    3️⃣ Modifying characters
    4️⃣ Length / Size
    5️⃣ Concatenation
    6️⃣ Comparison
    7️⃣ Traversal

    ✔ Strings are heavily used in DSA for problems like:
        - Palindrome check
        - Substrings
        - Pattern matching
        - Text processing
    ==============================================================
*/

int main()
{
    // ----------------- INPUT STRING -----------------
    cout << "Enter a string: ";
    string str;
    getline(cin, str); // takes input with spaces
    cout << "You entered: " << str << endl;

    // ----------------- STRING ACCESS -----------------
    string s = "Hello World";
    cout << "First character: " << s[0] << endl;                // H
    cout << "Last character: " << s[s.length() - 1] << endl;   // d

    // ----------------- MODIFYING STRING -----------------
    s[s.length() - 1] = '!';   // replacing last character
    cout << "Modified string: " << s << endl;  // Hello Worl!

    // ----------------- STRING FUNCTIONS -----------------
    cout << "Length of string: " << s.length() << endl;
    cout << "Is string empty? " << (s.empty() ? "Yes" : "No") << endl;

    string s2 = " C++";
    // Concatenation
    string s3 = s + s2;
    cout << "Concatenated string: " << s3 << endl;

    // Traversal
    cout << "Characters in the string: ";
    for (char c : s)
    {
        cout << c << " ";
    }
    cout << endl;

    // Comparison
    string a = "apple", b = "banana";
    if (a == b)
        cout << "Strings are equal" << endl;
    else if (a < b)
        cout << a << " comes before " << b << endl;
    else
        cout << a << " comes after " << b << endl;

    return 0;
}
