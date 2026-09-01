#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool dfs(int u, int currentColor, vector<vector<int>> &graph, vector<int> &color)
    {

        color[u] = currentColor;

        for (int v : graph[u])
        {

            // Neighbour is not colored yet
            if (color[v] == -1)
            {
                // Give opposite color, default dfs hume return karega true and agar dfs chalaya or wo tru nah nikla to wo return false dega and isliye !dfs() chalay ahai ki agar wo false return kare to hum false return kar denge
                if (!dfs(v, 1 - currentColor, graph, color))
                {
                    return false;
                }
            }

            // Neighbour already has same color
            else if (color[v] == color[u])
            {
                return false;
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

    // Example graph
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