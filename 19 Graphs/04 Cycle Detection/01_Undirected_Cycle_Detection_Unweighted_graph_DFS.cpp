#include <iostream>
#include <vector>

using namespace std;

// DFS Function
bool dfs(int node, int parent, const vector<vector<int>> &adj, vector<bool> &visited)
{
    // Step 1 : Mark current node visited
    visited[node] = true;

    // Step 2 : Visit all neighbours
    for (int neighbour : adj[node])
    {
        // Case 1 : Not visited
        if (!visited[neighbour])
        {
            // Explore neighbour
            if (dfs(neighbour, node, adj, visited))
            {
                return true;
            }
        }

        // Case 2 : Already visited & Parent nahi hai
        else if (neighbour != parent)
        {
            return true;
        }
    }

    // No cycle found
    return false;
}

int main()
{
    int n = 5;

    vector<vector<int>> adj(n);

    // Undirected Graph

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    adj[4].push_back(1);
    adj[1].push_back(4);

    vector<bool> visited(n, false);

    bool hasCycle = false;

    // Important for disconnected graph
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            // staring node, parent, adjacency list, visited array
            if (dfs(i, -1, adj, visited))
            {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle)
    {
        cout << "Cycle Found";
    }
    else
    {
        cout << "No Cycle";
    }

    return 0;
}