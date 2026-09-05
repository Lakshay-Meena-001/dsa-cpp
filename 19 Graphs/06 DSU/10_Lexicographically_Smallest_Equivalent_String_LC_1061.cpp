/*
------------------------------------------------------------

Problem : Lexicographically Smallest Equivalent String (LC 1061)

Pattern
-------
Disjoint Set Union (DSU)
+
Character Grouping
+
Lexicographical Leader

Time Complexity
---------------
O(N * α(26))

Space Complexity
----------------
O(26)

------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class DisjointSet
{
private:
    vector<int> parent;

public:
    DisjointSet()
    {
        parent.resize(26);

        // Initially every character is its own parent.

        for (int i = 0; i < 26; i++)
        {
            parent[i] = i;
        }
    }

    // Find Ultimate Parent

    int findParent(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    // Lexicographical Union

    void unionCharacters(int u, int v)
    {
        int leaderU = findParent(u);
        int leaderV = findParent(v);

        if (leaderU == leaderV)
        {
            return;
        }

        // Smaller character becomes leader. isme hum ye kar rahe hai ki jo chota character hoga usko leader bana denge taki answer lexicographically smallest ho.

        if (leaderU < leaderV)
        {
            parent[leaderV] = leaderU;
        }
        else
        {
            parent[leaderU] = leaderV;
        }
    }
};

//------------------------------------------------------------

string smallestEquivalentString(string s1, string s2, string baseStr)
{
    DisjointSet ds;

    // Build Character Groups

    for (int i = 0; i < s1.size(); i++)
    {
        int firstCharacter = s1[i] - 'a';
        int secondCharacter = s2[i] - 'a';

        ds.unionCharacters(firstCharacter, secondCharacter);
    }

    // Build Answer

    string answer = "";

    for (char character : baseStr)
    {
        int leader = ds.findParent(character - 'a');

        //implicit narrowing conversion from int to char
        answer.push_back(leader + 'a');
    }

    return answer;
}

// Driver Main

int main()
{
    string s1 = "abc";
    string s2 = "cde";

    string baseStr = "eed";

    cout << smallestEquivalentString(
        s1,
        s2,
        baseStr);

    return 0;
}