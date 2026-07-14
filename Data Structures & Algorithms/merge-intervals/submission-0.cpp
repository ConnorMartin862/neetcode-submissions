class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> results;
        results.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            vector<int> curr = intervals[i];
            if (results.back()[1] >= curr[0]) {
                results.back()[1] = max(results.back()[1], curr[1]);
            } else {
                results.push_back(curr);
            }
        }

        return results;
    }
};
