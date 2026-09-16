#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool bfs(int start, vector<vector<int>> &graph, vector<int> &color)
    {
        queue<int> q;

        // Give starting node the first color
        color[start] = 0;

        q.push(start);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v : graph[u])
            {
                // Neighbour is not colored yet
                if (color[v] == -1)
                {
                    // Give opposite color
                    color[v] = 1 - color[u];

                    // Process this neighbour later
                    q.push(v);
                }

                // Neighbour already colored
                // Same color means conflict
                else if (color[v] == color[u])
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();

        // -1 = uncolored
        //  0 = first color
        //  1 = second color
        vector<int> color(n, -1);

        // Graph may be disconnected
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (!bfs(i, graph, color))
                {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    vector<vector<int>> graph = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}};

    Solution obj;

    bool result = obj.isBipartite(graph);

    if (result)
    {
        cout << "Graph is Bipartite" << endl;
    }
    else
    {
        cout << "Graph is NOT Bipartite" << endl;
    }

    return 0;
}