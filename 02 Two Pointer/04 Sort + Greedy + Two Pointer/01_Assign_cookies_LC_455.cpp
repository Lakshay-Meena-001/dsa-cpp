#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int child = 0;
    int cookie = 0;
    int count = 0;

    while (child < g.size() && cookie < s.size())
    {
        if (s[cookie] >= g[child])
        {
            // Cookie can satisfy this child
            count++;
            child++;
            cookie++;
        }
        else
        {
            // Cookie is too small, discard it
            cookie++;
        }
    }

    return count;
}

int main()
{
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1, 2, 3};

    cout << findContentChildren(g, s) << endl;

    return 0;
}