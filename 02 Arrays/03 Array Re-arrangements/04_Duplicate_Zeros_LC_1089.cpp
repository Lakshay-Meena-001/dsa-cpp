#include <iostream>
#include <vector>
using namespace std;

void duplicateZeros(vector<int> &arr)
{
    int n = arr.size();
    int zeros = 0;

    // Count zeros to be duplicated
    for (int x : arr)
    {
        if (x == 0)
        {
            zeros++;
        }
    }

    int i = n - 1;
    int j = n + zeros - 1;

    // Fill from the end
    while (i >= 0)
    {
        if (j < n)
        {
            arr[j] = arr[i];
        }

        if (arr[i] == 0)
        {
            j--;
            if (j < n)
            {
                arr[j] = 0;
            }
        }

        i--;
        j--;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    duplicateZeros(arr);

    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}

/*
Problem:
Ek fixed-size array diya hai. Har 0 ko duplicate karna hai,
lekin array ka size change nahi karna.
Jo elements array ki length se bahar jaate hain, unhe ignore karna hai.

Input:  [1, 0, 2, 3, 0, 4, 5, 0]
Output: [1, 0, 0, 2, 3, 0, 0, 4]

Approach: Two Pointers (Backward Traversal) - In-place

Steps:
1. Array mein total zeroes count karo.
2. i = n-1 rakho (original array ka last index).
3. j = n + zeros - 1 rakho (virtual expanded array ka last index).
4. End se start ki taraf traverse karo.
5. Agar j < n hai, toh arr[i] ko arr[j] par copy karo.
6. Agar arr[i] == 0 hai:
   - j-- karo.
   - Agar j < n hai, toh wahan bhi 0 insert karo.
7. Har iteration mein i-- aur j-- karo.
8. Array automatically in-place modify ho jayega.

Ek chhota example
[1, 0, 2, 3]

Total zero = 1

i = 3, j = 4

3 ko index 4 par likhna possible nahi, ignore.

2 ko index 3 par likho.

0 ko index 2 aur index 1 par likho.

1 ko index 0 par likho.

Final: [1, 0, 0, 2]

TC: O(n) - Zero count aur backward traversal.
SC: O(1) - Extra array use nahi kiya.
*/