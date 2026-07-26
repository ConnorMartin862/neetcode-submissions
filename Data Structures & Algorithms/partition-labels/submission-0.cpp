class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> storage(26, -1);
        for (int i = 0; i < s.size(); i++) {
            int a = s[i] - 'a';
            storage[a] = i;
        }

        vector<int> result;
        int reach = 0;
        int last = -1;
        for (int i = 0; i < s.size(); i++) {
            int a = s[i] - 'a';
            reach = max(reach, storage[a]);
            if (i == reach) {
                result.push_back(reach - last);
                last = reach;
                reach++;
            }
        }
        return result;
    }
};
