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
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) {
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (auto& i : intervals) {
            if (!minHeap.empty() && i.start >= minHeap.top()) {
                minHeap.pop();
            }
            minHeap.push(i.end);
        }
        return minHeap.size();
    }
};
