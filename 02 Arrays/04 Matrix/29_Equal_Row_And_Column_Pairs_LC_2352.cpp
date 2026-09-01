#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// Problem : 29_Equal_Row_And_Column_Pairs_LC_2352.cpp
// Pattern : Matrix + HashMap
// Approach :
// 1. Convert every row into a unique string.
// 2. Store row frequency in HashMap.
// 3. Convert every column into a string.
// 4. Lookup the column string inside HashMap.
//
// Time  : O(n²)
// Space : O(n²)
//
// Learning:
// 1. Matrix Signature
// 2. HashMap Lookup
// 3. Row vs Column Comparison

int equalPairs(const vector<vector<int>> &grid)
{
    int n = grid.size();

    unordered_map<string, int> frequency;

    //--------------------------------------------------
    // Pass 1 : Store every row.
    //--------------------------------------------------

    for (int i = 0; i < n; i++)
    {
        string signature;

        for (int j = 0; j < n; j++)
        {
            signature += to_string(grid[i][j]) + "#";
        }

        frequency[signature]++;
    }

    //--------------------------------------------------
    // Pass 2 : Compare every column.
    //--------------------------------------------------

    int answer = 0;

    for (int j = 0; j < n; j++)
    {
        string signature;

        for (int i = 0; i < n; i++)
        {
            signature += to_string(grid[i][j]) + "#";
        }
        // jo current column ka signature hai, usko frequenct map me check karenge, agar presnet hai to answer me add karenge
        answer += frequency[signature];
    }

    return answer;
}

// Driver

int main()
{
    int n;

    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << equalPairs(grid);

    return 0;
}