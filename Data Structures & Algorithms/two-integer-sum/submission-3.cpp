class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> storage;
        for (int i = 0; i < nums.size(); i++) {
            if (storage.count(nums[i])) {
                return {storage[nums[i]], i};
            } else {
                int complement = target - nums[i];
                storage[complement] = i;
            }
        }
        return {0,0};
    }
};
