class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxNum = nums[0];
        int minNum = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int maxEnd = max({nums[i], nums[i] * maxNum, nums[i] * minNum});
            int minEnd = min({nums[i], nums[i] * maxNum, nums[i] * minNum});
            result = max(maxEnd, result);
            maxNum = maxEnd;
            minNum = minEnd;
        }
        return result;
    }
};
