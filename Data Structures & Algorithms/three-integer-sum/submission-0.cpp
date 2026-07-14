class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        for (int i = 0; i < nums.size(); i++) {
            int start = i + 1;
            int end = nums.size() - 1;
            while (start < end) {
                int value = nums[i] + nums[start] + nums[end];
                if (value == 0) {
                    results.push_back({nums[i], nums[start], nums[end]});
                    while (start < end && nums[start + 1] == nums[start]) {
                        start++;
                    }
                    start++;
                    while (start < end && nums[end - 1] == nums[end]) {
                        end--;
                    }
                    end--;
                } else if (value > 0) {
                    end--;
                } else {
                    start++;
                }
            }
            while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        return results;
    }
};
