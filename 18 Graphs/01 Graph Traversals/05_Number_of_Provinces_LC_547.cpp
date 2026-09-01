#include <iostream>
#include <vector>
using namespace std;

// LeetCode 547 - Number of Provinces
//
// Approach : DFS (Recursive)
//
// Time Complexity  : O(V²)
// Space Complexity : O(V)

// DFS Helper

void dfs(int node, const vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = true;

    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, adj, visited);
        }
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();

    // Convert Matrix -> Adjacency List
    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && isConnected[i][j] == 1)
            {
                adj[i].push_back(j);
            }
        }
    }

    vector<bool> visited(n, false);

    int provinces = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited);
            provinces++;
        }
    }

    return provinces;
}

// Driver Code

int main()
{
    vector<vector<int>> isConnected =
        {
            {1, 1, 0},
            {1, 1, 0},
            {0, 0, 1}};

    cout << "Number of Provinces : "
         << findCircleNum(isConnected)
         << endl;

    return 0;
}

/*
class Solution
{
public:

void dfs(int city, const vector<vector<int>> &isConnected, vector<bool> &visited)
{
    visited[city] = true;

    int n = isConnected.size();

    // Visit all connected cities
    for (int neighbour = 0; neighbour < n; neighbour++)
    {
        if (isConnected[city][neighbour] == 1 &&
            !visited[neighbour])
        {
            dfs(neighbour, isConnected, visited);
        }
    }
}

// Returns Number of Provinces

int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();

    vector<bool> visited(n, false);

    int provinces = 0;

    // Traverse every city
    for (int city = 0; city < n; city++)
    {
        if (!visited[city])
        {
            dfs(city, isConnected, visited);
            provinces++;
        }
    }

    return provinces;
}
};
*/