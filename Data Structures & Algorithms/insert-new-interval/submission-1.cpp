class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int upper = newInterval[1];
        int lower = newInterval[0];
        int index = 0;
        vector<vector<int>> results;
        while (index < intervals.size() && intervals[index][1] < lower) {
            results.push_back(intervals[index]);
            index++;
        }
        while (index < intervals.size() && intervals[index][0] <= upper) {
            upper = max(upper, intervals[index][1]);
            lower = min(lower, intervals[index][0]);
            index++;
        }
        results.push_back({lower, upper});
        while (index < intervals.size()) {
            results.push_back(intervals[index]);
            index++;
        }
        return results;
    }
};
