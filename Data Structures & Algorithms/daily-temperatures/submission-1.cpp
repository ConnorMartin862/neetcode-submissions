class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> storage;
        vector<int> result(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            while (!storage.empty() && temperatures[storage.top()] < temperatures[i]) {
                result[storage.top()] = i - storage.top();
                storage.pop();
            }
            storage.push(i);
        }
        return result;
    }
};
