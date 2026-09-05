#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool dfs(int u, int currentColor, vector<vector<int>> &graph, vector<int> &color)
    {
        // Give current person a color
        color[u] = currentColor;

        for (int v : graph[u])
        {
            // Neighbour is not colored yet
            if (color[v] == -1)
            {
                // Give opposite color
                if (!dfs(v, 1 - currentColor, graph, color))
                {
                    return false;
                }
            }

            // Already colored neighbour has same color
            // Therefore, they cannot be in different groups
            else if (color[v] == color[u])
            {
                return false;
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        // Build the graph
        vector<vector<int>> graph(n + 1);

        for (auto &edge : dislikes)
        {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // -1 = uncolored
        //  0 = first group
        //  1 = second group
        vector<int> color(n + 1, -1);

        // Graph may be disconnected
        for (int i = 1; i <= n; i++)
        {
            if (color[i] == -1)
            {
                if (!dfs(i, 0, graph, color))
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
    int n = 4;

    vector<vector<int>> dislikes = {
        {1, 2},
        {1, 3},
        {2, 4}};

    Solution obj;

    bool result = obj.possibleBipartition(n, dislikes);

    if (result)
    {
        cout << "Possible to divide into two groups" << endl;
    }
    else
    {
        cout << "Not possible to divide into two groups" << endl;
    }

    return 0;
}