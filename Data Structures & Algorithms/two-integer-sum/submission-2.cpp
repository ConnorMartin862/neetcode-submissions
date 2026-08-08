class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> storage;
        vector<int> result(2, 0);
        for (int i = 0; i < nums.size(); i++) {
            if (storage.count(nums[i])) {
                return {storage[nums[i]], i};
            }
            storage[target - nums[i]] = i;
        }
        return {0, 0};
    }
};
