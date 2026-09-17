#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;

    // 0 = WHITE , 1 = GRAY , 2 = BLACK
    vector<int> color;

    bool dfs(int u)
    {
        // Step 1: DFS mein enter hue
        color[u] = 1; // GRAY

        // Step 2: saare neighbours check karo
        for (int v : adj[u])
        {

            // GRAY neighbour = current DFS path mein wapas aaye Therefore cycle exists
            if (color[v] == 1)
            {
                return true;
            }

            // WHITE neighbour = abhi visit nahi hua
            if (color[v] == 0)
            {
                if (dfs(v))
                {
                    return true;
                }
            }

            // BLACK neighbour = already completely processed Isko ignore kar sakte hain
        }

        // Step 3: current node ka DFS complete
        color[u] = 2; // BLACK

        return false;
    }

public:
    Graph(int n)
    {
        V = n;
        adj.resize(V);
        color.assign(V, 0); // Initially all WHITE
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    bool hasCycle()
    {

        // Graph disconnected bhi ho sakta hai,isliye har WHITE node se DFS start karenge.
        for (int u = 0; u < V; u++)
        {
            if (color[u] == 0)
            {
                if (dfs(u))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{

    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);

    if (g.hasCycle())
    {
        cout << "Cycle exists\n";
    }
    else
    {
        cout << "No cycle\n";
    }

    return 0;
}