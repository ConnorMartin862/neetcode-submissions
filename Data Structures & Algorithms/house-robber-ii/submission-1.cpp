class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {return nums[0];}
        if (nums.size() == 2) {return max(nums[0], nums[1]);}
        vector<int> memoA(nums.size(), 0);
        vector<int> memoB(nums.size(), 0);
        memoA[0] = nums[0];
        memoA[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size() - 1; i++) {
            memoA[i] = max(memoA[i - 1], memoA[i - 2] + nums[i]);
        }

        memoB[1] = nums[1];
        memoB[2] = max(nums[1], nums[2]);
        for (int i = 3; i < nums.size(); i++) {
            memoB[i] = max(memoB[i - 1], memoB[i - 2] + nums[i]);
        }

        return max(memoA[nums.size() - 2], memoB[nums.size() - 1]);
    }
};
