class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> storage(26, 0);
        int left = 0;
        int right = 0;
        int most = 0;
        while (right < s.size()) {
            while (right < s.size() && right - left <= k + most) {
                storage[s[right] - 'A']++;
                most = max(most, storage[s[right] - 'A']);
                right++;
            }
            storage[s[left] - 'A']--;
            left++;
        }
        int result = min(k + most, (int)s.size());
        return result;

    }
};
