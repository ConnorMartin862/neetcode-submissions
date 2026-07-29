class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> storage;
        for (int num : nums) {
            storage.insert(num);
        }
        int result = 0;
        for (int num : nums) {
            if (storage.count(num - 1)) {continue;}
            int count = 1;
            int index = num + 1;
            while (storage.count(index)) {
                index++;
                count++;
            }
            result = max(result, count);
        }
        return result;
    }
};
