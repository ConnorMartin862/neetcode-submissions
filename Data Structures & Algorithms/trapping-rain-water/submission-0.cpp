class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int hLeft = 0;
        int right = height.size() - 1;
        int hRight = 0;
        int result = 0;
        while (left < right) {
            if (height[left] > hLeft) {
                hLeft = height[left];
            } 
            if (height[right] > hRight) {
                hRight = height[right];
            }
            int minHeight = min(hLeft, hRight);
            if (height[left] < minHeight) {
                result += (minHeight - height[left]);
                height[left] = minHeight;
            }
            if (height[right] < minHeight) {
                result += (minHeight - height[right]);
                height[right] = minHeight;
            } 
            if (hLeft >= hRight) {
                right--;
            } else {
                left++;
            }
        }
        return result;
    }
};
