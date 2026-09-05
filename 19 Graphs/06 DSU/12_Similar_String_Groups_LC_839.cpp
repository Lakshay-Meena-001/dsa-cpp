/*
------------------------------------------------------------

Problem : Similar String Groups (LC 839)

Pattern
-------
Disjoint Set Union (DSU)
+
Hidden Graph
+
Connected Components

Time Complexity
---------------
O(N² × L)

N = Number of Strings
L = Length of Each String

Space Complexity
----------------
O(N)

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
    vector<int> size;
    int components;

public:

    DisjointSet(int n)
    {
        parent.resize(n);
        size.resize(n,1);

        components=n;

        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }

    int findParent(int node)
    {
        if(parent[node]==node)
        {
            return node;
        }

        return parent[node]=findParent(parent[node]);
    }

    void unionBySize(int u,int v)
    {
        int leaderU=findParent(u);
        int leaderV=findParent(v);

        if(leaderU==leaderV)
        {
            return;
        }

        if(size[leaderU]<size[leaderV])
        {
            parent[leaderU]=leaderV;
            size[leaderV]+=size[leaderU];
        }
        else
        {
            parent[leaderV]=leaderU;
            size[leaderU]+=size[leaderV];
        }

        components--;
    }

    int getComponents()
    {
        return components;
    }
};

// Returns true if two strings are similar.

bool similar(string first, string second)
{
    int difference=0;

    for(int i=0;i<first.size();i++)
    {
        if(first[i]!=second[i])
        {
            difference++;
        }
    }

    return difference==0 || difference==2;
}



int numberOfGroups(vector<string>& strs)
{
    int n=strs.size();

    DisjointSet ds(n);

    // Compare every pair

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(similar(strs[i],strs[j]))
            {
                ds.unionBySize(i,j);
            }
        }
    }

    return ds.getComponents();
}

//driver main

int main()
{
    vector<string> strs=
    {
        "tars",
        "rats",
        "arts",
        "star"
    };

    cout<<"Number Of Groups = ";

    cout<<numberOfGroups(strs);

    return 0;
}