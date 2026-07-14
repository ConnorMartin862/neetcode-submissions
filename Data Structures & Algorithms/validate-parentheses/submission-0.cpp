class Solution {
public:
    bool isValid(string s) {
        stack<char> storage;
        for (char c : s) {
            if (c == '{' || c == '[' || c == '(') {
                storage.push(c);
            }
            else if (c == '}') {
                if (storage.empty() || storage.top() != '{') {
                    return false;
                }
                else {
                    storage.pop();
                }
            }
            else if (c == ']') {
                if (storage.empty() || storage.top() != '[') {
                    return false;
                }
                else {
                    storage.pop();
                }
            }
            else {
                if (storage.empty() || storage.top() != '(') {
                    return false;
                }
                else {
                    storage.pop();
                }
            }
        }
        return storage.empty();
    }
};
