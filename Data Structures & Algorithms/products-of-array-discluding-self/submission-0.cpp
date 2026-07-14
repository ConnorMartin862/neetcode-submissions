class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);
        vector<int> results(n, 0);
        int p = 1;
        int s = 1;
        for (int i = 0; i < n; i++) {
            p *= nums[i];
            prefix[i] = p;
        }
        for (int i = n - 1; i >= 0; i--) {
            s *= nums[i];
            suffix[i] = s;
        }
        results[0] = suffix[1];
        results[n - 1] = prefix[n - 2];
        for (int i = 1; i < n - 1; i++) {
            results[i] = prefix[i - 1] * suffix[i + 1];
        }
        return results;
    }
};
