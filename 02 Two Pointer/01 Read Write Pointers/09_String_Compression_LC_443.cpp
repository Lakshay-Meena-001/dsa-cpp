#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {

        int n = chars.size();

        int read = 0;
        int write = 0;

        while (read < n)
        {

            // Character whose group we are processing.
            char current = chars[read];

            int count = 0;

            // Count the complete group.
            while (read < n && chars[read] == current)
            {
                count++;
                read++;
            }

            // Write the character.
            chars[write] = current;
            write++;

            // Write the count only if it is greater than 1.
            if (count > 1)
            {

                string countString = to_string(count);

                for (char digit : countString)
                {

                    chars[write] = digit;
                    write++;
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

    Solution solution;

    int k = solution.compress(chars);

    cout << "Compressed: ";

    for (int i = 0; i < k; i++)
    {
        cout << chars[i];
    }

    cout << "\nLength: " << k << endl;

    return 0;
}