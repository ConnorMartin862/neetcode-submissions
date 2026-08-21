class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> memo;
        memo.push_back(nums[0]);
        int result = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > memo.back()) {
                result++;
                memo.push_back(nums[i]);
            } else {
                int index = lower_bound(memo.begin(), memo.end(), nums[i]) - memo.begin();
                memo[index] = nums[i];
            }
        }
        return result;
    }
};
