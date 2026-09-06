class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> storage;
        vector<vector<string>> results;
        for (string str : strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            if (storage.count(temp)) {
                results[storage[temp]].push_back(str);
            } else {
                storage[temp] = results.size();
                results.push_back({str});
            }
        }
        return results;
    }
};
