/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) {return a.start < b.start;});
        int start = 0;
        int end = -1;
        for (auto& i : intervals) {
            start = i.start;
            if (start < end) {
                return false;
            }
            end = i.end;
        }
        return true;
    }
};
