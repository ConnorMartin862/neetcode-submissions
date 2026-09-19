class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> storage;
        int result = 0;
        for (int i = 0; i < heights.size(); i++) {
            int height = 0;
            while (!storage.empty() && heights[storage.top()] > heights[i]) {
                height = heights[storage.top()];
                storage.pop();
                int width = 0;
                if (storage.empty()) {width = i;}
                else {width = i - storage.top() - 1;}
                result = max(height * width, result);
            }
            storage.push(i);
        }
        while(!storage.empty()) {
            int height = heights[storage.top()];
            storage.pop();
            int width = 0;
            if (storage.empty()) {width = n;}
            else {width = n - storage.top() - 1;}
            result = max(height * width, result);
        }
        return result;
    }
};
