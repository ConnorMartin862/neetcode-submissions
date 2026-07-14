class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int lower = newInterval[0];
        int upper = newInterval[1];
        int index = 0;
        vector<vector<int>> newResult;
        while (index < intervals.size() && intervals[index][1] < lower) {
            newResult.push_back(intervals[index]);
            index++;
        }
        while (index < intervals.size() && intervals[index][0] <= upper) {
            lower = min(lower, intervals[index][0]);
            upper = max(upper, intervals[index][1]);
            index++;
        }
        newResult.push_back({lower, upper});
        while (index < intervals.size()) {
            newResult.push_back(intervals[index]);
            index++;
        }
        return newResult;
    }
};
