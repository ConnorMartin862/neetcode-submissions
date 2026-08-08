class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {return false;}
        vector<int> storage(26, 0);
        for (char c : s) {storage[c - 'a']++;}
        for (char c : t) {
            storage[c - 'a']--;
            if (storage[c - 'a'] == -1) {return false;}
        }
        return true;
    }
};
