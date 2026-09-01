#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// LeetCode 542 - 01 Matrix

// Approach : Multi Source BFS

// Time Complexity : O(rows × cols)
// Space Complexity : O(rows × cols)

// Update Matrix

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int rows = mat.size();
    int cols = mat[0].size();

    queue<pair<int, int>> q;

    vector<vector<int>> distance(rows,vector<int>(cols, -1));

    // Direction Arrays
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};

    // Put all 0's into Queue
   
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (mat[row][col] == 0)
            {
                q.push({row, col});
                distance[row][col] = 0;
            }
        }
    }


    // Multi Source BFS

    while (!q.empty())
    {
        auto current = q.front();
        q.pop();

        int row = current.first;
        int col = current.second;

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dr[i];
            int newCol = col + dc[i];

            if (newRow >= 0 &&
                newRow < rows &&
                newCol >= 0 &&
                newCol < cols &&
                distance[newRow][newCol] == -1)
            {
                distance[newRow][newCol] =
                    distance[row][col] + 1;

                q.push({newRow, newCol});
            }
        }
    }

    return distance;
}


// Print Matrix

void printMatrix(vector<vector<int>> &matrix)
{
    for (auto row : matrix)
    {
        for (int value : row)
        {
            cout << value << " ";
        }

        cout << endl;
    }
}

// Driver Code

int main()
{
    vector<vector<int>> mat =
    {
        {0,0,0},
        {0,1,0},
        {1,1,1}
    };

    cout << "Original Matrix\n\n";

    printMatrix(mat);

    cout << "\nDistance Matrix\n\n";

    vector<vector<int>> answer = updateMatrix(mat);

    printMatrix(answer);

    return 0;
}