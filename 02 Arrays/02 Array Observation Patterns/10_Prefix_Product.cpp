#include<iostream>
#include<vector>
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

    for(int i=0;i<n;i++)
    {
        answer[i]=prefix;

        prefix*=arr[i];
    }

    cout<<"Prefix Product : ";

    for(int i=0;i<n;i++)
    {
        cout<<answer[i]<<" ";
    }
}

int main()
{
    int arr[]={2,3,4,5};

    int n=sizeof(arr)/sizeof(arr[0]);

    prefixProduct(arr,n);

    return 0;
}