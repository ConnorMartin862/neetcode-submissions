class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int result = 0;
        unordered_set<char> storage;
        while (right < s.size()) {
            while (storage.count(s[right])) {
                storage.erase(s[left]);
                left++;
            }
            storage.insert(s[right]);
            right++;
            result = max(result, right - left);
        }
        return result;
    }
};
