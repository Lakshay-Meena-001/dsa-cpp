/*

Problem : Number_Of_Islands_LC_200 (DSU Version)

Pattern
-------
Disjoint Set Union (DSU)
+
Grid Graph
+
Connected Components

Time Complexity
O(R × C × α(R × C))

Space Complexity
O(R × C)

*/

#include <iostream>
#include <vector>

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
        size.resize(n, 1);

        components = 0;

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    void addLand()
    {
        components++;
    }

    int findParent(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

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

        components--;
    }

    int getComponents()
    {
        return components;
    }
};

// Returns total number of islands.

int numberOfIslands(vector<vector<char>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    DisjointSet ds(rows * cols);

    // Step 1
    // Count every land cell as one component

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (grid[row][col] == '1')
            {
                ds.addLand();
            }
        }
    }

    // Step 2
    // Union adjacent land cells

    vector<pair<int, int>> directions =
        {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}};

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (grid[row][col] == '0')
            {
                continue;
            }

            int currentNode = row * cols + col;

            for (auto direction : directions)
            {
                int newRow = row + direction.first;
                int newCol = col + direction.second;

                if (newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols)
                {
                    continue;
                }

                if (grid[newRow][newCol] == '0')
                {
                    continue;
                }

                int neighbourNode = newRow * cols + newCol;

                ds.unionBySize(currentNode, neighbourNode);
            }
        }
    }

    return ds.getComponents();
}

// Driver

int main()
{
    vector<vector<char>> grid =
        {
            {'1', '1', '0'},
            {'0', '1', '0'},
            {'0', '0', '1'}};

    cout << "Number of Islands = ";

    cout << numberOfIslands(grid);

    return 0;
}