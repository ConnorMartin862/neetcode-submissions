class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int actual = 0;
        int expected = 0;
        for (int i = 0; i < nums.size(); i++) {
            actual += nums[i];
            expected += i;
        }
        expected += nums.size();
        return expected - actual;
    }
};
