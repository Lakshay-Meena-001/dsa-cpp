#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> kahnTopoSort(int V, const vector<vector<int>>& adj)
{
    // Step 1 : Calculate Indegree
    vector<int> indegree(V, 0);

    for (int node = 0; node < V; node++)
    {
        for (int neighbour : adj[node])
        {
            indegree[neighbour]++;
        }
    }

    // Step 2 : Push all indegree 0 nodes
    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> topo;

    // Step 3 : BFS
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        topo.push_back(node);

        for (int neighbour : adj[node])
        {
            indegree[neighbour]--;

            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    return topo;
}

int main()
{
    int V = 6;

    vector<vector<int>> adj(V);

    adj[5].push_back(2);
    adj[5].push_back(0);

    adj[4].push_back(0);
    adj[4].push_back(1);

    adj[2].push_back(3);

    adj[3].push_back(1);

    vector<int> topo = kahnTopoSort(V, adj);

    cout << "Topological Order : ";

    for (int node : topo)
    {
        cout << node << " ";
    }

    return 0;
}