#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int nextGreaterElement(int n)
{

    // Number ko digits ki string mein convert kar rahe hain
    string digits = to_string(n);

    int i = digits.size() - 2;

    // Step 1: Right se pivot find karo
    while (i >= 0 && digits[i] >= digits[i + 1])
    {
        i--;
    }

    // Koi pivot nahi mila
    // Number already largest permutation hai
    if (i < 0)
    {
        return -1;
    }

    // Step 2: Right se pivot se just-greater digit find karo
    int j = digits.size() - 1;

    while (digits[j] <= digits[i])
    {
        j--;
    }

    // Step 3: Pivot aur successor swap
    swap(digits[i], digits[j]);

    // Step 4: Suffix ko smallest order mein lao
    reverse(digits.begin() + i + 1, digits.end());

    // String ko long long mein convert
    long long result = stoll(digits);

    // 32-bit signed integer ke andar fit hona chahiye
    if (result > INT_MAX)
    {
        return -1;
    }

    return static_cast<int>(result);
}

int main()
{

    int n = 12443322;

    cout << "Next Greater Element: "
         << nextGreaterElement(n) << endl;

    return 0;
}

/*
Input:
12443322

Output:
13222344

Core Pattern:
Next Permutation

Steps:
1. Find pivot from right.
2. Find just-greater digit.
3. Swap.
4. Reverse suffix.
5. Check INT_MAX overflow.

TC: O(d), where d = number of digits
SC: O(d)
*/