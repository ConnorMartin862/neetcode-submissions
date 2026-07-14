class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while (end - start > 1) {
            int middle = start + ((end - start) / 2);
            if (nums[middle] > nums[end]) {
                // break is in end
                if (target >= nums[start] && target <= nums[middle]) {end = middle;}
                else {start = middle;}
            } else if (nums[middle] < nums[start]) {
                // break is in start
                if (target > nums[middle] && target <= nums[end]) {start = middle;}
                else {end = middle;}
            } else {
                // no break, treat as atypical binary serach
                if (target > nums[middle]) {start = middle;}
                else {end = middle;}
            }
        }
        if (nums[start] == target) {return start;}
        else if (nums[end] == target) {return end;}
        else {return -1;}
    }
};
