class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> storage(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size()  + 1, 0);
        return helper(s, 0, memo, storage);
    }

    bool helper (string& s, int start, vector<int>& memo, unordered_set<string>& storage) {
        if (start == s.size()) {return true;}
        if (memo[start] == -1) {return false;}
        for (auto& word : storage) {
            if (s.substr(start, word.size()) == word) {
                if (helper(s, start + word.size(), memo, storage)) {return true;}
            }
        }
        
        memo[start] = -1;
        return false;
    }
};
