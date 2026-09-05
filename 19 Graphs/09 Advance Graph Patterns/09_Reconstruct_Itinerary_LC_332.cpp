#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>

/*
heirholzer's algorithm
EDGE CONSUME
+
BACKTRACK
+
ROUTE CONSTRUCTION
*/
using namespace std;

class Solution
{
public:
    map<string, priority_queue<string, vector<string>, greater<string>>> graph;

    vector<string> route;

    void dfs(string airport)
    {
        // current airpot se jitne bhi destination hai unko visit karo
        while (!graph[airport].empty())
        {
            // hume lexographically smallest destination chahiye us airpot se isliye priority queue use kiya hai
            string next = graph[airport].top();

            // ab jo ticket top par thi usko us ekarliya humen kyuki ek hi bar mtlab ek edge ko consume karn ahai 
            graph[airport].pop();

            // ab jo ticket consume ki hai usse next airpot se jite bhi destination hai isi tarah se dfs lagao 
            dfs(next);
        }

        // to ab is airpot se jitne bhi destination hai unko visit kar liya hai ab hum backtrack kar rahe hai to is airpot ko route me add kar do
        // ab usko route me add karne ka mtlab hai ki humne jitne bhi destination visit kiye hai unke baad hum wapas aa rahe hai is airpot par to is airpot ko route me add kar do
        route.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        // Build directed graph.
        for (auto &ticket : tickets)
        {
            string from = ticket[0];
            string to = ticket[1];

            graph[from].push(to);
        }

        // Start from JFK.
        dfs("JFK");

        // Vertices were collected during backtracking,
        // so reverse them to get the actual itinerary.
        reverse(route.begin(), route.end());

        return route;
    }
};

int main()
{
    vector<vector<string>> tickets = {
        {"MUC", "LHR"},
        {"JFK", "MUC"},
        {"SFO", "SJC"},
        {"LHR", "SFO"}};

    Solution obj;

    vector<string> result = obj.findItinerary(tickets);

    cout << "Itinerary:" << endl;

    for (string airport : result)
    {
        cout << airport << " ";
    }

    cout << endl;

    return 0;
}