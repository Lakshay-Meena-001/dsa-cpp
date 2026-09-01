#include <iostream>
using namespace std;

// Sample Array
// {10,20,30,40,50}

// 1. Forward Traversal
void forwardTraversal(const int arr[], int n)
{
    cout << "Forward Traversal : ";

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// 2. Backward Traversal
void backwardTraversal(const int arr[], int n)
{
    cout << "Backward Traversal : ";

    for(int i = n - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// 3. By Value
void rangeByValue(const int arr[], int n)
{
    cout << "Range By Value : ";

    for(int i = 0; i < n; i++)
    {
        int x = arr[i];
        cout << x << " ";
    }

    cout << endl;
}

// 4. By Reference
void rangeByReference(int arr[], int n)
{
    cout << "Range By Reference : ";

    for(int i = 0; i < n; i++)
    {
        int &x = arr[i];
        x *= 2;
    }

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// 5. Const Reference
void constReferenceTraversal(const int arr[], int n)
{
    cout << "Const Reference : ";

    for(int i = 0; i < n; i++)
    {
        const int &x = arr[i];
        cout << x << " ";
    }

    cout << endl;
}

// 6. Auto
void autoTraversal(const int arr[], int n)
{
    cout << "Auto Traversal : ";

    for(int i = 0; i < n; i++)
    {
        auto x = arr[i];
        cout << x << " ";
    }

    cout << endl;
}

// 7. Auto Reference
void autoReferenceTraversal(int arr[], int n)
{
    cout << "Auto Reference : ";

    for(int i = 0; i < n; i++)
    {
        auto &x = arr[i];
        x++;
    }

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// 8. Const Auto Reference
void constAutoReferenceTraversal(const int arr[], int n)
{
    cout << "Const Auto Reference : ";

    for(int i = 0; i < n; i++)
    {
        const auto &x = arr[i];
        cout << x << " ";
    }

    cout << endl;
}

// 9. Reverse
void printReverse(const int arr[], int n)
{
    cout << "Reverse : ";

    for(int i = n - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// 10. Alternate Elements
void printAlternate(const int arr[], int n)
{
    cout << "Alternate Elements : ";

    for(int i = 0; i < n; i += 2)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// 11. Even Index
void printEvenIndex(const int arr[], int n)
{
    cout << "Even Index : ";

    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
        {
            cout << arr[i] << " ";
        }
    }

    cout << endl;
}

// 12. Odd Index
void printOddIndex(const int arr[], int n)
{
    cout << "Odd Index : ";

    for(int i = 0; i < n; i++)
    {
        if(i % 2 != 0)
        {
            cout << arr[i] << " ";
        }
    }

    cout << endl;
}

// 13. First Half
void printFirstHalf(const int arr[], int n)
{
    cout << "First Half : ";

    for(int i = 0; i < n / 2; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// 14. Second Half
void printSecondHalf(const int arr[], int n)
{
    cout << "Second Half : ";

    for(int i = n / 2; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// 15. Index and Value
void printIndexAndValue(const int arr[], int n)
{
    cout << "Index -> Value\n";

    for(int i = 0; i < n; i++)
    {
        cout << i << " -> " << arr[i] << endl;
    }
}

// 16. Double Elements
void doubleElements(int arr[], int n)
{
    cout << "Double Elements : ";

    for(int i = 0; i < n; i++)
    {
        arr[i] *= 2;
    }

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// 17. Increment Elements
void incrementElements(int arr[], int n)
{
    cout << "Increment Elements : ";

    for(int i = 0; i < n; i++)
    {
        arr[i]++;
    }

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// 18. Square Elements
void squareElements(int arr[], int n)
{
    cout << "Square Elements : ";

    for(int i = 0; i < n; i++)
    {
        arr[i] *= arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// Driver
int main()
{
    int arr[] = {10,20,30,40,50};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array : ";

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n\n";

    forwardTraversal(arr, n);
    backwardTraversal(arr, n);
    rangeByValue(arr, n);
    rangeByReference(arr, n);
    constReferenceTraversal(arr, n);
    autoTraversal(arr, n);
    autoReferenceTraversal(arr, n);
    constAutoReferenceTraversal(arr, n);

    printReverse(arr, n);
    printAlternate(arr, n);
    printEvenIndex(arr, n);
    printOddIndex(arr, n);
    printFirstHalf(arr, n);
    printSecondHalf(arr, n);
    printIndexAndValue(arr, n);

    doubleElements(arr, n);
    incrementElements(arr, n);
    squareElements(arr, n);

    return 0;
}