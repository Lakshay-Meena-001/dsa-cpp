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
        // Case 1 : Neighbour visited nahi hai
        if (!visited[neighbour])
        {
            // Explore neighbour ki agar neighbour par dsa se cycle mil gyi ans propagate hota hai
            /*
            Agar tumne us return value ko ignore kar diya, to node 2 ko kabhi pata hi nahi chalega ki cycle mil chuki hai. Wo baaki neighbours dekhne lagega aur final answer galat ho sakta hai.
            Isliye recursive call ka result capture aur propagate karna zaroori hai.*/
            if (dfs(neighbour, node, adj, visited))
            {
                return true;
            }
        }

        // Case 2 :Neighbour already visited hai and wo parent bhi nahi hai kyuki undirected graph hai
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

/*
DFS(node, parent)

↓

Mark Visited

↓

For every neighbour

    Not Visited ?

        DFS

        True?

            Return True

    Else

        Parent?

            Ignore

        Not Parent?

            Cycle

↓

Return False
*/