#include <iostream>
#include <vector>
using namespace std;

// LeetCode 841 - Keys and Rooms
//
// Approach : DFS (Recursive)
//
// Time Complexity  : O(V + E)
// Space Complexity : O(V)

void dfs(int room, const vector<vector<int>> &rooms, vector<bool> &visited, int &visitedCount)
{
    visited[room] = true;
    visitedCount++;

    for (int nextRoom : rooms[room])
    {
        if (!visited[nextRoom])
        {
            dfs(nextRoom, rooms, visited, visitedCount);
        }
    }
}

bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    int n = rooms.size();

    vector<bool> visited(n, false);

    int visitedCount = 0;

    dfs(0, rooms, visited, visitedCount);

    return visitedCount == n;
}

// Driver Code

int main()
{
    vector<vector<int>> rooms =
        {
            {1},
            {2},
            {3},
            {}};

    if (canVisitAllRooms(rooms))
    {
        cout << "All Rooms Can Be Visited" << endl;
    }
    else
    {
        cout << "All Rooms Cannot Be Visited" << endl;
    }

    return 0;
}

/*
/ DFS Helper

void dfs(int room, const vector<vector<int>> &rooms, vector<bool> &visited)
{
    visited[room] = true;

    // Visit all rooms whose keys are present
    for (int nextRoom : rooms[room])
    {
        if (!visited[nextRoom])
        {
            dfs(nextRoom, rooms, visited);
        }
    }
}

// Returns true if all rooms can be visited

bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    int n = rooms.size();

    vector<bool> visited(n, false);

    // Start from Room 0
    dfs(0, rooms, visited);

    // Check if every room is visited
    for (bool roomVisited : visited)
    {
        if (!roomVisited)
        {
            return false;
        }
    }

    return true;
}


*/