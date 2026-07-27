class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        int value = target + sum;
        if (value < 0 || value % 2 != 0) return 0;
        value /= 2;
        vector<vector<int>> memo (nums.size() + 1, vector<int>(value + 1, 0));
        memo[0][0] = 1;

        for (int i = 1; i < memo.size(); i++) {
            for (int j = 0; j < memo[0].size(); j++) {
                memo[i][j] = memo[i - 1][j] + (j >= nums[i - 1] ? memo[i - 1][j - nums[i - 1]] : 0);
            }
        }
        return memo[nums.size()][value];
    }
};
