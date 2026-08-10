class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(), 0);
        vector<int> postfix(nums.size(), 0);
        vector<int> result(nums.size(), 0);
        int pre = 1;
        for (int i = 0; i < nums.size(); i++) {
            pre *= nums[i];
            prefix[i] = pre;
        }

        int post = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            post *= nums[i];
            postfix[i] = post;
        }

        result[0] = postfix[1];
        result[nums.size() - 1] = prefix[nums.size() - 2];
        for (int i = 1; i < nums.size() - 1; i++) {
            result[i] = prefix[i - 1] * postfix[i + 1];
        }
        return result;
    }
};
