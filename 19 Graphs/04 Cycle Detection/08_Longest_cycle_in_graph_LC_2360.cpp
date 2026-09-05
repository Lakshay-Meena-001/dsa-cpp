#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// LeetCode 2360 - Longest Cycle in a Graph

// Approach : Graph Traversal + Visit Time Mapping
// Time Complexity : O(V)
// Space Complexity : O(V)

int longestCycle(vector<int> &edges)
{
    int n = edges.size();

    vector<bool> visited(n, false);

    int longest = -1;

    // Try every node as a starting point

    for (int start = 0; start < n; start++)
    {
        if (visited[start])
        {
            continue;
        }

        unordered_map<int, int> visitTime;

        int node = start;
        int step = 0;

        // Traverse until dead end or visited node

        while (node != -1 && !visited[node])
        {
            visited[node] = true;

            visitTime[node] = step;

            step++;

            // next nod epar move karo like adjacency list ki tarah se no loop because ek outgoing edge hai 
            
            node = edges[node];
        }

        // Cycle Found

        if (node != -1 && visitTime.count(node))
        {
            longest = max(longest, step - visitTime[node]);
        }
    }

    return longest;
}

// Driver Code

int main()
{
    vector<int> edges =
        {
            3, 3, 4, 2, 3};

    cout << "Longest Cycle Length = "
         << longestCycle(edges)
         << endl;

    return 0;
}