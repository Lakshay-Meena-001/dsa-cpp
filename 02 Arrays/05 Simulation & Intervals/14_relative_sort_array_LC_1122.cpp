#include <iostream>
#include <vector>

using namespace std;

vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
{
    // Frequency table
    vector<int> freq(1001, 0);

    // Count every value in arr1
    for (int x : arr1)
    {
        freq[x]++;
    }

    vector<int> answer;

    // First priority:
    // Follow the order given by arr2
    for (int x : arr2)
    {
        // Put x into answer freq[x] times
        while (freq[x] > 0)
        {
            answer.push_back(x);
            freq[x]--;
        }
    }

    // Second priority:
    // Remaining values in ascending order
    for (int value = 0; value <= 1000; value++)
    {
        while (freq[value] > 0)
        {
            answer.push_back(value);
            freq[value]--;
        }
    }

    return answer;
}

int main()
{
    vector<int> arr1 =
        {
            2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};

    vector<int> arr2 =
        {
            2, 1, 4, 3, 9, 6};

    vector<int> answer =
        relativeSortArray(arr1, arr2);

    for (int x : answer)
    {
        cout << x << " ";
    }

    return 0;
}