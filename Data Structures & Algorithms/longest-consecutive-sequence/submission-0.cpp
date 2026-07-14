class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {return 0;}
        unordered_set<int> storage;
        int result = 1;
        for (int i : nums) {
            storage.insert(i);
        }
        for (auto& i : storage) {
            if (!storage.count(i - 1)) {
                int index = i;
                int value = 1;
                while (storage.count(index + 1)) {
                    index++;
                    value++;
                }
                result = max(value, result);
            }
            else {
                continue;
            }
        }
        return result;
    }
};
