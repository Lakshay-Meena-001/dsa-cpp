#include <iostream>
#include <climits>
using namespace std;

// Sample Array
// {10,20,-5,0,20,-8,15,11}

// Maximum / Minimum Pattern

// 1. Find Maximum Element

// Purpose : Find largest element
// Time    : O(n)
// Space   : O(1)
// Pattern : Best Answer


int findMaximum(const int arr[], int n)
{
    int maximum = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > maximum)
        {
            maximum = arr[i];
        }
    }

    return maximum;
}


// 2. Find Minimum Element

// Purpose : Find smallest element
// Time    : O(n)
// Space   : O(1)


int findMinimum(const int arr[], int n)
{
    int minimum = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] < minimum)
        {
            minimum = arr[i];
        }
    }

    return minimum;
}


// 3. Find Maximum & Minimum Together

// Purpose : Find both in one traversal
// Time    : O(n)
// Space   : O(1)


void findMaximumAndMinimum(const int arr[], int n)
{
    int maximum = arr[0];
    int minimum = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > maximum)
        {
            maximum = arr[i];
        }

        if(arr[i] < minimum)
        {
            minimum = arr[i];
        }
    }

    cout << "Maximum : " << maximum << endl;
    cout << "Minimum : " << minimum << endl;
}

// Second Best Pattern

// 4. Find Second Largest Element

// Purpose : Find second largest distinct element
// Time    : O(n)
// Space   : O(1)


int findSecondLargest(const int arr[], int n)
{
    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
        }
    }

    return secondLargest;
}

// 5. Find Second Smallest Element

// Purpose : Find second smallest distinct element
// Time    : O(n)
// Space   : O(1)

int findSecondSmallest(const int arr[], int n)
{
    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] < secondSmallest && arr[i] != smallest)
        {
            secondSmallest = arr[i];
        }
    }

    return secondSmallest;
}

// Index Pattern

// 6. Largest Element Index

// Purpose : Return index of largest element
// Time    : O(n)
// Space   : O(1)


int largestIndex(const int arr[], int n)
{
    int index = 0;

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > arr[index])
        {
            index = i;
        }
    }

    return index;
}


// 7. Smallest Element Index

// Purpose : Return index of smallest element
// Time    : O(n)
// Space   : O(1)

int smallestIndex(const int arr[], int n)
{
    int index = 0;

    for(int i = 1; i < n; i++)
    {
        if(arr[i] < arr[index])
        {
            index = i;
        }
    }

    return index;
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

    cout << "Maximum             : " << findMaximum(arr,n) << endl;

    cout << "Minimum             : " << findMinimum(arr,n) << endl;

    findMaximumAndMinimum(arr,n);

    cout << "Second Largest      : " << findSecondLargest(arr,n) << endl;

    cout << "Second Smallest     : " << findSecondSmallest(arr,n) << endl;

    cout << "Largest Index       : " << largestIndex(arr,n) << endl;

    cout << "Smallest Index      : " << smallestIndex(arr,n) << endl;

    return 0;
}