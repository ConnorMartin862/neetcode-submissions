class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> results;
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int res = nums[i] + nums[j] + nums[k];
                if (res > 0) {
                    int b = k;
                    while (b > j && nums[b] == nums[k]) {b--;}
                    k = b;
                } else if (res < 0) {
                    int a = j;
                    while (a < k && nums[a] == nums[j]) {a++;}
                    j = a;
                } else {
                    results.push_back({nums[i], nums[j], nums[k]});
                    int a = j;
                    int b = k;
                    while (a < k && nums[a] == nums[j]) {a++;}
                    while (b > j && nums[b] == nums[k]) {b--;}
                    j = a;
                    k = b;
                }
            }
            while (i < n - 1 && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        return results;
    }
};
