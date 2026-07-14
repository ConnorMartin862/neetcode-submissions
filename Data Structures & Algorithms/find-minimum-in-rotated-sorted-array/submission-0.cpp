class Solution {
public:
    int findMin(vector<int> &nums) {
        int start = 0;
        int end = nums.size() - 1;
        while (end - start > 1) {
            int middle = start + ((end - start) / 2);
            if (nums[middle] > nums[end]) {
                start = middle;
                // break is in back half
            } else if (nums[middle] < nums[start]) {
                end = middle;
                // break is in front half
            } else {
                return nums[start];
                // no break
            }
        }
        return min(nums[end], nums[start]);
    }
};
