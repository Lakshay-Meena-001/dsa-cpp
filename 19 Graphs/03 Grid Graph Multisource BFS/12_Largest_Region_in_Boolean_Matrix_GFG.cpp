#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int rows, cols;

    int dr[8] = {-1, -1, -1,
                  0,       0,
                  1,  1,  1};

    int dc[8] = {-1,  0,  1,
                 -1,  1,
                 -1,  0,  1};

    int dfs(int r, int c, vector<vector<int>>& mat) {

        // Boundary check
        if(r < 0 || r >= rows ||
           c < 0 || c >= cols ||
           mat[r][c] == 0) {

            return 0;
        }

        // Mark visited
        mat[r][c] = 0;

        int size = 1;

        // 8 neighbours explore karo
        for(int k = 0; k < 8; k++) {

            int nr = r + dr[k];
            int nc = c + dc[k];

            size += dfs(nr, nc, mat);
        }

        return size;
    }

    int largestRegion(vector<vector<int>>& mat) {

        rows = mat.size();
        cols = mat[0].size();

        int maxRegion = 0;

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {

                if(mat[r][c] == 1) {

                    int currentRegion = dfs(r, c, mat);

                    maxRegion = max(maxRegion, currentRegion);
                }
            }
        }

        return maxRegion;
    }
};