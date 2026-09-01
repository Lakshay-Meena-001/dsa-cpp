#include <bits/stdc++.h>
using namespace std;

/*
  ===========================================
  STL: Custom Comparators & Lambda Functions
  ===========================================

  1️⃣ Why use a custom comparator?
     - Default sort/order is not always enough.
     - For example:
        * Sort pairs by second element
        * Multi-condition sort
        * Min-heap for priority_queue based on custom criteria

  2️⃣ Comparator must return:
        true  -> first element should come BEFORE second
        false -> otherwise

  3️⃣ Can be implemented as:
        - Function
        - Lambda
        - Functor (struct with operator())

  4️⃣ Lambda functions: [capture] (parameters) { body }
     - [ ] -> capture clause: allows lambda to use variables from outside scope
        * []      -> capture nothing
        * [&]     -> capture all by reference
        * [=]     -> capture all by value
        * [x,y]   -> capture specific variables by value
        * [&x,&y] -> capture specific variables by reference

*/

void explainCustomComparator() {
    // Example 1: Sort vector descending using normal function
    auto cmpFunc = [](int a, int b) { return a > b; }; // lambda function
    vector<int> v = {5,2,8,1,3};
    sort(v.begin(), v.end(), cmpFunc); // descending
    cout << "Descending sort: ";
    for(int x: v) cout << x << " "; 
    cout << "\n";

    // Example 2: Sort vector of pairs by first ascending, second descending
    vector<pair<int,int>> vp = {{1,3},{1,2},{2,1}};
    sort(vp.begin(), vp.end(), [](pair<int,int> a, pair<int,int> b){
        if(a.first == b.first) return a.second > b.second; // second desc
        return a.first < b.first; // first asc
    });
    cout << "Custom sort pairs: ";
    for(auto p: vp) cout << "{" << p.first << "," << p.second << "} ";
    cout << "\n";

    // Example 3: priority_queue min-heap of pairs by second element
    auto cmpPQ = [](pair<int,int> a, pair<int,int> b){ return a.second > b.second; };
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmpPQ)> pq(cmpPQ);

    pq.push({1,5});
    pq.push({2,2});
    pq.push({3,4});
    cout << "Top of min-heap based on second element: " << pq.top().second << "\n";

    // Example 4: Functor (struct) as comparator
    struct MyCmp {
        bool operator()(pair<int,int> a, pair<int,int> b) {
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        }
    };
    sort(vp.begin(), vp.end(), MyCmp());
    cout << "Sorted with functor: ";
    for(auto p: vp) cout << "{" << p.first << "," << p.second << "} ";
    cout << "\n";

    // Example 5: Capture outside variables using lambda
    int multiplier = 2;
    sort(v.begin(), v.end(), [multiplier](int a,int b){ 
        return (a*multiplier) < (b*multiplier); 
    }); // capture multiplier by value
    cout << "Sort using captured variable: ";
    for(int x:v) cout << x << " ";
    cout << "\n";
}

int main() {
    cout << "========= Custom Comparator Examples =========\n";
    explainCustomComparator();
    return 0;
}
