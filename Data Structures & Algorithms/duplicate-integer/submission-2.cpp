class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> storage;
        for (int num : nums) {
            if (storage.count(num)) {
                return true;
            }
            storage.insert(num);
        }
        return false;
    }
};