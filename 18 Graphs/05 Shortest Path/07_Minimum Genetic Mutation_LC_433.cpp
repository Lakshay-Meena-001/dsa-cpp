/*
------------------------------------------------------------

LeetCode 433 : Minimum Genetic Mutation

Pattern
-------
State Space Graph
+
Implicit Graph
+
Unweighted Shortest Path
+
BFS

Time Complexity
---------------
O(N × L × 4)

N = Number of genes
L = Length of gene (8)

Space Complexity
----------------
O(N)

------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

// Returns minimum mutations required

int minMutation(string startGene, string endGene, vector<string> &bank)
{
    // Store gene bank for O(1) lookup

    unordered_set<string> geneBank(bank.begin(), bank.end());

    // Destination must exist

    if (!geneBank.count(endGene))
    {
        return -1;
    }

    // Queue stores
    // (Current Gene, Mutations)

    queue<pair<string, int>> q;

    q.push({startGene, 0});

    // Mark start as visited

    geneBank.erase(startGene);

    // Allowed characters

    vector<char> choices = {'A', 'C', 'G', 'T'};

    // Standard BFS

    while (!q.empty())
    {
        string currentGene = q.front().first;
        int mutations = q.front().second;

        q.pop();

        // Destination reached

        if (currentGene == endGene)
            return mutations;

        // Try mutation at every position

        for (int i = 0; i < currentGene.size(); i++)
        {
            char originalCharacter = currentGene[i];

            // Try A,C,G,T

            for (char ch : choices)
            {
                if (ch == originalCharacter)
                    {continue;}

                currentGene[i] = ch;

                // Valid gene?

                if (geneBank.count(currentGene))
                {
                    q.push({currentGene, mutations + 1});

                    // Remove immediately
                    // (acts as visited)

                    geneBank.erase(currentGene);
                }
            }

            // Restore original gene

            currentGene[i] = originalCharacter;
        }
    }

    // Destination unreachable

    return -1;
}

int main()
{
    string startGene = "AACCGGTT";

    string endGene = "AAACGGTA";

    vector<string> bank =
        {
            "AACCGGTA",
            "AACCGCTA",
            "AAACGGTA"};

    cout << "Minimum Mutations = ";

    cout << minMutation(startGene, endGene, bank);

    return 0;
}