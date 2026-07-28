class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> storage;
        for (char c : s1) {
            storage[c]--;
        }
        int unsatisfied = storage.size();

        int left = 0;
        int right = 0;
        while (right < s1.size()) {
            if (storage.count(s2[right])) {
                storage[s2[right]]++;
                if (storage[s2[right]] == 0) {
                    unsatisfied--;
                }
            }
            right++;
        }

        if (unsatisfied == 0) {return true;}

        while (right < s2.size()) {
            if (storage.count(s2[left])) {
                storage[s2[left]]--;
                if (storage[s2[left]] == -1) {
                    unsatisfied++;
                }
            }
            left++;

            if (storage.count(s2[right])) {
                storage[s2[right]]++;
                if (storage[s2[right]] == 0) {
                    unsatisfied--;
                }
            }
            right++;

            if (unsatisfied == 0) {return true;}
        }
        return false;
    }
};
