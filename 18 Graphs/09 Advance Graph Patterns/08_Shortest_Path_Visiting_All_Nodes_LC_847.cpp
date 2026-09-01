#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    // humne structure kyu liya pair ya vector kyu nahi liya ? kyuki structure me hum easily variable ko naam de sakte hai aur usko access kar sakte hai structure self explanatory hota hai aur code ko read karna easy hota hai but pair m hum easily variable ko naam nahi de sakte hai aur usko access karna bhi thoda difficult hota hai hum nahi jaante ki first aur second ka kya matlab hai isliye humne structure liya hai
    struct State
    {
        int node;
        int mask;
    };

    int shortestPathLength(vector<vector<int>> &graph)
    {
        int n = graph.size();

        // All nodes visited mask.
        // Example:
        // n = 4
        // allVisited = 1111
        int allVisited = (1 << n) - 1;

        // visited[node][mask]
        //
        // It tells us whether we have already reached
        // this particular state:
        //
        // current node + visited nodes
        vector<vector<bool>> visited(
            n,
            vector<bool>(1 << n, false));

        queue<State> q;

        // We can start from ANY node.
        //
        // If we start from node i,
        // only node i is visited initially.
        for (int i = 0; i < n; i++)
        {
            int mask = (1 << i);

            q.push({i, mask});

            visited[i][mask] = true;
        }

        int steps = 0;

        while (!q.empty())
        {
            int size = q.size();

            // Process one BFS level.
            // Every level represents one more step.
            while (size--)
            {
                State current = q.front();
                q.pop();

                int node = current.node;
                int mask = current.mask;

                // Have we visited every node?
                if (mask == allVisited)
                {
                    return steps;
                }

                // Try every neighbour.
                for (int next : graph[node])
                {
                    // Add 'next' node to the visited set.
                    int newMask = mask | (1 << next);

                    // Have we already seen this exact state?
                    if (visited[next][newMask])
                    {
                        continue;
                    }

                    visited[next][newMask] = true;

                    q.push({next, newMask});
                }
            }

            steps++;
        }

        return -1;
    }
};

int main()
{
    vector<vector<int>> graph = {
        {1, 2},
        {0, 2, 3},
        {0, 1, 3},
        {1, 2}};

    Solution obj;

    int result = obj.shortestPathLength(graph);

    cout << "Shortest path visiting all nodes: "
         << result << endl;

    return 0;
}