class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) {return nums;}
        deque<int> storage;
        vector<int> results;
        for (int i = 0; i < k; i++) {
            while (!storage.empty() && nums[i] > nums[storage.back()]) {
                storage.pop_back();
            }
            storage.push_back(i);
        }
        results.push_back(nums[storage.front()]);
        int right = k;
        int left = 1;
        while (right < nums.size()) {
            while (!storage.empty() && nums[right] > nums[storage.back()]) {
                storage.pop_back();
            }
            storage.push_back(right);
            while (storage.front() < left) {
                storage.pop_front();
            }
            results.push_back(nums[storage.front()]);
            right++;
            left++;
        }
        return results;
    }
};
