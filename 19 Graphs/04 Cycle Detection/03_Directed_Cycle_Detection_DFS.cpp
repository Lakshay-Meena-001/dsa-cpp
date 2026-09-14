#include <iostream>
#include <vector>

using namespace std;

// problem kya hai ki hum path m cycle ki wajah se directed graph m ghum kar kisi top node m aa gaye, ab pichle problem m kya tha ki ycl edetect karne k liye visited neighbour ho or parent n aho yah awo fail kar jata hai
bool dfs(int node, const vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &pathVisited)
{
    // Node visited permanently
    visited[node] = true;

    // Node enters current DFS path
    pathVisited[node] = true;

    // Explore neighbours
    for (int neighbour : adj[node])
    {
        // New node mili hai check karo
        if (!visited[neighbour])
        {
            if (dfs(neighbour, adj, visited, pathVisited))
            {
                return true;
            }
        }

        // Already present in current DFS path matlab ye whi patch chal rah ahi and hum wapis uski kisi node par aa gye 
        else if (pathVisited[neighbour])
        {
            return true;
        }
    }

    // Remove from current DFS path for next new dfs path
    pathVisited[node] = false;

    return false;
}

int main()
{
    int n = 4;

    vector<vector<int>> adj(n);

    // Directed Graph
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);

    vector<bool> visited(n, false);
    vector<bool> pathVisited(n, false);

    bool hasCycle = false;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, adj, visited, pathVisited))
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