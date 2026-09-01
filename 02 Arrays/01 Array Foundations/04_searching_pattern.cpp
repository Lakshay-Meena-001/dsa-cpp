#include <iostream>
using namespace std;

// Sample Array
// {10,20,-5,0,20,-8,15,11}

// Basic Searching Pattern

// 1. Linear Search

// Purpose : Return index of target
// Time    : O(n)
// Space   : O(1)


int linearSearch(const int arr[], int n, int target)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}


// 2. Check Element Exists

// Purpose : Return true if element exists


bool contains(const int arr[], int n, int target)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == target)
        {
            return true;
        }
    }

    return false;
}


// 3. First Occurrence

// Purpose : Return first occurrence index


int firstOccurrence(const int arr[], int n, int target)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}

// 4. Last Occurrence

// Purpose : Return last occurrence index

int lastOccurrence(const int arr[], int n, int target)
{
    for(int i = n - 1; i >= 0; i--)
    {
        if(arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}


// 5. Count Occurrences
// Purpose : Count frequency of target

int countOccurrences(const int arr[], int n, int target)
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


// 6. Print All Occurrences

// Purpose : Print all indices of target


void printAllOccurrences(const int arr[], int n, int target)
{
    cout << "Indices : ";

    bool found = false;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == target)
        {
            cout << i << " ";

            found = true;
        }
    }

    if(!found)
    {
        cout << "Not Found";
    }

    cout << endl;
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

    cout << "Linear Search (20)      : " << linearSearch(arr,n,20) << endl;

    cout << "Contains 15             : " << contains(arr,n,15) << endl;

    cout << "First Occurrence (20)   : " << firstOccurrence(arr,n,20) << endl;

    cout << "Last Occurrence (20)    : " << lastOccurrence(arr,n,20) << endl;

    cout << "Count Occurrences (20)  : " << countOccurrences(arr,n,20) << endl;

    printAllOccurrences(arr,n,20);

    return 0;
}