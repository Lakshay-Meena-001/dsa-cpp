#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// BFS Function
bool bfs(int start, const vector<vector<int>> &adj, vector<bool> &visited)
{
    // Queue stores (node, parent)
    queue<pair<int, int>> q;

    visited[start] = true;

    q.push({start, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int neighbour : adj[node])
        {
            // New node
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push({neighbour, node});
            }

            // Already visited but not parent
            else if (neighbour != parent)
            {
                return true;
            }
        }
    }

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

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (bfs(i, adj, visited))
            {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle)
        cout << "Cycle Found";
    else
        cout << "No Cycle";

    return 0;
}