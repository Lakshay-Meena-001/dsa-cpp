#include <iostream>
#include <vector>

using namespace std;

vector<int> addToArrayForm(vector<int>& num, int k)
{
    int i = num.size() - 1;
    int carry = 0;

    while (i >= 0 || k > 0 || carry > 0)
    {
        int digitFromNum = 0;

        if (i >= 0)
        {
            digitFromNum = num[i];
        }

        int digitFromK = k % 10;

        int sum = digitFromNum + digitFromK + carry;

        // jis array k element se digit uthaya ab usko update karna hai carry hata ke
        if (i >= 0)
        {
            num[i] = sum % 10;
        }
        else
        {
            num.insert(num.begin(), sum % 10);
        }

        carry = sum / 10;

        k /= 10;
        i--;
    }

    return num;
}

int main()
{
    vector<int> num = {2, 7, 4};
    int k = 58;

    vector<int> result = addToArrayForm(num, k);

    for (int digit : result)
    {
        cout << digit << " ";
    }

    cout << '\n';

    return 0;
}