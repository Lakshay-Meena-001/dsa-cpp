#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {

        int n = colors.size();

        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        // Build graph
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            indegree[v]++;
        }

        vector<vector<int>> dp(n, vector<int>(26, 0));

        queue<int> q;

        // Initialize source nodes
        for (int i = 0; i < n; i++)
        {

            if (indegree[i] == 0)
            {

                q.push(i);

                // Starting node contributes its own color
                dp[i][colors[i] - 'a'] = 1;
            }
        }

        int processed = 0;
        int answer = 0;

        while (!q.empty())
        {

            int u = q.front();
            q.pop();

            processed++;

            // Check answer
            for (int c = 0; c < 26; c++)
            {
                answer = max(answer, dp[u][c]);
            }

            // u → v
            for (int v : graph[u])
            {

                for (int c = 0; c < 26; c++)
                {

                    int extra = (colors[v] - 'a' == c);

                    dp[v][c] = max(
                        dp[v][c],
                        dp[u][c] + extra);
                }

                indegree[v]--;

                if (indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        // Not all nodes processed => cycle
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