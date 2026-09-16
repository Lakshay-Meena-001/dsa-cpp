#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// LeetCode 802 - Find Eventual Safe States
// Approach : Reverse Graph + Kahn's Algorithm, can do with DFS also using 03 in cycle detection
// Time Complexity : O(V + E)
// Space Complexity : O(V + E)

/*
graph[0] = {1, 2}
graph[1] = {2, 3}
graph[2] = {5}
graph[3] = {0}
graph[4] = {5}
graph[5] = {}
graph[6] = {}
*/
vector<int> eventualSafeNodes(vector<vector<int>>& graph)
{
    int n = graph.size();

    // Reverse Graph

    vector<vector<int>> reverseGraph(n);

    // Outdegree of Original Graph ki ek node se kitne edges baher jaa rahi hai 

    vector<int> outDegree(n, 0);

    // Build Reverse Graph kyuki agar hum normal graph us ekarte hai sirf kuch node par bfs chalega jo kaam nahi karega to reverse graph ki need hai taaki remaining ya othernode ko bhi visit kar payein 

    for (int u = 0; u < n; u++)
    {
        //2d vector hai graph adj list ki form m, to sbhi rows ko as 1d vector ka size nikal rahe hai
        // jaise  graph[0] = {1,2}
        
        outDegree[u] = graph[u].size();

        for (int v : graph[u])
        {
            reverseGraph[v].push_back(u);
        }
    }

    queue<int> q;

    // Push all Terminal Nodes (Outdegree = 0)

    for (int i = 0; i < n; i++)
    {
        if (outDegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> safeNodes;

    // Kahn's Algorithm

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        safeNodes.push_back(node);

        for (int parent : reverseGraph[node])
        {
            outDegree[parent]--;

            if (outDegree[parent] == 0)
            {
                q.push(parent);
            }
        }
    }

    // Sort Answer

    sort(safeNodes.begin(), safeNodes.end());

    return safeNodes;
}

// Driver Code

int main()
{
    vector<vector<int>> graph =
    {
        {1, 2},
        {2, 3},
        {5},
        {0},
        {5},
        {},
        {}
    };

    vector<int> answer = eventualSafeNodes(graph);

    cout << "Safe Nodes : ";

    for (int node : answer)
    {
        cout << node << " ";
    }

    cout << endl;

    return 0;
}