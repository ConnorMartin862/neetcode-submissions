class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> storage;
        vector<vector<string>> results;
        int index = 0;
        for (string& s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            if (storage.count(temp)) {results[storage[temp]].push_back(s);}
            else {
                storage[temp] = index;
                results.push_back({s});
                index++;
            }
        }
        return results;
    }
};
