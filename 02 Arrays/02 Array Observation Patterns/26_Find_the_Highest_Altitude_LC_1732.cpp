#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int largestAltitude(vector<int> &gain)
{
    int currentAltitude = 0;
    int highestAltitude = 0;

    for (int change : gain)
    {
        // Update current altitude
        currentAltitude += change;

        // Update highest altitude
        highestAltitude = max(highestAltitude, currentAltitude);
    }

    return highestAltitude;
}

int main()
{
    vector<int> gain = {-5, 1, 5, 0, -7};

    cout << "Highest Altitude = ";

    cout << largestAltitude(gain);

    return 0;
}