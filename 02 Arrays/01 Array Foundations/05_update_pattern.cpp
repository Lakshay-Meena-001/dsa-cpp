#include <iostream>
using namespace std;

// Sample Array

// {10,20,-5,0,20,-8,15,11}

// Mathematical Updating Pattern

// 1. Increment Every Element

// Purpose : Add 1 to every element
// Time    : O(n)
// Space   : O(1)

void incrementAll(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i]++;
    }
}

// 2. Decrement Every Element

// Purpose : Subtract 1 from every element
// Time    : O(n)
// Space   : O(1)

void decrementAll(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i]--;
    }
}

// 3. Multiply Every Element

// Purpose : Multiply every element by k
// Time    : O(n)
// Space   : O(1)

void multiplyAll(int arr[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] *= k;
    }
}

// 4. Divide Every Element

// Purpose : Divide every element by k
// Time    : O(n)
// Space   : O(1)

void divideAll(int arr[], int n, int k)
{
    if (k == 0)
    {
        cout << "Division by zero is not allowed.\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] /= k;
    }
}

// 5. Square Every Element

// Purpose : Square every element

void squareAll(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] *= arr[i];
    }
}

// Conditional Updating Pattern

// 6. Replace Negative Elements

// Purpose : Replace negative numbers with value

void replaceNegative(int arr[], int n, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            arr[i] = value;
        }
    }
}

// 7. Replace Positive Elements

// Purpose : Replace positive numbers

void replacePositive(int arr[], int n, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            arr[i] = value;
        }
    }
}

// 8. Replace Zero

// Purpose : Replace all zeroes

void replaceZero(int arr[], int n, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            arr[i] = value;
        }
    }
}

// 9. Replace Even Elements

// Purpose : Replace all even numbers

void replaceEven(int arr[], int n, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            arr[i] = value;
        }
    }
}

// 10. Replace Odd Elements

// Purpose : Replace all odd numbers

void replaceOdd(int arr[], int n, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 != 0)
        {
            arr[i] = value;
        }
    }
}

// 11. Replace Target Value

// Purpose : Replace target with new value

void replaceValue(int arr[], int n, int target, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            arr[i] = value;
        }
    }
}

// Utility Function

void printArray(const int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// Driver

int main()
{
    int arr[] = {10, 20, -5, 0, 20, -8, 15, 11};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array : ";
    printArray(arr, n);

    incrementAll(arr, n);
    cout << "Increment      : ";
    printArray(arr, n);

    decrementAll(arr, n);
    cout << "Decrement      : ";
    printArray(arr, n);

    multiplyAll(arr, n, 2);
    cout << "Multiply x2    : ";
    printArray(arr, n);

    divideAll(arr, n, 2);
    cout << "Divide by 2    : ";
    printArray(arr, n);

    squareAll(arr, n);
    cout << "Square         : ";
    printArray(arr, n);

    replaceNegative(arr, n, 0);
    cout << "Negative->0    : ";
    printArray(arr, n);

    replacePositive(arr, n, 100);
    cout << "Positive->100  : ";
    printArray(arr, n);

    replaceZero(arr, n, -1);
    cout << "Zero->-1       : ";
    printArray(arr, n);

    replaceEven(arr, n, 8);
    cout << "Even->8        : ";
    printArray(arr, n);

    replaceOdd(arr, n, 9);
    cout << "Odd->9         : ";
    printArray(arr, n);

    replaceValue(arr, n, 9, 50);
    cout << "9->50          : ";
    printArray(arr, n);

    return 0;
}