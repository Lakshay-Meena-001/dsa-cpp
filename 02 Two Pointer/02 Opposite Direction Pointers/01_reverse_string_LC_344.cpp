#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int L = 0;
        int R = s.size() - 1;

        while (L < R)
        {
            swap(s[L], s[R]);

            L++;
            R--;
        }
    }
};

int main()
{
    Solution obj;

    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    obj.reverseString(s);

    for (char ch : s)
    {
        cout << ch;
    }

    return 0;
}