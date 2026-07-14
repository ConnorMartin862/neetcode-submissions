class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prefix = 0;
        int result = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            result = max(result, prefix);
            if (prefix < 0) {prefix = 0;}
        }
        return result;
    }
};
