#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int mostBooked(int n, vector<vector<int>> &meetings)
{
    // Meetings ko start time ke according sort karo
    sort(meetings.begin(), meetings.end());

    // Available rooms:
    // smallest room number sabse pehle milega
    priority_queue<int, vector<int>, greater<int>> availableRooms;

    // Busy rooms:
    // {endTime, roomNumber}
    // earliest end time top par
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busyRooms;

    // Initially sab rooms availableRooms hain
    for (int room = 0; room < n; room++)
    {
        availableRooms.push(room);
    }

    // Har room ne kitni meetings ki
    vector<int> count(n, 0);

    for (auto &meeting : meetings)
    {
        long long start = meeting[0];
        long long end = meeting[1];

        // Jo rooms ab free ho chuke hain,
        // unhe availableRooms heap me daalo
        while (!busyRooms.empty() && busyRooms.top().first <= start)
        {
            int room = busyRooms.top().second;

            busyRooms.pop();

            availableRooms.push(room);
        }

        // Case 1:
        // Koi room availableRooms hai
        if (!availableRooms.empty())
        {
            int room = availableRooms.top();
            availableRooms.pop();

            count[room]++;

            busyRooms.push({end, room});
        }

        // Case 2:
        // Koi room availableRooms nahi hai
        else
        {
            // Jo room sabse pehle free hoga
            auto [freeTime, room] = busyRooms.top();

            busyRooms.pop();

            // Meeting ki duration
            long long duration = end - start;

            // Meeting delay hogi
            long long newEnd = freeTime + duration;

            count[room]++;

            busyRooms.push({newEnd, room});
        }
    }

    // Maximum meetings wala room
    // tie me smallest room number
    int answer = 0;

    for (int room = 1; room < n; room++)
    {
        if (count[room] > count[answer])
        {
            answer = room;
        }
    }

    return answer;
}

int main()
{
    int n = 2;

    vector<vector<int>> meetings =
        {
            {0, 10},
            {1, 5},
            {2, 7},
            {3, 4}};

    cout << mostBooked(n, meetings) << '\n';

    return 0;
}