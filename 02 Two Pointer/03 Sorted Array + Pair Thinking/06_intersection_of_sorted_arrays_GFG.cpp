#include <bits/stdc++.h>
using namespace std;

vector<int> intersectionOfSortedArrays(vector<int> &A, vector<int> &B)
{
    int i = 0;
    int j = 0;

    vector<int> answer;

    while (i < A.size() && j < B.size())
    {

        if (A[i] < B[j])
        {
            i++;
        }
        else if (A[i] > B[j])
        {
            j++;
        }
        else
        {
            // if kya kar raha hai ki answer vector me last element ko check kar raha hai ki agar wo same hai to push nahi karega 
            if (answer.empty() || answer.back() != A[i])
            {
                answer.push_back(A[i]);
            }

            i++;
            j++;
        }
    }

    return answer;
}

int main()
{

    vector<int> A = {1, 3, 5, 7, 9};
    vector<int> B = {2, 3, 6, 7, 10};

    vector<int> answer =
        intersectionOfSortedArrays(A, B);

    for (int x : answer)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}