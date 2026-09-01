#include <iostream>
using namespace std;

// Sample Array
// {10,20,-5,0,20,-8,15,11}


// 1. Sum of Array

// Purpose : Find sum of all elements
// Time    : O(n)
// Space   : O(1)
// Pattern : Accumulator

int sumArray(const int arr[], int n)
{
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return sum;
}

// 2. Average of Array

// Purpose : Find average of all elements
// Time    : O(n)
// Space   : O(1)

double averageArray(const int arr[], int n)
{
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return (double)sum / n;
}

// 3. Product of Array

// Purpose : Multiply all elements
// Time    : O(n)
// Space   : O(1)

long long productArray(const int arr[], int n)
{
    long long product = 1;

    for(int i = 0; i < n; i++)
    {
        product *= arr[i];
    }

    return product;
}

// 4. Count Even Numbers

// Purpose : Count even elements
// Time    : O(n)
// Space   : O(1)

int countEven(const int arr[], int n)
{
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] % 2 == 0)
        {
            count++;
        }
    }

    return count;
}


// 5. Count Odd Numbers

int countOdd(const int arr[], int n)
{
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] % 2 != 0)
        {
            count++;
        }
    }

    return count;
}

// 6. Count Positive Numbers

// Purpose : Count all positive elements
// Time    : O(n)
// Space   : O(1)


int countPositive(const int arr[], int n)
{
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > 0)
        {
            count++;
        }
    }

    return count;
}

// 7. Count Negative Numbers

// Purpose : Count all negative elements
// Time    : O(n)
// Space   : O(1)


int countNegative(const int arr[], int n)
{
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] < 0)
        {
            count++;
        }
    }

    return count;
}

// 8. Count Zeroes

// Purpose : Count all zeroes
// Time    : O(n)
// Space   : O(1)


int countZero(const int arr[], int n)
{
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 0)
        {
            count++;
        }
    }

    return count;
}

// 9. Count Frequency of Target

// Purpose : Count occurrences of target element
// Time    : O(n)
// Space   : O(1)


int countFrequency(const int arr[], int n, int target)
{
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == target)
        {
            count++;
        }
    }

    return count;
}


// 10. Count Greater Than X

// Purpose : Count elements greater than x
// Time    : O(n)
// Space   : O(1)


int countGreaterThan(const int arr[], int n, int x)
{
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > x)
        {
            count++;
        }
    }

    return count;
}

// 11. Count Less Than X

// Purpose : Count elements less than x
// Time    : O(n)
// Space   : O(1)


int countLessThan(const int arr[], int n, int x)
{
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] < x)
        {
            count++;
        }
    }

    return count;
}

// 12. Count Equal To X

// Purpose : Count elements equal to x
// Time    : O(n)
// Space   : O(1)


int countEqualTo(const int arr[], int n, int x)
{
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == x)
        {
            count++;
        }
    }

    return count;
}

// Driver

int main()
{
    int arr[] = {10,20,-5,0,20,-8,15,11};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array : ";

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n\n";

    cout << "Sum              : " << sumArray(arr, n) << endl;

    cout << "Average          : " << averageArray(arr, n) << endl;

    cout << "Product          : " << productArray(arr, n) << endl;

    cout << "Even Count       : " << countEven(arr, n) << endl;

    cout << "Odd Count        : " << countOdd(arr, n) << endl;

    return 0;
}