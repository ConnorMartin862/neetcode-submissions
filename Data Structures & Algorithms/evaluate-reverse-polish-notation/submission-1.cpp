class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> storage;
        for (string c : tokens) {
            if (isdigit(c[0]) || c.size() > 1) {
                int val = stoi(c);
                storage.push(val);
            } else {
                if (c == "+") {
                    int a = storage.top();
                    storage.pop();
                    int b = storage.top();
                    storage.pop();
                    storage.push(b + a);
                } else if (c == "-") {
                    int a = storage.top();
                    storage.pop();
                    int b = storage.top();
                    storage.pop();
                    storage.push(b - a);
                } else if (c == "*") {
                    int a = storage.top();
                    storage.pop();
                    int b = storage.top();
                    storage.pop();
                    storage.push(b * a);
                }
                else {
                    int a = storage.top();
                    storage.pop();
                    int b = storage.top();
                    storage.pop();
                    storage.push(b / a);
                }
            }
        }
        return storage.top();
    }
};
