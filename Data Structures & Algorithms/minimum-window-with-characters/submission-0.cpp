class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {return "";}
        int right = 0;
        int left = 0;
        unordered_map<char, int> storage;
        for (char c : t) {
            storage[c]--;
        }
        int unsatisfied = storage.size();
        int length = INT_MAX;
        int maxLeft = left;
        while (right < s.size()) {
            if (!storage.count(s[right])) {right++; continue;}
            storage[s[right]]++;
            if (storage[s[right]] == 0) {unsatisfied--;}
            right++;
            while (unsatisfied == 0) {
                if (right - left < length) {
                    length = right - left;
                    maxLeft = left;
                }
                if (!storage.count(s[left])) {left++; continue;}
                storage[s[left]]--;
                if (storage[s[left]] == -1) {unsatisfied++;}
                left++;
            }
        }
        if (length == INT_MAX) {return "";}
        string result = s.substr(maxLeft, length);
        return result;
    }
};
