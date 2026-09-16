/*
------------------------------------------------------------

Problem : Open_the_Lock_LC_752

Pattern
-------
State Space Graph
+
Implicit Graph
+
Unweighted Shortest Path
+
BFS

Time Complexity
---------------
O(10000)

Maximum possible lock states = 0000 -> 9999

Each state generates 8 neighbours.

Space Complexity
----------------
O(10000)

------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

// Returns minimum moves required to reach target.

int openLock(vector<string> &deadends, string target)
{
    // Store all dead ends for O(1) lookup.

    unordered_set<string> dead(deadends.begin(), deadends.end());

    // If starting state itself is blocked.

    if (dead.count("0000"))
    {
        return -1;
    }

    // Visited states.

    unordered_set<string> visited;

    // Queue stores:
    // Current Lock State
    // Number of Moves

    queue<pair<string, int>> q;

    q.push({"0000", 0});

    visited.insert("0000");

    // Standard BFS

    while (!q.empty())
    {
        string current = q.front().first;
        int moves = q.front().second;

        q.pop();

        // Destination reached

        if (current == target)
        {
            return moves;
        }
        // Rotate every wheel

        for (int i = 0; i < 4; i++)
        {
            // Save original digit.

            char originalDigit = current[i];

            // Forward Rotation

            current[i] = (originalDigit == '9') ? '0' : originalDigit + 1;

            if (!dead.count(current) && !visited.count(current))
            {
                visited.insert(current);

                q.push({current, moves + 1});
            }

            // Restore original digit.

            current[i] = originalDigit;

            // Backward Rotation

            current[i] = (originalDigit == '0') ? '9' : originalDigit - 1;

            if (!dead.count(current) && !visited.count(current))
            {
                visited.insert(current);

                q.push({current, moves + 1});
            }

            // Restore original state.

            current[i] = originalDigit;
        }
    }

    // Target unreachable.

    return -1;
}

// Main
int main()
{
    vector<string> deadends =
        {
            "0201",
            "0101",
            "0102",
            "1212",
            "2002"};

    string target = "0202";

    cout << "Minimum Moves = ";

    cout << openLock(deadends, target);

    return 0;
}