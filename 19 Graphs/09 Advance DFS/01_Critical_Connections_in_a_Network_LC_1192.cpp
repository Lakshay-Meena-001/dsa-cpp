#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int timer = 0;

    void dfs(int u, int parent, vector<vector<int>> &graph, vector<int> &tin, vector<int> &low, vector<vector<int>> &ans)
    {

        // Discovery time
        tin[u] = low[u] = timer++;

        for (int v : graph[u])
        {

            // Parent edge ko ignore karo
            if (v == parent)
            {
                continue;
            }

            // Agar node pehli baar visit ho raha hai
            if (tin[v] == -1)
            {

                dfs(v, u, graph, tin, low, ans);

                // Child ki low value se current node update
                low[u] = min(low[u], low[v]);

                // Bridge condition
                if (low[v] > tin[u])
                {
                    ans.push_back({u, v});
                }
            }

            // Back edge
            else
            {
                low[u] = min(low[u], tin[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {

        // Graph create karo
        vector<vector<int>> graph(n);

        for (auto &edge : connections)
        {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> tin(n, -1);
        vector<int> low(n, -1);

        vector<vector<int>> ans;

        // DFS start
        dfs(0, -1, graph, tin, low, ans);

        return ans;
    }
};

int main()
{

    int n = 5;

    vector<vector<int>> connections = {
        {0, 1},
        {1, 2},
        {2, 0},
        {1, 3},
        {3, 4}};

    Solution obj;

    vector<vector<int>> ans =
        obj.criticalConnections(n, connections);

    cout << "Bridges are:\n";

    for (auto &edge : ans)
    {
        cout << edge[0] << " - " << edge[1] << endl;
    }

    return 0;
}