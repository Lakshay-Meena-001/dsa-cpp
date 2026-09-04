#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long dividePlayers(vector<int> &skill)
{
    sort(skill.begin(), skill.end());

    int n = skill.size();

    long long totalSkill = 0;

    for (int x : skill)
    {
        totalSkill += x;
    }

    int teams = n / 2;
    // Every team must have the same skill sum.
    // Number of teams = n / 2.
    if (totalSkill % (teams) != 0)
    {
        return -1;
    }

    long long target = totalSkill / teams;

    int left = 0;
    int right = n - 1;

    long long chemistry = 0;

    while (left < right)
    {
        // Smallest + largest must form exactly target.
        if (skill[left] + skill[right] != target)
        {
            return -1;
        }

        chemistry += 1LL * skill[left] * skill[right];

        // Both players are now consumed.
        left++;
        right--;
    }

    return chemistry;
}

int main()
{
    vector<int> skill = {3, 2, 5, 4};

    cout << dividePlayers(skill) << endl;

    return 0;
}