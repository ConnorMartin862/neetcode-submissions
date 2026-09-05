class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> storage;
        int result = 0;
        int n = heights.size();

        for (int i = 0; i < n; i++) {
            while (!storage.empty() && heights[storage.top()] > heights[i]) {
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
            result = max(result, height * width);
        }
        return result;
    }
};
