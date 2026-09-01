#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2)
{
    // value is bounded, so we can use
    // the value directly as an index.
    vector<int> weight(1001, 0);

    // Add weights from items1
    for (auto &item : items1)
    {
        int value = item[0];
        int w = item[1];

        weight[value] += w;
    }

    // Add weights from items2
    for (auto &item : items2)
    {
        int value = item[0];
        int w = item[1];

        weight[value] += w;
    }

    vector<vector<int>> answer;

    // Scan values in increasing order
    for (int value = 1; value <= 1000; value++)
    {
        if (weight[value] != 0)
        {
            answer.push_back({value, weight[value]});
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> items1 =
        {
            {1, 1},
            {4, 5},
            {3, 8}};

    vector<vector<int>> items2 =
        {
            {3, 1},
            {1, 5}};

    vector<vector<int>> answer =
        mergeSimilarItems(items1, items2);

    for (auto &item : answer)
    {
        cout << "[" << item[0]
             << ", " << item[1]
             << "] ";
    }

    return 0;
}