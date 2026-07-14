class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0) {return "";}
        if (s.size() == 1) {return s;}
        int result = 0;
        int index = 0;
        for (int i = 0; i < s.size(); i++) {
            // Check for odd length palindromes
            int start = i;
            int end = i;
            while (start >= 0 && end < s.size() && s[start] == s[end]) {
                if (end - start + 1 > result) {
                    result = end - start + 1;
                    index = start;
                }
                start--;
                end++;
            }
            // Check for even length palindromes
            start = i;
            end = i + 1;
            while (start >= 0 && end < s.size() && s[start] == s[end]) {
                if (end - start + 1 > result) {
                    result = end - start + 1;
                    index = start;
                }
                start--;
                end++;
            }
        }
        return s.substr(index, result);
    }
};
