class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size() + 1);
        memo[0] = 0;
        memo[1] = nums[0];
        if (nums.size() > 1) {
            memo[2] = max(nums[1], nums[0]);
        }
        for (int i = 3; i < nums.size() + 1; i++) {
            memo[i] = max(memo[i - 2], memo[i - 3]) + nums[i - 1];
        }
        return max(memo[nums.size()], memo[nums.size() - 1]);
    }
};
