class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> storage;
        for (int i : nums) {
            storage.insert(i);
        }

        int result = 0;
        for (int i : nums) {
            if (storage.count(i - 1)) {
                continue;
            }
            int val = 0;
            while (storage.count(i)) {
                val++;
                i++;
            }
            result = max(result, val);
        }
        return result;
    }
};
