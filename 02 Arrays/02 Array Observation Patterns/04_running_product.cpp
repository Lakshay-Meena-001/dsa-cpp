#include <iostream>
using namespace std;

// Running Product

// Purpose : Find product of all elements
// Pattern : Running State
// Used In : LC238, LC152
// Time    : O(n)
// Space   : O(1)


long long runningProduct(const int arr[], int n)
{
    // Start with multiplicative identity
    long long currentProduct = 1;

    for(int i = 0; i < n; i++)
    {
        currentProduct *= arr[i];
    }

    return currentProduct;
}

int main()
{
    int arr[] = {2,3,4,5};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Running Product = "<<runningProduct(arr,n);

    return 0;
}