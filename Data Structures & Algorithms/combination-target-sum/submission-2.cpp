class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        vector<int> current;
        backtracking(results, current, nums, target, 0);
        return results;
    }

    void backtracking(vector<vector<int>>& results, vector<int>& current, 
            vector<int>& nums, int target, int start) {
        if (target == 0) {
            results.emplace_back(current);
        } else {
            for (int i = start; i < nums.size(); i++) {
                if (nums[i] > target) {break;}
                current.emplace_back(nums[i]);
                backtracking(results, current, nums, target - nums[i], i);
                current.pop_back();
            }
        }
        return;
    }
};
