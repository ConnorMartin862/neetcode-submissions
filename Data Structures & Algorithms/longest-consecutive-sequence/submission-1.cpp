class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> storage;
        for (int i : nums) {
            storage.insert(i);
        }

        int result = 0;
        for (auto& item : storage) {
            if (!storage.count(item - 1)) {
                int temp = 1;
                int index = item + 1;
                while (storage.count(index)) {
                    temp++;
                    index++;
                }
                result = max(temp, result);
            }
        }
        return result;
    }
};
