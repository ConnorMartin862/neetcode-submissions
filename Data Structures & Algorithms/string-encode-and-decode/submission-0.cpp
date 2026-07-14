class Solution {
public:

    string encode(vector<string>& strs) {
        string e = "";
        for (string s : strs) {
            e += to_string(s.size());
            e += '#';
            e += s;
        }
        return e;
    }

    vector<string> decode(string s) {
        vector<string> results;
        int i = 0;
        while (i < s.size()) {
            string num = "";
            while (isdigit(s[i])) {
                num += s[i];
                i++;
            }
            i++;
            int a = stoi(num);
            results.push_back(s.substr(i, a));
            i += a;
        }
        return results;
    }
};
