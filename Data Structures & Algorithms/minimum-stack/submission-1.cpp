class MinStack {
public:
    vector<int> data;
    stack<int> minStack;

    MinStack() {
    }
    
    void push(int val) {
        data.push_back(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        if (minStack.top() == data.back()) {
            minStack.pop();
        }
        data.pop_back();
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return minStack.top();
    }
};
