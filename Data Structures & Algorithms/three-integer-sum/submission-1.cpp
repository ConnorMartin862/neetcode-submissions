class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int value = nums[i] + nums[j] + nums[k];
                if (value == 0) {
                    results.push_back({nums[i], nums[j], nums[k]});
                    int a = nums[j];
                    int b = nums[k];
                    while (j < k && nums[j] == a) {j++;}
                    while (j < k && nums[k] == b) {k--;}
                } else if (value > 0) {
                    int temp = nums[k];
                    while (j < k && nums[k] == temp) {k--;}
                } else {
                    int temp = nums[j];
                    while (j < k && nums[j] == temp) {j++;}
                }
            }
            int temp = nums[i];
            while (i < nums.size() - 2 && nums[i + 1] == temp) {i++;}
        }
        return results;
    }
};
