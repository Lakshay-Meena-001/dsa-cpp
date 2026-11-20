#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int largestAltitude(vector<int> &gain)
{
    int currentAltitude = 0;
    int highestAltitude = 0;

    // bohot simple hai jaise hi gain array ke elements ko iterate karte hai, current altitude ko update karte hai aur highest altitude ko track karte hai. matlab ki mai abhi jaha hu and aage jaake mai kitna upar jaa sakta hu ye track karte hai. agar wo highest altitude se bada hai to highest altitude ko update karte hai. otherwise wahi highest altitude ko return karte hai.
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