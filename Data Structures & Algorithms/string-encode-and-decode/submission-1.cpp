class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for (string s : strs) {
            result += to_string(s.size());
            result += '#';
            result += s;
        }
        return result;
    }

    vector<string> decode(string s) {
        int ptr = 0;
        vector<string> results;
        while (ptr < s.size()) {
            // Handle Number
            int value = 0;
            int start = ptr;
            while (isdigit(s[ptr])) {
                value++;
                ptr++;
            }
            int len = stoi(s.substr(start, value));
            // Handle Dash
            ptr++;
            // Handle String
            results.push_back(s.substr(ptr, len));
            ptr += len;
        }
        return results;
    }
};
