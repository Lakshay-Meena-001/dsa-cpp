#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// LC121 - Best Time to Buy and Sell Stock

// Pattern: Running Minimum + Running Best Answer

// Time  : O(n)
// Space : O(1)

int maxProfit(vector<int> &prices)
{
    int minPrice = INT_MAX;
    int bestProfit = 0;

    for (int price : prices)
    {
        // Sell today
        int profit = price - minPrice;

        // Best profit till now
        bestProfit = max(bestProfit, profit);

        // Cheapest buying price till now
        minPrice = min(minPrice, price);
    }

    return bestProfit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "Maximum Profit = ";

    cout << maxProfit(prices);

    return 0;
}