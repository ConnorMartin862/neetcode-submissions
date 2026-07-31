class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.size() + 1, false);
        memo[0] = true;
        for (int i = 0; i < s.size(); i++) {
            for (string word: wordDict) {
                if (i >= word.size() - 1 && memo[i - word.size() + 1] && s.substr(i - word.size() + 1, word.size()) == word) {
                    memo[i + 1] = true;
                    break;
                }
            }
        }
        return memo[s.size()];
    }
};
