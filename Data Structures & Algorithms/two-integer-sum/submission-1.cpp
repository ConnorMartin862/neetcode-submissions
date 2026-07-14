class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> storage;
        for (int i = 0; i < nums.size(); i++) {
            if (storage.count(nums[i])) {
                return {storage[nums[i]], i};
            }
            storage[target - nums[i]] = i;
        }
        return {-1, -1};
    }
};
