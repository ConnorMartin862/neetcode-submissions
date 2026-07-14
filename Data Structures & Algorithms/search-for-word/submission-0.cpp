class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    char temp = board[i][j];
                    board[i][j] = '.';
                    if (backtracking(board, word, 0, i, j)) {
                        return true;
                    }
                    board[i][j] = temp;
                }
            }
        }
        return false;
    }

    bool backtracking(vector<vector<char>>& board, string word, int index, int i, int j) {
        if (index == word.size() - 1) {return true;}
        
        char temp = board[i][j];
        board[i][j] = '.';
        index++;

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto& d : dirs) {
            int ni = i + d[0];
            int nj = j + d[1];
            if (ni >= 0 && ni < board.size() 
                && nj >= 0 && nj < board[0].size()
                && board[ni][nj] == word[index]) {
                if (backtracking(board, word, index, ni, nj)) {
                    board[i][j] = temp;
                    return true;
                }
            }
        }
        board[i][j] = temp;
        return false;
    }
};
