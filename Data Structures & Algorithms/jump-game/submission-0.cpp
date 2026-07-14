class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            reach = max(reach, i + nums[i]);
            if (i == reach) {return false;}
        }
        return true;
    }
};
