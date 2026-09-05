/*
------------------------------------------------------------

Problem : Accounts_Merge_LC_721

Pattern
-------
Disjoint Set Union (DSU)
+
HashMap
+
Grouping

Time Complexity
---------------
O(N * M * α(N) + K log K)

N = Number of Accounts
M = Average Emails per Account
K = Total Emails

Space Complexity
----------------
O(K + N)

------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class DisjointSet
{
private:
    vector<int> parent;
    vector<int> size;

public:
    // Constructor

    DisjointSet(int n)
    {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    // Find Ultimate Parent
    // Path Compression

    int findParent(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    // Union By Size

    void unionBySize(int u, int v)
    {
        int leaderU = findParent(u);
        int leaderV = findParent(v);

        if (leaderU == leaderV)
        {
            return;
        }

        if (size[leaderU] < size[leaderV])
        {
            parent[leaderU] = leaderV;
            size[leaderV] += size[leaderU];
        }
        else
        {
            parent[leaderV] = leaderU;
            size[leaderU] += size[leaderV];
        }
    }
};

// Returns merged accounts.

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
    int numberOfAccounts = accounts.size();

    DisjointSet ds(numberOfAccounts);

    //---------------------------------------------------
    // Email -> Account Index
    //---------------------------------------------------

    unordered_map<string, int> emailOwner;

    for (int account = 0; account < numberOfAccounts; account++)
    {
        for (int email = 1; email < accounts[account].size(); email++)
        {
            string currentEmail = accounts[account][email];

            if (emailOwner.find(currentEmail) == emailOwner.end())
            {
                emailOwner[currentEmail] = account;
            }
            else
            {
                ds.unionBySize(account, emailOwner[currentEmail]);
            }
        }
    }

    //---------------------------------------------------
    // Leader -> Emails
    //---------------------------------------------------

    vector<vector<string>> mergedEmails(numberOfAccounts);

    for (auto entry : emailOwner)
    {
        string email = entry.first;
        int account = entry.second;

        int leader = ds.findParent(account);

        mergedEmails[leader].push_back(email);
    }

    //---------------------------------------------------
    // Build Final Answer
    //---------------------------------------------------

    vector<vector<string>> answer;

    for (int account = 0; account < numberOfAccounts; account++)
    {
        if (mergedEmails[account].empty())
        {
            continue;
        }

        sort(mergedEmails[account].begin(),
             mergedEmails[account].end());

        vector<string> currentAccount;

        // Name

        currentAccount.push_back(accounts[account][0]);

        // Emails

        for (string email : mergedEmails[account])
        {
            currentAccount.push_back(email);
        }

        answer.push_back(currentAccount);
    }

    return answer;
}

// Driver

int main()
{
    vector<vector<string>> accounts =
        {
            {"John", "johnsmith@mail.com", "john00@mail.com"},
            {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
            {"Mary", "mary@mail.com"},
            {"John", "johnnybravo@mail.com"}};

    vector<vector<string>> result =
        accountsMerge(accounts);

    for (auto account : result)
    {
        cout << "[ ";

        for (string value : account)
        {
            cout << value << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}