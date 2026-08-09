class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> results;
        unordered_map<string, int> storage;
        for (string str : strs) {
            string copy = str;
            sort(copy.begin(), copy.end());
            if (storage.count(copy)) {
                results[storage[copy]].push_back(str);
            } else {
                storage.insert({copy, results.size()});
                results.push_back({str});
            }
        }
        return results;
    }
};
