class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (right >= left) {
            if (!isalnum(s[left])) {
                left++;
            } else if (!isalnum(s[right])) {
                right--;
            } else {
                if (toupper(s[left]) != toupper(s[right])) {
                    return false;
                }
                left++;
                right--;
            }
        }
        return true;
    }
};
