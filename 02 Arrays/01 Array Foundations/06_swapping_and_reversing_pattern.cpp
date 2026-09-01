#include <iostream>
using namespace std;


// Sample Array
// {10,20,-5,0,20,-8,15,11}

// Utility Function

void printArray(const int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}


// Swapping Pattern

// 1. Manual Swap

// Purpose : Swap two variables
// Time    : O(1)
// Space   : O(1)

void manualSwap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 2. Swap By Index

// Purpose : Swap two array elements

void swapByIndex(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Reverse Pattern

// 3. Reverse Array

// Purpose : Reverse complete array

// Pattern : Two Pointer

// Time : O(n)
// Space : O(1)


void reverseArray(int arr[], int n)
{
    int left = 0;
    int right = n - 1;

    while(left < right)
    {
        manualSwap(arr[left], arr[right]);

        left++;
        right--;
    }
}


// 4. Reverse Subarray

// Purpose : Reverse from l to r


void reverseSubarray(int arr[], int left, int right)
{
    while(left < right)
    {
        manualSwap(arr[left], arr[right]);

        left++;
        right--;
    }
}


// Shift Pattern

// 5. Left Shift By One

// Time : O(n)
// Space : O(1)


void leftShiftByOne(int arr[], int n)
{
    int first = arr[0];

    for(int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    arr[n - 1] = first;
}

// 6. Right Shift By One

// Time : O(n)
// Space : O(1)

void rightShiftByOne(int arr[], int n)
{
    int last = arr[n - 1];

    for(int i = n - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[0] = last;
}

// Driver

int main()
{
    int arr[] = {10,20,-5,0,20,-8,15,11};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array : ";
    printArray(arr,n);

    reverseArray(arr,n);
    cout << "Reverse Array  : ";
    printArray(arr,n);

    reverseSubarray(arr,2,5);
    cout << "Reverse 2-5    : ";
    printArray(arr,n);

    leftShiftByOne(arr,n);
    cout << "Left Shift     : ";
    printArray(arr,n);

    rightShiftByOne(arr,n);
    cout << "Right Shift    : ";
    printArray(arr,n);

    return 0;
}