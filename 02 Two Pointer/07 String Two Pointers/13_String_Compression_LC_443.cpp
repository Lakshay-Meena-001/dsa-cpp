// 13_String_Compression_LC_443.cpp
// Pattern: Read + Write Two Pointers
// Goal: Consecutive characters ko in-place compress karna

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int read = 0;
        int write = 0;

        while (read < chars.size())
        {
            char current = chars[read];
            int count = 0;

            // Current character ka complete group count karo
            while (read < chars.size() &&
                   chars[read] == current)
            {
                read++;
                count++;
            }

            // Character write karo
            chars[write++] = current;

            // Count > 1 ho toh digits write karo
            if (count > 1)
            {
                string countStr = to_string(count);

                for (char digit : countStr)
                {
                    chars[write++] = digit;
                }
            }
        }

        return write;
    }
};

int main()
{
    vector<char> chars = {
        'a', 'a', 'b', 'b', 'c', 'c', 'c'};

    Solution obj;

    int len = obj.compress(chars);

    for (int i = 0; i < len; i++)
    {
        cout << chars[i] << " ";
    }

    cout << "\nCompressed Length: " << len;

    return 0;
}