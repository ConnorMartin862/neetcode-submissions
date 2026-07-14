class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, 1));
        for (int i = 2; i <= m; i++) {
            for (int j = 2; j <= n; j++) {
                memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
            }
        }
        return memo[m][n];
    }
};
