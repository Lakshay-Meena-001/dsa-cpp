#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)

    {
        // ingredient -> recipes that depend on it/ is ingredient se kitni recipies
        unordered_map<string, vector<string>> dependents;

        // recipe -> number of ingredients still required/ is recipie k liye kitne ingredients
        unordered_map<string, int> need;

        // Initially available supplies/ supply se shuru 
        queue<string> q;

        // Build dependency graph
        for (int i = 0; i < recipes.size(); i++)
        {

            // ek ek karke recipie nikali 
            string recipe = recipes[i];

            // recipie k liye kitne ingredients
            need[recipe] = ingredients[i].size();

            for (string ingredient : ingredients[i])
            {
                dependents[ingredient].push_back(recipe);    
            }

        }

        // All initially available items
        for (string supply : supplies)
        {
            q.push(supply);
        }

        vector<string> ans;

        // Kahn-style dependency propagation
        while (!q.empty())
        {

            string item = q.front();
            q.pop();

            // Which recipes depend on this item?
            for (string recipe : dependents[item])
            {

                need[recipe]--;

                // All ingredients are now available
                if (need[recipe] == 0)
                {

                    ans.push_back(recipe);

                    // Recipe becomes a new available item
                    q.push(recipe);
                }
            }
        }

        return ans;
    }
};

int main()
{

    Solution sol;

    vector<string> recipes = {
        "bread",
        "sandwich"};

    vector<vector<string>> ingredients = {
        {"yeast", "flour"},
        {"bread", "meat"}};

    vector<string> supplies = {
        "yeast",
        "flour",
        "meat"};

    vector<string> result =
        sol.findAllRecipes(recipes, ingredients, supplies);

    for (string recipe : result)
    {
        cout << recipe << " ";
    }

    cout << "\n";

    return 0;
}