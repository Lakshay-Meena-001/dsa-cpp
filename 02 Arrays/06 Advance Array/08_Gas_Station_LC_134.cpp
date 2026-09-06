#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{

    int totalGas = 0;
    int totalCost = 0;

    int tank = 0;
    int start = 0;

    for (int i = 0; i < gas.size(); i++)
    {

        // Overall availability, ki total gas total cost se zyada ya barabar honi hi chahiye
        totalGas += gas[i];
        totalCost += cost[i];

        // Petrol gained/lost at this station, jitna pichla petrol tha + abhi current kitna mila station i par - requirement kitni hai aage badhne k liye 
        tank += gas[i] - cost[i];

        // Current start cannot work
        if (tank < 0)
        {
            start = i + 1;
            tank = 0;
        }
    }

    // Not enough petrol overall
    if (totalGas < totalCost)
    {
        return -1;
    }

    return start;
}

int main()
{

    vector<int> gas = {4, 6, 7, 4, 5, 3, 5};
    vector<int> cost = {6, 5, 3, 5, 2, 6, 2};

    cout << canCompleteCircuit(gas, cost) << endl;

    return 0;
}