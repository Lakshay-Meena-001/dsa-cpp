/*
---------------------------------------------------------

Minimum Multiplications to Reach End

Pattern
-------
Implicit Graph
+
Unweighted Shortest Path
+
BFS

Time Complexity
---------------
O(100000 × M)

M = Number of Multipliers

Space Complexity
----------------
O(100000)

---------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MOD = 100000;

// Returns minimum multiplications needed

int minimumMultiplications(vector<int> &multipliers, int start, int end)
{
    // Distance Array
    // dist[x] = Minimum operations required
    // to reach number x.
    // -1 => Not visited yet

    vector<int> dist(MOD, -1);

    // Queue stores:
    // Current Number

    queue<int> q;

    // Source Initialization

    q.push(start);

    dist[start] = 0;

    // Standard BFS

    while (!q.empty())
    {
        int current = q.front();

        q.pop();

        // Destination reached.
        // First reach = shortest reach

        if (current == end)
        {
            return dist[current];
        }

        // Try every multiplier

        for (int multiplier : multipliers)
        {
            // Generate neighbour.
            // Mod keeps graph finite.

            int next = (current * multiplier) % MOD;

            // First time discovered?

            if (dist[next] == -1)
            {
                dist[next] = dist[current] + 1;

                q.push(next);
            }
        }
    }

    // End cannot be reached.

    return -1;
}

int main()
{
    vector<int> multipliers =
        {
            2,
            5,
            7};

    int start = 3;

    int end = 30;

    cout << "Minimum Operations = ";

    cout << minimumMultiplications(
        multipliers,
        start,
        end);

    return 0;
}