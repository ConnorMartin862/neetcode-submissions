class LetterNode {
public:
    LetterNode* children[26];
    string word;
    LetterNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        word = "";
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        LetterNode* root = new LetterNode();
        for (string& word : words) {
            LetterNode* curr = root;
            for (char c : word) {
                int a = c - 'a';
                if (!curr->children[a]) {
                    curr->children[a] = new LetterNode();
                }
                curr = curr->children[a];
            }
            curr->word = word;
        }

        vector<string> results;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root, results);
            }
        }
        return results;
    }

    void dfs(vector<vector<char>>& board, int i, int j, LetterNode* node, vector<string>& results) {
        char c = board[i][j];
        if (c == '#' || !node->children[c - 'a']) {return;}

        node = node->children[c - 'a'];
        if (!node->word.empty()) {
            results.push_back(node->word);
            node->word = "";
        }

        board[i][j] = '#';

        if (i > 0) {dfs(board, i - 1, j, node, results);}
        if (j > 0) {dfs(board, i, j - 1, node, results);}
        if (i < board.size() - 1) {dfs(board, i + 1, j, node, results);}
        if (j < board[0].size() - 1) {dfs(board, i, j + 1, node, results);}
        board[i][j] = c;
        return;
    }

};
