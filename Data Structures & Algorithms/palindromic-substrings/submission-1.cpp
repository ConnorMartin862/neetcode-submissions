class Solution {
public:
    int countSubstrings(string s) {
        int results = 0;
        for (int i = 0; i < s.size(); i++) {
            int left = i;
            int right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                results++;
                left--;
                right++;
            }
            left = i;
            right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                results++;
                left--;
                right++;
            }
        }
        return results;
    }
};
