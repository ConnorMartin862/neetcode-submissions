class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> storage(26, 0);
        int left = 0;
        int right = 0;
        int result = 0;
        int index = 0;
        while (right < s.size()) {
            storage[s[right] - 'A']++;
            index = max(index, storage[s[right] - 'A']);
            if (right - left + 1 > index + k) {
                result = max(result, right - left);
                storage[s[left] - 'A']--;
                left++;
            }
            right++;
        }
        result = max(result, right - left);
        return result;
    }
};
