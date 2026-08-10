class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> results;
        results.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > results.back()[1]) {
                results.push_back(intervals[i]);
            } else {
                results.back()[1] = max(results.back()[1], intervals[i][1]);
            }
        }

        return results;
    }
};
