class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        vector<int> storage(26, 0);
        int result = 0;
        int maxFreq = 0;
        while (right < s.size()) {
            storage[s[right] - 'A']++;
            maxFreq = max(maxFreq, storage[s[right] - 'A']);            
            if (right - left + 1 > maxFreq + k) {
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
