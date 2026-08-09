class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> storage;
        for (int num : nums) {
            storage[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& object : storage) {
            buckets[object.second].push_back(object.first);
        }

        vector<int> results;
        int index = nums.size();
        while (index >= 0) {
            if (buckets[index].empty()) {
                index--;
            } else {
                results.push_back(buckets[index].back());
                buckets[index].pop_back();
                if (results.size() == k) {
                    break;
                }
            }
        }

        return results;
    }
};
