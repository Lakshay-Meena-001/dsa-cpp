#include <bits/stdc++.h>
using namespace std;

/*
STL ALGORITHMS & UTILITIES REFERENCE

1️⃣ Sorting:
- sort(v.begin(), v.end()) -> ascending
- sort(v.begin(), v.end(), greater<int>()) -> descending
- partial_sort, stable_sort

2️⃣ Searching:
- binary_search(v.begin(), v.end(), x) -> true/false
- lower_bound(v.begin(), v.end(), x) -> first >= x
- upper_bound(v.begin(), v.end(), x) -> first > x

3️⃣ Max/Min:
- max(a,b), min(a,b)
- max({a,b,c,...}), min({a,b,c,...})
- *max_element, *min_element -> return value
- distance(v.begin(), max_element(v.begin(),v.end()))

4️⃣ Counting / Frequency:
- count(v.begin(), v.end(), x)
- count_if(v.begin(), v.end(), lambda)
- __builtin_popcount(x) -> number of set bits
- __builtin_clz(x) -> leading zeros
- __builtin_ctz(x) -> trailing zeros

5️⃣ Prefix/Suffix sums:
- accumulate(v.begin(), v.end(), 0) -> sum
- partial_sum(v.begin(), v.end(), result.begin())
- adjacent_difference

6️⃣ Permutations & Combinations:
- next_permutation(v.begin(), v.end()) -> next lexicographical
- prev_permutation(v.begin(), v.end())

7️⃣ Heap Operations:
- make_heap(v.begin(), v.end())
- push_heap(v.begin(), v.end())
- pop_heap(v.begin(), v.end())
- sort_heap(v.begin(), v.end())

8️⃣ All_of / Any_of / None_of:
- all_of(v.begin(), v.end(), condition)
- any_of(...)
- none_of(...)

9️⃣ Swap / Reverse / Rotate / Unique / Remove:
- reverse(v.begin(), v.end())
- rotate(v.begin(), v.begin()+k, v.end())
- unique(v.begin(), v.end()) -> returns iterator
- remove(v.begin(), v.end(), value) -> returns iterator

10️⃣ Custom Comparators:
- sort(v.begin(), v.end(), cmp)
- lambda functions for custom sorting

11️⃣ Misc:
- iota(v.begin(), v.end(), start) -> fill with increasing values
- next/prev_permutation for generating combinations
*/

void explainAlgorithms() {
    // 1️⃣ Sorting
    vector<int> v = {5,2,8,1,3};
    sort(v.begin(), v.end()); // ascending
    cout << "Ascending sort: ";
    for(auto x: v) cout << x << " ";
    cout << "\n";
    
    sort(v.begin(), v.end(), greater<int>()); // descending
    cout << "Descending sort: ";
    for(auto x: v) cout << x << " ";
    cout << "\n";

    // 2️⃣ Searching
    cout << "Binary search 3: " << binary_search(v.begin(), v.end(), 3) << "\n";
    cout << "Lower bound of 3: " << distance(v.begin(), lower_bound(v.begin(), v.end(), 3)) << "\n";
    cout << "Upper bound of 3: " << distance(v.begin(), upper_bound(v.begin(), v.end(), 3)) << "\n";

    // 3️⃣ Max/Min
    cout << "Max element: " << *max_element(v.begin(), v.end()) << "\n";
    cout << "Min element: " << *min_element(v.begin(), v.end()) << "\n";

    // 4️⃣ Counting / Popcount
    cout << "Count of 3 in v: " << count(v.begin(), v.end(), 3) << "\n";
    int x = 29; // 11101 in binary
    cout << "__builtin_popcount(29) = " << __builtin_popcount(x) << "\n"; // 4 set bits
    cout << "__builtin_clz(29) = " << __builtin_clz(x) << "\n"; // leading zeros (32bit int)
    cout << "__builtin_ctz(29) = " << __builtin_ctz(x) << "\n"; // trailing zeros

    // 5️⃣ Prefix sums
    vector<int> prefix(v.size());
    partial_sum(v.begin(), v.end(), prefix.begin());
    cout << "Partial sum: ";
    for(auto x: prefix) cout << x << " ";
    cout << "\n";

    cout << "Accumulate sum: " << accumulate(v.begin(), v.end(), 0) << "\n";

    // 6️⃣ Permutations
    sort(v.begin(), v.end());
    cout << "Next permutation: ";
    next_permutation(v.begin(), v.end());
    for(auto x: v) cout << x << " ";
    cout << "\n";

    prev_permutation(v.begin(), v.end()); // back to previous

    // 7️⃣ Heap
    vector<int> h = {3,2,5,1,4};
    make_heap(h.begin(), h.end()); // max heap by default
    cout << "Heap top: " << h.front() << "\n";
    h.push_back(6);
    push_heap(h.begin(), h.end());
    cout << "Heap top after push: " << h.front() << "\n";
    pop_heap(h.begin(), h.end());
    h.pop_back();
    cout << "Heap top after pop: " << h.front() << "\n";

    // 8️⃣ All/Any/None of
    cout << "All >0? " << all_of(v.begin(), v.end(), [](int x){ return x>0; }) << "\n";
    cout << "Any >5? " << any_of(v.begin(), v.end(), [](int x){ return x>5; }) << "\n";
    cout << "None <0? " << none_of(v.begin(), v.end(), [](int x){ return x<0; }) << "\n";

    // 9️⃣ Reverse / Rotate / Remove / Unique
    vector<int> rv = {1,2,3,4,5};
    reverse(rv.begin(), rv.end());
    cout << "Reverse: ";
    for(auto x: rv) cout << x << " ";
    cout << "\n";

    rotate(rv.begin(), rv.begin()+2, rv.end()); // rotate left by 2
    cout << "Rotate by 2: ";
    for(auto x: rv) cout << x << " ";
    cout << "\n";

    vector<int> rm = {1,2,2,3,3,3,4};
    rm.erase(unique(rm.begin(), rm.end()), rm.end());
    cout << "Unique elements: ";
    for(auto x: rm) cout << x << " ";
    cout << "\n";

    // 10️⃣ Custom comparator
    vector<pair<int,int>> vp = {{1,3},{1,2},{2,1}};
    sort(vp.begin(), vp.end(), [](pair<int,int> a, pair<int,int> b){
        if(a.first==b.first) return a.second>b.second; // custom logic
        return a.first<b.first;
    });
    cout << "Custom sorted pairs: ";
    for(auto x: vp) cout << "{"<<x.first<<","<<x.second<<"} ";
    cout << "\n";

    // 11️⃣ iota
    vector<int> io(5);
    iota(io.begin(), io.end(), 10); // fills 10,11,12,13,14
    cout << "iota: ";
    for(auto x: io) cout << x << " ";
    cout << "\n";
}

int main() {
    // Title: STL Algorithms & Utilities Reference
    explainAlgorithms();
    return 0;
}
