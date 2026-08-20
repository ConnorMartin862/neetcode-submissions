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
        for (string w : words) {
            LetterNode* curr = root;
            for (char c : w) {
                int a = c - 'a';
                if (!curr->children[a]) {
                    curr->children[a] = new LetterNode();
                }
                curr = curr->children[a];
            }
            curr->word = w;
        }

        vector<string> results;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(root, board, results, i, j);
            }
        }
        return results;
    }

        void dfs(LetterNode* curr, vector<vector<char>>& board, vector<string>& results, int i, int j) {
        if (!curr || board[i][j] == '#') {
            return;
        }
        char c = board[i][j];
        int a = c - 'a';

        LetterNode* next = curr->children[a];
        if (!next) return;

        if (!next->word.empty()) {
            results.push_back(next->word);
            next->word = "";
        }

        board[i][j] = '#';

        if (i > 0)                          {dfs(next, board, results, i - 1, j);}
        if (j < board[0].size() - 1)        {dfs(next, board, results, i, j + 1);}
        if (i < board.size() - 1)           {dfs(next, board, results, i + 1, j);}
        if (j > 0)                          {dfs(next, board, results, i, j - 1);}

        board[i][j] = c;
    }
};
