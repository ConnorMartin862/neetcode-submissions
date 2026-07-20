class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    result++;
                    grid[i][j] = '0';
                    dfs(grid, i, j);
                }
            }
        }

        return result;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        vector<vector<int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        for (auto& dir : dirs) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            if (ni >= 0 && ni < grid.size()
                && nj >= 0 && nj < grid[0].size()
                && grid[ni][nj] == '1') {
                grid[ni][nj] = '0';
                dfs(grid, ni, nj);
            }
        }
        return;
    }
};
