#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//=========================================================
// LeetCode 1462 - Course Schedule IV
//
// Approach : Topological Sort + Reachability
//
// Time Complexity : O(V² + E + Q)
// Space Complexity : O(V²)
//=========================================================

vector<bool> checkIfPrerequisite(int numCourses,vector<vector<int>>& prerequisites,vector<vector<int>>& queries)
{
    // Graph

    vector<vector<int>> adj(numCourses);

    vector<int> indegree(numCourses, 0);

    // reach[u][v] = true
    // u is prerequisite of v

    vector<vector<bool>> reach(numCourses,vector<bool>(numCourses, false));

    // Build Graph

    for (auto &edge : prerequisites)
    {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);

        indegree[v]++;
    }

    queue<int> q;

    // Push indegree = 0

    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // Kahn's Algorithm

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int neighbour : adj[node])
        {
            // Direct prerequisite

            reach[node][neighbour] = true;

            // Inherit all prerequisites

            for (int i = 0; i < numCourses; i++)
            {
                if (reach[i][node])
                {
                    reach[i][neighbour] = true;
                }
            }

            indegree[neighbour]--;

            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    // Answer Queries

    vector<bool> answer;

    for (auto &query : queries)
    {
        answer.push_back(reach[query[0]][query[1]]);
    }

    return answer;
}

// Driver Code

int main()
{
    int numCourses = 4;

    vector<vector<int>> prerequisites =
    {
        {0,1},
        {1,2},
        {2,3}
    };

    vector<vector<int>> queries =
    {
        {0,3},
        {1,3},
        {3,0},
        {0,2}
    };

    vector<bool> answer =
        checkIfPrerequisite(numCourses,
                            prerequisites,
                            queries);

    cout << "Answers : ";

    for (bool x : answer)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}