class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int minProd = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int maxEnd = max({nums[i], nums[i] * maxProd, nums[i] * minProd});
            int minEnd = min({nums[i], nums[i] * maxProd, nums[i] * minProd});
            result = max(maxEnd, result);
            maxProd = maxEnd;
            minProd = minEnd;
        }
        return result;
    }
};
