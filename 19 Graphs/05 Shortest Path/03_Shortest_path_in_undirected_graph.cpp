#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> shortestPath(int V, vector<vector<int>> &adj, int source)
{
    vector<int> dist(V, -1);

    queue<int> q;

    q.push(source);

    dist[source] = 0;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int neighbour : adj[current])
        {

            if (dist[neighbour] == -1)
            {
                dist[neighbour] = dist[current] + 1;
                q.push(neighbour);
            }
        }
    }

    return dist;
}

int main()
{
    int V = 9;

    vector<vector<int>> adj(V);

    auto addEdge = [&](int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    addEdge(0, 1);
    addEdge(0, 3);
    addEdge(1, 2);
    addEdge(3, 4);
    addEdge(4, 5);
    addEdge(5, 6);
    addEdge(2, 6);
    addEdge(6, 7);
    addEdge(7, 8);

    int source = 0;

    vector<int> distance = shortestPath(V, adj, source);

    cout << "Shortest Distance From Source\n\n";

    for (int i = 0; i < V; i++)
    {
        cout << i << " -> " << distance[i] << endl;
    }

    return 0;
}