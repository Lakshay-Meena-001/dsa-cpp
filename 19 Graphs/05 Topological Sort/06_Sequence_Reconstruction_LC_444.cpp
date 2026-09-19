#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool sequenceReconstruction(vector<int> &nums, vector<vector<int>> &sequences)
    {

        int n = nums.size();

        // graph[u] = nodes that come after u
        vector<unordered_set<int>> graph(n + 1);

        // indegree[v] = number of prerequisites of v
        vector<int> indegree(n + 1, 0);

        // Build graph
        for (auto &seq : sequences)
        {

            for (int i = 1; i < seq.size(); i++)
            {

                int u = seq[i - 1];
                int v = seq[i];

                // Avoid duplicate edges
                if (graph[u].insert(v).second)
                {
                    indegree[v]++;
                }
            }
        }

        // Kahn's queue
        queue<int> q;

        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> order;

        while (!q.empty())
        {

            // More than one choice => not unique
            if (q.size() > 1)
            {
                return false;
            }

            int u = q.front();
            q.pop();

            order.push_back(u);

            // Remove u's dependency from its neighbours
            for (int v : graph[u])
            {

                indegree[v]--;

                if (indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        // Unique order must exactly match nums
        return order == nums;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 2, 3};

    vector<vector<int>> sequences = {
        {1, 2},
        {2, 3}};

    bool answer =
        obj.sequenceReconstruction(nums, sequences);

    cout << (answer ? "true" : "false") << endl;

    return 0;
}