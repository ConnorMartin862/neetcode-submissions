class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {return false;}
        unordered_map<char, int> storage;
        for (char c : s) {storage[c]++;}
        for (char c : t) {
            if (!storage.count(c) || storage[c] == 0) {return false;}
            storage[c]--;
        }
        return true;
    }
};
