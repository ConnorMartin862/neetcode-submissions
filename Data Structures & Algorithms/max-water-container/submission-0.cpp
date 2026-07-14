class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int result = 0;
        while (left < right) {
            int value = min(heights[left], heights[right]);
            result = max(result, (right - left) * value);
            if (heights[left] > heights[right]) {
                right--;
            } else {
                left++;
            }
        }
       return result;
    }
};
