class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> storage;
        for (int i : nums) {
            storage[i]++;
        }
        int n = nums.size();
        vector<vector<int>> freq(n + 1);
        for (auto& item : storage) {
            freq[item.second].push_back(item.first);
        }
        vector<int> results;
        int index = n;
        while (results.size() < k) {
            if (!freq[index].empty()) {
                results.push_back(freq[index].back());
                freq[index].pop_back();
            } else {
                index--;
            }
        }
        return results;
    }
};
