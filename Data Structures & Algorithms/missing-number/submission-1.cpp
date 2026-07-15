class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int actual = 0;
        int expected = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            actual += nums[i];
            expected += i;
        }
        return expected - actual;
    }
};
