class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> storage;
        for (int i : nums) {
            storage.insert(i);
        }
        int counter = 0;
        for (auto& i : storage) {
            if (!storage.count(i - 1)) {
                int temp = i;
                int temp_count = 0;
                while (storage.count(temp)) {
                    temp_count++;
                    temp++;
                }
                counter = max(counter, temp_count);
            }
        }
        return counter;
    }
};
