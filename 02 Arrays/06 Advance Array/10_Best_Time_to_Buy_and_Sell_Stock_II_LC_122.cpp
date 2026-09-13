#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{

    // har bar sell karne par profit add hoga
    int profit = 0;

    // sbhi prices par loop
    for (int i = 1; i < prices.size(); i++)
    {

        // agar piche wale price se ajka price zyada hai bech do and profit collect karo har bar karte jao
        if (prices[i] > prices[i - 1])
        {
            profit += prices[i] - prices[i - 1];
        }
    }

    return profit;
}

int main()
{

    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "Maximum Profit = "
         << maxProfit(prices) << endl;

    return 0;
}