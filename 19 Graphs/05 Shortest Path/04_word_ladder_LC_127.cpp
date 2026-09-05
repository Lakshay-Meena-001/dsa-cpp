/*
-------------------------------------------------------
LeetCode 127 : Word Ladder

Pattern
-------
Implicit Graph
+
Unweighted Shortest Path
+
BFS

Time Complexity
---------------
O(N × L × 26)

N = Number of words
L = Length of each word

Space Complexity
----------------
O(N)

-------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

// Returns minimum transformation sequence length

int wordLadderLength(string beginWord, string endWord, vector<string> &wordList)
{
    // Store all dictionary words inside hash set.
    // Why?
    // Fast O(1) average lookup.

    unordered_set<string> dictionary;

    for (string word : wordList)
    {
        dictionary.insert(word);
    }

    // If destination itself doesn't exist,
    // answer is impossible.

    if (dictionary.find(endWord) == dictionary.end())
    {
        return 0;
    }

    // Queue stores:
    // Current Word
    // Current Level (distance)

    queue<pair<string, int>> q;

    q.push({beginWord, 1});

    // Mark source visited.

    dictionary.erase(beginWord);

    // Standard BFS

    while (!q.empty())
    {
        string currentWord = q.front().first;
        int level = q.front().second;

        q.pop();

        // Destination reached.

        if (currentWord == endWord)
            return level;

        // Try changing every character.

        for (int i = 0; i < currentWord.size(); i++)
        {
            // Save original character.

            char originalCharacter = currentWord[i];

            // Replace with a-z

            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                // Skip same character.

                if (ch == originalCharacter)
                {
                    continue;
                }

                currentWord[i] = ch;

                // Word exists?

                if (dictionary.find(currentWord) != dictionary.end())
                {
                    q.push({currentWord, level + 1});

                    // Remove immediately.
                    // Acts as visited.

                    dictionary.erase(currentWord);
                }
            }

            // Restore original word.

            currentWord[i] = originalCharacter;
        }
    }

    // Destination unreachable.

    return 0;
}

int main()
{
    string beginWord = "hit";

    string endWord = "cog";

    vector<string> wordList =
        {
            "hot",
            "dot",
            "dog",
            "lot",
            "log",
            "cog"};

    int answer = wordLadderLength(beginWord, endWord, wordList);

    cout << "Minimum Transformation Length = ";

    cout << answer << endl;

    return 0;
}