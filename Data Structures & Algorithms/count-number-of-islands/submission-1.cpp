class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int counter = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    counter++;
                    dfs(grid, i, j);
                }
            }
        }
        return counter;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (auto& dir : dirs) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            if (ni < grid.size() && ni >= 0 && nj < grid[0].size() && nj >= 0 && grid[ni][nj] == '1') {
                dfs(grid, ni, nj);
            }
        }

        return;
    }
};
