#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// LeetCode 2392 - Build a Matrix With Conditions

// Approach : Two Topological Sorts

// Time Complexity : O(K + RowEdges + ColEdges)
// Space Complexity : O(K + RowEdges + ColEdges)

// Topological Sort

vector<int> topoSort(int k, vector<vector<int>> &conditions)
{
    vector<vector<int>> adj(k + 1);

    vector<int> indegree(k + 1, 0);

    // Build Graph

    for (auto &edge : conditions)
    {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);

        indegree[v]++;
    }

    queue<int> q;

    // Push indegree = 0

    for (int i = 1; i <= k; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> order;

    // Kahn's Algorithm

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        order.push_back(node);

        for (int neighbour : adj[node])
        {
            indegree[neighbour]--;

            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    // Cycle Found

    if (order.size() != k)
    {
        return {};
    }

    return order;
}

// Build Matrix

vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
{
    // Row Topological Order

    vector<int> rowOrder = topoSort(k, rowConditions);

    // Column Topological Order

    vector<int> colOrder = topoSort(k, colConditions);

    if (rowOrder.empty() || colOrder.empty())
    {
        return {};
    }

    // Position Arrays

    vector<int> rowPosition(k + 1);
    vector<int> colPosition(k + 1);

    for (int i = 0; i < k; i++)
    {
        rowPosition[rowOrder[i]] = i;
        colPosition[colOrder[i]] = i;
    }

    // Build Matrix

    vector<vector<int>> matrix(k, vector<int>(k, 0));

    for (int num = 1; num <= k; num++)
    {
        matrix[rowPosition[num]][colPosition[num]] = num;
    }

    return matrix;
}

// Driver Code

int main()
{
    int k = 3;

    vector<vector<int>> rowConditions =
        {
            {1, 2},
            {3, 2}};

    vector<vector<int>> colConditions =
        {
            {2, 1},
            {3, 2}};

    vector<vector<int>> matrix = buildMatrix(k, rowConditions, colConditions);

    if (matrix.empty())
    {
        cout << "No Valid Matrix Exists\n";
        return 0;
    }

    cout << "Matrix:\n\n";

    for (auto &row : matrix)
    {
        for (int value : row)
        {
            cout << value << " ";
        }

        cout << endl;
    }

    return 0;
}