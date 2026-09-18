#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int minimumSemesters(int n, vector<vector<int>> &relations)
    {

        // 1. Graph
        vector<vector<int>> adj(n + 1);

        // 2. Indegree
        vector<int> indegree(n + 1, 0);

        // 3. Build graph
        for (auto &edge : relations)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        // 4. Courses available in first semester
        queue<int> q;

        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // 5. BFS level-by-level
        int semesters = 0;
        int completed = 0;

        while (!q.empty())
        {

            semesters++;

            int size = q.size();

            while (size--)
            {

                int u = q.front();
                q.pop();

                completed++;

                for (int v : adj[u])
                {

                    indegree[v]--;

                    if (indegree[v] == 0)
                    {
                        q.push(v);
                    }
                }
            }
        }

        // 6. Cycle detection
        if (completed == n)
            return semesters;

        return -1;
    }
};