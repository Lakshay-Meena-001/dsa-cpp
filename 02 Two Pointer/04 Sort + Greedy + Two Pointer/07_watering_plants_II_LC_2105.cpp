#include <iostream>
#include <vector>
using namespace std;

int minimumRefill(vector<int> &plants, int capacityA, int capacityB)
{
    int left = 0;
    int right = plants.size() - 1;

    int waterA = capacityA;
    int waterB = capacityB;

    int refills = 0;

    while (left < right)
    {
        // Alice waters from the left.
        if (waterA < plants[left])
        {
            refills++;
            waterA = capacityA;
        }

        waterA -= plants[left];
        left++;

        // Bob waters from the right.
        if (waterB < plants[right])
        {
            refills++;
            waterB = capacityB;
        }

        waterB -= plants[right];
        right--;
    }

    // One plant remains in the middle.
    if (left == right)
    {
        int needed = plants[left];

        // The person with more remaining water
        // should handle the final plant.
        int maxWater = max(waterA, waterB);

        if (maxWater < needed)
        {
            refills++;
        }
    }

    return refills;
}

int main()
{
    vector<int> plants = {2, 4, 5};

    int capacityA = 5;
    int capacityB = 6;

    cout << minimumRefill(plants, capacityA, capacityB) << endl;

    return 0;
}