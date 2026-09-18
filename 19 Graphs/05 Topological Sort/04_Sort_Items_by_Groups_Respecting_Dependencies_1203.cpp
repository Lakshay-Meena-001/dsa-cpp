#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Kahn's Algorithm
    vector<int> topoSort(vector<vector<int>> &graph, vector<int> indegree, int n)
    {

        queue<int> q;
        vector<int> order;

        // Jinke paas koi dependency nahi hai
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {

            int u = q.front();
            q.pop();

            order.push_back(u);

            // u complete hua,
            // isliye neighbours ki dependency kam karo
            for (int v : graph[u])
            {

                indegree[v]--;

                // v ki saari dependencies complete
                if (indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        // Cycle hai
        if (order.size() != n)
        {
            return {};
        }

        return order;
    }

    vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems)
    {

        // STEP 1: Ungrouped items ko unique group do

        int totalGroups = m;

        for (int i = 0; i < n; i++)
        {

            if (group[i] == -1)
            {
                group[i] = totalGroups++;
            }
        }

        // STEP 2: Graphs + indegrees

        vector<vector<int>> itemGraph(n);
        vector<int> itemIndegree(n, 0);

        vector<vector<int>> groupGraph(totalGroups);
        vector<int> groupIndegree(totalGroups, 0);

        // STEP 3: Item Graph + Group Graph

        for (int v = 0; v < n; v++)
        {

            for (int u : beforeItems[v])
            {

                // Item dependency:
                // u -> v
                itemGraph[u].push_back(v);
                itemIndegree[v]++;

                // Agar different groups hain,
                // toh group dependency bhi banegi
                if (group[u] != group[v])
                {

                    groupGraph[group[u]].push_back(group[v]);
                    groupIndegree[group[v]]++;
                }
            }
        }

        // STEP 4: Group Topological Sort

        vector<int> groupOrder = topoSort(groupGraph, groupIndegree, totalGroups);

        if (groupOrder.empty())
        {
            return {};
        }

        // STEP 5: Item Topological Sort

        vector<int> itemOrder = topoSort(itemGraph, itemIndegree, n);

        if (itemOrder.empty())
        {
            return {};
        }

        // STEP 6: Items ko group-wise buckets mein daalo

        vector<vector<int>> buckets(totalGroups);

        for (int item : itemOrder)
        {

            int g = group[item];

            buckets[g].push_back(item);
        }

        // STEP 7: Group order ke according buckets join karo

        vector<int> answer;

        for (int g : groupOrder)
        {

            for (int item : buckets[g])
            {

                answer.push_back(item);
            }
        }

        return answer;
    }
};

// MAIN

int main()
{

    int n = 8;
    int m = 2;

    vector<int> group = {
        -1, -1, 1, 0, 0, 1, 0, -1};

    vector<vector<int>> beforeItems = {
        {},     // 0
        {6},    // 1
        {5},    // 2
        {6},    // 3
        {3, 6}, // 4
        {},     // 5
        {},     // 6
        {}      // 7
    };

    Solution obj;

    vector<int> answer =
        obj.sortItems(n, m, group, beforeItems);

    // Print answer
    if (answer.empty())
    {

        cout << "No valid ordering exists.\n";
    }
    else
    {

        cout << "Valid ordering: ";

        for (int x : answer)
        {
            cout << x << " ";
        }

        cout << "\n";
    }

    return 0;
}