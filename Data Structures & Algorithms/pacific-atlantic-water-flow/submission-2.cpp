class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), false));

        for (int i = 0; i < heights.size(); i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, heights[0].size() - 1);
        }

        for (int j = 0; j < heights[0].size(); j++) {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, heights.size() - 1, j);
        }

        vector<vector<int>> results;
        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[0].size(); j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    results.push_back({i, j});
                }
            }
        }
        return results;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j) {
        int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        visited[i][j] = true;

        for (auto& dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            if (ni >= 0 && ni < visited.size()
                && nj >= 0 && nj < visited[0].size()
                && !visited[ni][nj] && heights[ni][nj] >= heights[i][j]) {
                dfs(heights, visited, ni, nj);
            }
        }
        return;
    }
};
