#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// GFG - Alien Dictionary

// Approach : Kahn's Algorithm (Topological Sort)

// Time Complexity : O(N * L + K + E)
// N = Number of Words
// L = Average Word Length
// K = Number of Characters
// E = Number of Edges

// Space Complexity : O(K + E)

string findOrder(string dict[],int N,int K)
{
    vector<vector<int>> adj(K);

    vector<int> indegree(K, 0);

    // Step 1 : Build Graph

    for (int i = 0; i < N - 1; i++)
    {
        string word1 = dict[i];
        string word2 = dict[i + 1];

        int len = min(word1.length(), word2.length());

        for (int j = 0; j < len; j++)
        {
            if (word1[j] != word2[j])
            {
                int u = word1[j] - 'a';
                int v = word2[j] - 'a';

                adj[u].push_back(v);

                indegree[v]++;

                break;
            }
        }
    }

    queue<int> q;

    // Step 2 : Push all nodes having indegree = 0

    for (int i = 0; i < K; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    string answer = "";

    // Step 3 : Kahn's Algorithm

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        answer += char(node + 'a');

        for (int neighbour : adj[node])
        {
            indegree[neighbour]--;

            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    return answer;
}

//---------------------------------------------------------
// Driver Code
//---------------------------------------------------------

int main()
{
    int N = 5;
    int K = 4;

    string dict[] =
    {
        "baa",
        "abcd",
        "abca",
        "cab",
        "cad"
    };

    string order = findOrder(dict, N, K);

    cout << "Alien Dictionary Order : "
         << order
         << endl;

    return 0;
}