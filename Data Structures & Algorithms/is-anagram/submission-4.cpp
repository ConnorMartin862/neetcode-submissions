class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> storage(26, 0);
        for (char c : s) {
            int a = c - 'a';
            storage[a]++;
        }
        for (char c : t) {
            int a = c - 'a';
            if (storage[a] == 0) {
                return false;
            }
            storage[a]--;
        }
        for (int i : storage) {
            if (i != 0) {return false;}
        }
        return true;
    }
};
