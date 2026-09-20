class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> storage;
        int n = heights.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            while (!storage.empty() && heights[storage.top()] > heights[i]) {
                int height = heights[storage.top()];
                storage.pop();
                int width = 0;
                if (storage.empty()) {width = i;}
                else {width = i - storage.top() - 1;}
                result = max(result, width * height);
            }
            storage.push(i);
        }

        while (!storage.empty()) {
            int height = heights[storage.top()];
            storage.pop();
            int width = 0;
            if (storage.empty()) {width = n;}
            else {width = n - storage.top() - 1;}
            result = max(result, height * width);
        }
        return result;
    }
};
