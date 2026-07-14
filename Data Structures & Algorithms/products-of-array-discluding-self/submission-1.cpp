class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, nums[0]);
        vector<int> postfix(n, nums[n - 1]);
        vector<int> results(n);
        int pre = nums[0];
        for (int i = 1; i < n; i++) {
            pre *= nums[i];
            prefix[i] = pre;
        }

        int post = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            post *= nums[i];
            postfix[i] = post;
        }

        results[0] = postfix[1];
        results[n - 1] = prefix[n - 2];
        for (int i = 1; i < n - 1; i++) {
            results[i] = prefix[i - 1] * postfix[i + 1];
        }
        return results;
    }
};
