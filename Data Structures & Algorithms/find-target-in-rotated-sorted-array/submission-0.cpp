class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while (end - start > 1) {
            int mid = start + ((end - start) / 2);
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < nums[start]) {
                if (nums[mid] < target && target <= nums[end]) {
                    start = mid;
                }
                else {
                    end = mid;
                }
            } // break at start half
            else if (nums[end] < nums[mid]) {
                if (nums[start] <= target && target < nums[mid]) {
                    end = mid;
                }
                else {
                    start = mid;
                }
            } // break at end half
            else {
                if (nums[mid] > target) {
                    end = mid;
                }
                else {
                    start = mid;
                }
            } // no break
        }
        
        if (target == nums[start]) {
            return start;
        }
        else if (target == nums[end]) {
            return end;
        }

        return -1;
    }
};
