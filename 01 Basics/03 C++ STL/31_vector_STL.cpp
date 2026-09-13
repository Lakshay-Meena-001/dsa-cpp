#include <bits/stdc++.h>
using namespace std;

/*
    ============================== VECTOR THEORY (DSA) ==============================
    ✔ Vector is a Dynamic Array (Resizable Array)
    ✔ Stores elements in contiguous memory (like array)
    ✔ Random access is O(1)
    ✔ Insertion/Deletion at end → O(1) amortized
    ✔ Insertion/Deletion in the middle → O(N)
    ✔ Automatically doubles capacity when full

    Common Uses in DSA:
    - Dynamic lists
    - Graph adjacency lists
    - Storing answers / dynamic DP tables
    - Efficient iteration and random access
    ================================================================================ 
*/

void explainVector() {

    /*
        --------------------- INITIALIZATION EXAMPLES ---------------------
    */

    vector<int> v = {1, 2, 3, 4, 5};       // Example: Direct initialization
    vector<int> vec;                       // Empty vector
    vector<int> vec2(5, 100);              // {100,100,100,100,100}
    vector<int> vec3(5);                   // {0,0,0,0,0} (initialized to 0)
    vector<int> vec4(vec2);                // Copy vec2 → vec4

    /*
        --------------------- INSERTION METHODS ---------------------
    */

    // push_back(): Adds at END (creates a new space)
    vec.push_back(10);   // Example: Add 10
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    // emplace_back(): Faster, constructs in place
    vec.emplace_back(100);

    /*
        --------------------- ITERATORS ---------------------
        Iterator points to memory inside vector
        begin() → first element  
        end()   → one past the last element
    */

    vector<int>::iterator it = v.begin();
    it++;                        // Move to 2nd element
    cout << "Second element: " << *it << endl;

    it = it + 2;                 // Jump two positions ahead
    cout << "4th element: " << *it << endl;

    cout << "Front: " << v.front() << endl; // v[0]
    cout << "Back:  " << v.back()  << endl; // v[n-1]

    /*
        --------------------- ITERATION EXAMPLES ---------------------
    */

    cout << "\nIterating using iterator: ";
    for (auto itr = v.begin(); itr != v.end(); itr++)
        cout << *itr << " ";

    cout << "\nRange-based loop: ";
    for (auto x : v)
        cout << x << " ";

    cout << "\n";

    /*
        --------------------- ERASE & INSERT (IMPORTANT FOR DSA) ---------------------
        erase(pos) → O(N)
        erase(start, end) → O(N)
        insert(pos, value) → O(N)
    */

    vector<int> temp = {10,20,30,40,50,60,70};

    temp.erase(temp.begin() + 2);  // Removes 3rd element
    // Example before: {10,20,30,40,50,60,70}
    // Example after:  {10,20,40,50,60,70}

    temp.erase(temp.begin() + 1, temp.begin() + 4);
    // Deletes 3 elements: positions [1,4)
    // Example after: {10,60,70}

    // Insert a single value
    temp.insert(temp.begin(), 999);        // Insert at start

    // Insert multiple of same value
    temp.insert(temp.begin() + 1, 3, 11);  // Insert 11 three times

    // Insert another vector
    vector<int> extra = {111, 222};
    temp.insert(temp.begin(), extra.begin(), extra.end());

    /*
        --------------------- SIZE / CAPACITY / UTILITIES ---------------------
        size()     → Current number of elements
        capacity() → Allocated memory size (≥ size always)
        max_size() → Maximum elements vector can hold
    */

    cout << "\nSize: " << temp.size() << endl;
    cout << "Capacity: " << temp.capacity() << endl;
    cout << "Max Size: " << temp.max_size() << endl;

    // resize()
    temp.resize(5);     // Truncate if >5, add 0 if <5

    cout << "Is empty: " << temp.empty() << endl; // 0 = false

    temp.pop_back();  // Remove last element
    temp.clear();     // Removes all elements (size=0)

    // swap()
    vector<int> a = {1,2,3};
    vector<int> b = {9,8,7};
    a.swap(b);        // Swap contents

    /*
        --------------------- FINAL PRACTICAL DSA EXAMPLE ---------------------
        Example: Input size N, push elements, print
    */

    vector<int> arr;
    int n = 5;
    for (int i = 1; i <= n; i++)
        arr.push_back(i * 10);   // {10,20,30,40,50}

    cout << "\nDSA Example (arr vector): ";
    for (int x : arr) cout << x << " ";
}

int main() {
    explainVector();
    return 0;
}
