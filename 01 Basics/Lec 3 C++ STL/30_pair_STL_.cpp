#include <bits/stdc++.h>
using namespace std;

/*
===============================
C++ STL Pair Cheat Sheet
===============================

A pair is a simple container to store two heterogeneous objects as a single unit.
You can access the two elements using .first and .second

Common Uses in Competitive Programming:
1️⃣ Store coordinates (row, col)
2️⃣ Weighted edges in graphs (weight, vertex)
3️⃣ Store value with its original index (value, index)
4️⃣ Sorting by first or second element
5️⃣ Nested pairs for complex info
6️⃣ Use in vectors, arrays, sets, and maps

Reference: https://cplusplus.com/reference/utility/pair/

*/

void explainPairs()
{
    // 1️⃣ Basic Pair
    pair<int, int> p = {1, 2};
    cout << "Basic Pair: " << p.first << ", " << p.second << "\n";
    // Output: 1, 2

    // 2️⃣ Nested Pair
    pair<int, pair<int, int>> p1 = {1, {2, 3}};
    cout << "Nested Pair: " << p1.first << ", "
         << p1.second.first << ", "
         << p1.second.second << "\n";
    // Output: 1, 2, 3

    // 3️⃣ Pair in Array
    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
    cout << "Array of Pairs, second element of index 1: " << arr[1].second << "\n";
    // Output: 4

    // 4️⃣ Pair in Vector
    vector<pair<int, int>> v = {{3, 1}, {2, 2}, {1, 3}};
    cout << "Vector of Pairs:\n";
    for (auto &pr : v)
    {
        cout << pr.first << "," << pr.second << " ";
    }
    cout << "\n";

    // 5️⃣ Sorting Pairs
    sort(v.begin(), v.end()); // sorts by first, then second
    cout << "Sorted Vector of Pairs:\n";
    for (auto &pr : v)
    {
        cout << pr.first << "," << pr.second << " ";
    }
    cout << "\n";

    // 6️⃣ Sorting by second element using lambda
    sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b)
         { return a.second < b.second; });
    cout << "Sorted by second element:\n";
    for (auto &pr : v)
    {
        cout << pr.first << "," << pr.second << " ";
    }
    cout << "\n";

    // 7️⃣ Using Pairs in Priority Queue (common in graphs)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({2, 1});
    pq.push({1, 3});
    pq.push({3, 0});
    cout << "Priority Queue top: " << pq.top().first << "," << pq.top().second << "\n";
    // Output: 1,3  (min-heap based on first element)

    // 8️⃣ Common Competitive Programming Pattern: (value, index)
    vector<int> nums = {4, 2, 7, 1};
    vector<pair<int, int>> vp;
    for (int i = 0; i < nums.size(); i++)
    {
        vp.push_back({nums[i], i});
    }
    sort(vp.begin(), vp.end());
    cout << "Sorted by value with index:\n";
    for (auto &pr : vp)
        cout << pr.first << "(" << pr.second << ") ";
    cout << "\n";

    // 9️⃣ Coordinates in grid problems
    pair<int, int> coord = {2, 3}; // row=2, col=3
    cout << "Coordinates: (" << coord.first << "," << coord.second << ")\n";
}

int main()
{
    cout << "========== STL Pair Examples ==========\n";
    explainPairs();
    return 0;
}
