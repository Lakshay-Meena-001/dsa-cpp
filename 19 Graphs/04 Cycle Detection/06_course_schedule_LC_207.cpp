#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// LeetCode 207 - Course Schedule
// Approach : Kahn's Algorithm (Topological Sort)
// Time Complexity : O(V + E)
// Space Complexity : O(V + E)

bool canFinish(int numCourses,
               vector<vector<int>>& prerequisites)
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

    int count = 0;

    // Kahn's BFS

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        count++;

        for (int neighbour : adj[node])
        {
            indegree[neighbour]--;

            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    return count == numCourses;
}

// Driver Code

int main()
{
    int numCourses = 2;

    vector<vector<int>> prerequisites =
    {
        {1, 0}
    };

    if (canFinish(numCourses, prerequisites))
    {
        cout << "Yes, all courses can be completed." << endl;
    }
    else
    {
        cout << "No, all courses cannot be completed." << endl;
    }

    return 0;
}