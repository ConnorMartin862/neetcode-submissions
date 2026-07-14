class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int result = INT_MIN;
        while (left < right) {
            int temp = (right - left) * min(heights[right], heights[left]);
            result = max(result, temp);
            if (heights[left] > heights[right]) {
                right--;
            } else {
                left++;
            }
        }
        return result;
    }
};
