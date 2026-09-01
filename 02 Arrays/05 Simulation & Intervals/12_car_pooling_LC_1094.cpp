#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


// ============================================================
// APPROACH 1: BRUTE FORCE SIMULATION
// ============================================================

bool carPoolingBrute(vector<vector<int>>& trips, int capacity)
{
    // Location 0 to 1000
    for (int location = 0; location <= 1000; location++)
    {
        int passengers = 0;

        // Har trip ko check karo
        for (auto& trip : trips)
        {
            int people = trip[0];
            int pickup = trip[1];
            int drop = trip[2];

            // Agar is location par ye passengers
            // car ke andar hain
            if (pickup <= location && location < drop)
            {
                passengers += people;
            }
        }

        // Capacity exceed
        if (passengers > capacity)
        {
            return false;
        }
    }

    return true;
}


// ============================================================
// APPROACH 2: DIFFERENCE ARRAY + PREFIX SUM
// ⭐ MAIN APPROACH
// ============================================================

bool carPoolingDifferenceArray(vector<vector<int>>& trips,
                               int capacity)
{
    // diff[i] = location i par passenger count ka change
    vector<int> diff(1001, 0);

    for (auto& trip : trips)
    {
        int passengers = trip[0];
        int pickup = trip[1];
        int drop = trip[2];

        // Passengers enter
        diff[pickup] += passengers;

        // Passengers leave
        diff[drop] -= passengers;
    }

    int currentPassengers = 0;

    // Line Sweep
    for (int location = 0; location <= 1000; location++)
    {
        currentPassengers += diff[location];

        if (currentPassengers > capacity)
        {
            return false;
        }
    }

    return true;
}


// ============================================================
// APPROACH 3: ORDERED MAP + LINE SWEEP
// ============================================================

bool carPoolingMap(vector<vector<int>>& trips,
                   int capacity)
{
    map<int, int> changes;

    for (auto& trip : trips)
    {
        int passengers = trip[0];
        int pickup = trip[1];
        int drop = trip[2];

        // Event at pickup
        changes[pickup] += passengers;

        // Event at drop
        changes[drop] -= passengers;
    }

    int currentPassengers = 0;

    // map automatically locations ko sorted order me rakhta hai
    for (auto& [location, change] : changes)
    {
        currentPassengers += change;

        if (currentPassengers > capacity)
        {
            return false;
        }
    }

    return true;
}


// ============================================================
// APPROACH 4: SORTED EVENTS + LINE SWEEP
// ============================================================

bool carPoolingEvents(vector<vector<int>>& trips, int capacity)
{
    // {location, passengerChange}
    vector<pair<int, int>> events;

    for (auto& trip : trips)
    {
        int passengers = trip[0];
        int pickup = trip[1];
        int drop = trip[2];

        // Pickup event
        events.push_back({pickup, passengers});

        // Drop event
        events.push_back({drop, -passengers});
    }

    // Sort events by location
    sort(events.begin(), events.end());

    int currentPassengers = 0;

    for (auto& [location, change] : events)
    {
        currentPassengers += change;

        if (currentPassengers > capacity)
        {
            return false;
        }
    }

    return true;
}


// ============================================================
// MAIN
// ============================================================

int main()
{
    vector<vector<int>> trips =
    {
        {2, 1, 5},
        {3, 3, 7}
    };

    int capacity = 4;


    bool answer1 = carPoolingBrute(trips, capacity);

    bool answer2 = carPoolingDifferenceArray(trips, capacity);

    bool answer3 = carPoolingMap(trips, capacity);

    bool answer4 = carPoolingEvents(trips, capacity);


    cout << "Brute Force       : "
         << (answer1 ? "true" : "false") << '\n';

    cout << "Difference Array  : "
         << (answer2 ? "true" : "false") << '\n';

    cout << "Ordered Map       : "
         << (answer3 ? "true" : "false") << '\n';

    cout << "Sorted Events     : "
         << (answer4 ? "true" : "false") << '\n';


    return 0;
}