class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {return false;}
        vector<int> storage(26);
        for (char c : s) {
            storage[c - 'a']++;
        }
        for (char c : t) {
            if (storage[c - 'a'] == 0) {
                return false;
            }
            storage[c- 'a']--;
        }
        return true;
    }
};
