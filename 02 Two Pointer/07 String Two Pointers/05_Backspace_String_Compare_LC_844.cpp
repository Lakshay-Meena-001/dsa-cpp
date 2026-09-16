// 05_Backspace_String_Compare_LC_844.cpp
// Pattern: Two Pointers + Hidden Skip State
// Goal: '#' ke effect ke baad dono strings compare karna

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int i = s.size() - 1;
        int j = t.size() - 1;

        int skipS = 0;
        int skipT = 0;

        while (i >= 0 || j >= 0)
        {

            // S ka next valid character find karo
            while (i >= 0)
            {
                if (s[i] == '#')
                {
                    skipS++;
                    i--;
                }
                else if (skipS > 0)
                {
                    skipS--;
                    i--;
                }
                else
                {
                    break;
                }
            }

            // T ka next valid character find karo
            while (j >= 0)
            {
                if (t[j] == '#')
                {
                    skipT++;
                    j--;
                }
                else if (skipT > 0)
                {
                    skipT--;
                    j--;
                }
                else
                {
                    break;
                }
            }

            // Ek side par character hai aur doosri par nahi
            if ((i >= 0) != (j >= 0))
            {
                return false;
            }

            // Dono valid characters different hain
            if (i >= 0 && j >= 0 && s[i] != t[j])
            {
                return false;
            }

            i--;
            j--;
        }

        return true;
    }
};

int main()
{
    string s = "ab#c";
    string t = "ad#c";

    Solution obj;

    cout << boolalpha << obj.backspaceCompare(s, t);

    return 0;
}