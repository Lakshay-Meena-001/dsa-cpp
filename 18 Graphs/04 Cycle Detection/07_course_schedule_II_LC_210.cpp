#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// LeetCode 210 - Course Schedule II
// Approach : Kahn's Algorithm (Topological Sort)
// Time Complexity : O(V + E)
// Space Complexity : O(V + E)


vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);

    // Build Graph

    for (auto &edge : prerequisites)
    {
        int course = edge[0];
        int prerequisite = edge[1];

        adj[prerequisite].push_back(course);
        indegree[course]++;
    }

    queue<int> q;

    // Push all nodes having indegree = 0

    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> order;

    // Kahn's BFS

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        order.push_back(node);

        for (int neighbour : adj[node])
        {
            indegree[neighbour]--;

            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    // Cycle Check

    if (order.size() == numCourses)
    {
        return order;
    }

    return {};
}

// Driver Code

int main()
{
    int numCourses = 4;

    vector<vector<int>> prerequisites =
    {
        {1, 0},
        {2, 0},
        {3, 1},
        {3, 2}
    };

    vector<int> order = findOrder(numCourses, prerequisites);

    if (order.empty())
    {
        cout << "No valid course order exists." << endl;
    }
    else
    {
        cout << "Course Order : ";

        for (int course : order)
        {
            cout << course << " ";
        }

        cout << endl;
    }

    return 0;
}