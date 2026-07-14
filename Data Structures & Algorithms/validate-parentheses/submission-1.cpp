class Solution {
public:
    bool isValid(string s) {
        stack<int> storage;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                storage.push(c);
            } else if (c == ')') {
                if (storage.empty() || storage.top() != '(') {
                    return false;
                }
                storage.pop();
            } else if (c == ']') {
                if (storage.empty() || storage.top() != '[') {
                    return false;
                }
                storage.pop();
            } else {
                if (storage.empty() || storage.top() != '{') {
                    return false;
                }
                storage.pop();
            }
        }
        return storage.empty();
    }
};
