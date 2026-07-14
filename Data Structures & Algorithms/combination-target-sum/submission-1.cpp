class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        vector<int> current;
        backtracking(nums, results, current, target, 0);
        return results;
    }

    void backtracking(vector<int>& nums, vector<vector<int>>& results, 
            vector<int>& current, int target, int start) {
        if (target == 0) {
            results.push_back(current);
        } else {
            for (int i = start; i < nums.size(); i++) {
                if (nums[i] > target) {break;}
                current.push_back(nums[i]);
                backtracking(nums, results, current, target - nums[i], i);
                current.pop_back();
            }
        }
        return;
    }
};
