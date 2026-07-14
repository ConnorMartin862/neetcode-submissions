class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {return "";}
        unordered_map<char, int> storage;
        for (char c : t) {
            storage[c]--;
        }
        int unsatisfied = storage.size();
        int left = 0;
        int right = 0;
        int minLeft = -1;
        int length = INT_MAX;

        while (right < s.size()) {
            if (storage[s[right]] == -1) {unsatisfied--;}
            storage[s[right]]++;

            while (unsatisfied == 0) {
                if (right - left + 1 < length) {
                    length = right - left + 1;
                    minLeft = left;
                }
                storage[s[left]]--;
                if (storage[s[left]] == -1) {unsatisfied++;}
                left++;
            }
            right++;
        }

        if (minLeft == -1) {return "";}
        string result = s.substr(minLeft, length);
        return result;
    }
};
