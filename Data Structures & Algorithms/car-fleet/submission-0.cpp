class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> time(position.size());
        for (int i = 0; i < position.size(); i++) {
            time[i].first = position[i];
            time[i].second = static_cast<double>(target - position[i]) / static_cast<double>(speed[i]);
        }
        sort(time.begin(), time.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
            return a.first > b.first;
        });
        int result = 1;
        for (int i = 1; i < position.size(); i++) {
            if (time[i].second <= time[i - 1].second) {
                time[i].second = time[i - 1].second;
            } else {
                result++;
            }
        }
        return result;
    }
};
