class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> storage;
        int left = 0;
        int right = 0;
        int result = 0;
        while (right < s.size()) {
            if (!storage.count(s[right])) {
                storage.insert(s[right]);
                result = max(result, right - left + 1);
                right++;
            }
            else {
                while (storage.count(s[right])) {
                    storage.erase(s[left]);
                    left++;
                }
            }
        }
        return result;
    }
};
