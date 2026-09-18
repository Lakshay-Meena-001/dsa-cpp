#include <iostream>
using namespace std;

class Solution
{
public:
    // Number ke digits ke squares ka sum calculate karega
    int nextNumber(int n)
    {
        int sum = 0;

        while (n > 0)
        {
            int digit = n % 10;

            sum += digit * digit;

            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n)
    {
        int slow = n;
        int fast = n;

        do
        {
            // Slow → 1 step
            slow = nextNumber(slow);

            // Fast → 2 steps
            fast = nextNumber(nextNumber(fast));

        } while (slow != fast);

        // Agar cycle 1 par mila → Happy Number
        return slow == 1;
    }
};

int main()
{
    Solution sol;

    // Test Case 1
    int n1 = 19;

    cout << "Input: " << n1 << endl;
    cout << "Output: ";

    if (sol.isHappy(n1))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    cout << endl;

    // Test Case 2
    int n2 = 2;

    cout << "Input: " << n2 << endl;
    cout << "Output: ";

    if (sol.isHappy(n2))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    cout << endl;

    // Test Case 3
    int n3 = 7;

    cout << "Input: " << n3 << endl;
    cout << "Output: ";

    if (sol.isHappy(n3))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}