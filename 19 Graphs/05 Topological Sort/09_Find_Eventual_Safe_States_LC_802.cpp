#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// LeetCode 802 - Find Eventual Safe States
// Approach : Reverse Graph + Kahn's Algorithm
// Time Complexity : O(V + E)
// Space Complexity : O(V + E)

vector<int> eventualSafeNodes(vector<vector<int>>& graph)
{
    int n = graph.size();

    // Reverse Graph

    vector<vector<int>> reverseGraph(n);

    // Outdegree of Original Graph

    vector<int> outDegree(n, 0);

    // Build Reverse Graph

    for (int u = 0; u < n; u++)
    {
        outDegree[u] = graph[u].size();

        for (int v : graph[u])
        {
            reverseGraph[v].push_back(u);
        }
    }

    queue<int> q;

    // Push all Terminal Nodes (Outdegree = 0)

    for (int i = 0; i < n; i++)
    {
        if (outDegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> safeNodes;

    // Kahn's Algorithm

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        safeNodes.push_back(node);

        for (int parent : reverseGraph[node])
        {
            outDegree[parent]--;

            if (outDegree[parent] == 0)
            {
                q.push(parent);
            }
        }
    }

    // Sort Answer

    sort(safeNodes.begin(), safeNodes.end());

    return safeNodes;
}

// Driver Code

int main()
{
    vector<vector<int>> graph =
    {
        {1, 2},
        {2, 3},
        {5},
        {0},
        {5},
        {},
        {}
    };

    vector<int> answer = eventualSafeNodes(graph);

    cout << "Safe Nodes : ";

    for (int node : answer)
    {
        cout << node << " ";
    }

    cout << endl;

    return 0;
}