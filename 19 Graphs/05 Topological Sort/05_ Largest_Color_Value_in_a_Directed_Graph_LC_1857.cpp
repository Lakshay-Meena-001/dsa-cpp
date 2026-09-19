#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {

        int n = colors.size();

        // 1. Build graph + indegree

        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            indegree[v]++;
        }

        // 2. DP
        // dp[u][c] = maximum count of color c
        // on a path ending at node u

        vector<vector<int>> dp(n, vector<int>(26, 0));

        // 3. Kahn's Algorithm

        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        int processed = 0;
        int answer = 0;

        // 4. Topological BFS + DP

        while (!q.empty())
        {

            int u = q.front();
            q.pop();

            processed++;

            // Node u contributes its own color
            int colorIndex = colors[u] - 'a';
            dp[u][colorIndex]++;

            // Current best answer from node u
            for (int c = 0; c < 26; c++)
            {
                answer = max(answer, dp[u][c]);
            }

            // Send DP information to neighbours

            for (int v : graph[u])
            {
                for (int c = 0; c < 26; c++)
                {

                    int extra = (colors[v] - 'a' == c);

                    dp[v][c] = max(dp[v][c], dp[u][c] + extra);
                }

                // u is completed,
                // so one dependency of v is removed
                indegree[v]--;

                if (indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        // 5. Cycle detection

        if (processed != n)
        {
            return -1;
        }

        return answer;
    }
};

// MAIN

int main()
{

    Solution obj;

    // Example:
    //
    // 0(a) → 1(b) → 2(a)
    //                  ↘
    //                   3(c)
    //                  4(a)

    string colors = "abaca";

    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {2, 4}};

    int answer = obj.largestPathValue(colors, edges);

    cout << "Largest Color Value = "
         << answer << endl;

    return 0;
}