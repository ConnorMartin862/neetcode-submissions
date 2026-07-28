class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for (string str : strs) {
            result += to_string(str.size());
            result.push_back(',');
            result += str;
        }
        return result;
    }

    vector<string> decode(string s) {
        int ptr = 0;
        vector<string> results;
        while (ptr < s.size()) {
            int start = ptr;
            while (isdigit(s[ptr])) {
                ptr++;
            }
            int value = stoi(s.substr(start, ptr - start));
            ptr++;
            results.push_back(s.substr(ptr, value));
            ptr += value;
        }
        return results;
    }
};
