class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        int n = heights.size();
        stack<int> storage;
        for (int i = 0; i < heights.size(); i++) {
            while (!storage.empty() && heights[i] < heights[storage.top()]) {
                int height = heights[storage.top()];
                storage.pop();
                int width = storage.empty() ? i : i - storage.top() - 1;
                result = max(result, height * width);
            }
            storage.push(i);
        }
        while (!storage.empty()) {
            int height = heights[storage.top()];
            storage.pop();
            int width = storage.empty() ? n : n - storage.top() - 1;
            result = max(result, width * height);
        }
        return result;
    }
};
