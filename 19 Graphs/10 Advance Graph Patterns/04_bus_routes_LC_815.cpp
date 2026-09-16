#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        // Already at destination
        if (source == target)
        {
            return 0;
        }

        int n = routes.size();

        // stop -> list of buses/routes passing through this stop / adjacency list of stops
        vector<vector<int>> stopToBuses(1000001);

        for (int bus = 0; bus < n; bus++)
        {
            for (int stop : routes[bus])
            {
                stopToBuses[stop].push_back(bus);
            }
        }

        // BFS on stops
        queue<int> q;
        q.push(source);

        // Minimum number of buses needed to reach each stop
        vector<int> distance(1000001, -1);
        distance[source] = 0;

        // A bus route should be processed only once
        vector<bool> visitedBus(n, false);

        while (!q.empty())
        {
            int currentStop = q.front();
            q.pop();

            // All buses available at current stop
            for (int bus : stopToBuses[currentStop])
            {
                if (visitedBus[bus])
                {
                    continue;
                }

                visitedBus[bus] = true;

                // Take this bus and reach all its stops
                for (int nextStop : routes[bus])
                {
                    if (distance[nextStop] == -1)
                    {
                        distance[nextStop] = distance[currentStop] + 1;

                        if (nextStop == target)
                        {
                            return distance[nextStop];
                        }

                        q.push(nextStop);
                    }
                }
            }
        }

        return -1;
    }
};

int main()
{
    vector<vector<int>> routes = {
        {1, 2, 7},
        {3, 6, 7},
        {7, 8, 9}};

    int source = 1;
    int target = 9;

    Solution obj;

    int result =
        obj.numBusesToDestination(routes, source, target);

    cout << "Minimum buses required: "
         << result << endl;

    return 0;
}
