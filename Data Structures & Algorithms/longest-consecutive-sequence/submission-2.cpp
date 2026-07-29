class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> storage;
        for (int num : nums) {
            storage[num]++;
        }
        int result = 0;
        for (int num : nums) {
            if (storage[num - 1]) {continue;}
            int count = 1;
            int index = num + 1;
            while (storage[index]) {
                index++;
                count++;
            }
            result = max(result, count);
        }
        return result;
    }
};
