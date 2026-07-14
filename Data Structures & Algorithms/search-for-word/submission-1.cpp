class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && backtracking(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool backtracking(vector<vector<char>>& visited, string& word, int index, int i, int j) {
        if (index == word.size() - 1) {
            return true;
        }

        char temp = visited[i][j];
        visited[i][j] = '.';
        index++;

        int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (auto& d : dirs) {
            int ni = i + d[0];
            int nj = j + d[1];

            if (ni >= 0 && ni < visited.size()
                && nj >= 0 && nj < visited[0].size()
                && visited[ni][nj] == word[index]) {
                if (backtracking(visited, word, index, ni, nj)) {
                    visited[i][j] = temp;
                    return true;
                }
            }
        }

        visited[i][j] = temp;
        return false;
    }
};
