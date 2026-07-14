class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        vector<int> current;
        backtracking(nums, target, 0, results, current);
        return results;
    }

    void backtracking(vector<int>& nums, int target, int start, vector<vector<int>>& results, vector<int>& current) {
        if (target == 0) {
            results.emplace_back(current);
        }
        else {
            for (int i = start; i < nums.size(); i++) {
                if (nums[i] > target) {break;}
                current.push_back(nums[i]);
                backtracking(nums, target - nums[i], i, results, current);
                current.pop_back();
            }
        }
        return;
    }
};
