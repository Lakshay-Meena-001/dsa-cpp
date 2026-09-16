// 09_Long_Pressed_Name_LC_925.cpp
// Pattern: Two Pointers + Character Repetition
// Goal: Check karo typed, name ka valid long-pressed version hai ya nahi

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        int i = 0; // name pointer
        int j = 0; // typed pointer

        while (j < typed.size())
        {

            // Characters match → dono pointers aage
            if (i < name.size() && name[i] == typed[j])
            {
                i++;
                j++;
            }
            // Extra repeated character → typed pointer skip
            else if (j > 0 && typed[j] == typed[j - 1])
            {
                j++;
            }
            else
            {
                return false;
            }
        }

        // Pura name match hona chahiye
        return i == name.size();
    }
};

int main()
{
    string name = "alex";
    string typed = "aaleex";

    Solution obj;

    cout << boolalpha << obj.isLongPressedName(name, typed);

    return 0;
}