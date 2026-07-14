class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> storage;
        for (int i : nums) {
            if (storage.contains(i)) {
                return true;
            }
            storage.insert(i);
        }
        return false;
    }
};