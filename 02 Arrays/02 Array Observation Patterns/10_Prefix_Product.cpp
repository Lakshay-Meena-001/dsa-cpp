#include <iostream>
#include <vector>
using namespace std;

// Prefix Product

// Purpose : Build Prefix Product Array

// Used In : LC238
// Time : O(n)
// Space : O(n)

void prefixProduct(const int arr[], int n)
{
    vector<int> answer(n);

    int prefix = 1;

    // prefix product array kaise banta hai, basically hum ek prefix variable lete hai aur usko 1 se initialize karte hai aur fir hum array ke elements ko traverse karte hai aur har element ke liye prefix product ko answer array me store karte hai aur fir prefix ko current element se multiply kar dete hai. isse hume prefix product array mil jaata hai.
    for (int i = 0; i < n; i++)
    {
        // abhi ek important condition ki humne prefix product pehle nahi nikala humne pehle old prefox product ko answer me store kiya aur fir prefix ko update kiya. isse hume prefix product array mil jaata hai. kyuki agar hum prefix product ko pehle update karte hai to hume prefix product array nahi milega. isliye humne pehle old prefix product ko answer me store kiya aur fir prefix ko update kiya.
        answer[i] = prefix;

        prefix *= arr[i];
    }

    cout << "Prefix Product : ";

    for (int i = 0; i < n; i++)
    {
        cout << answer[i] << " ";
    }
}

int main()
{
    int arr[] = {2, 3, 4, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    prefixProduct(arr, n);

    return 0;
}