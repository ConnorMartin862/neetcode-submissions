class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        if (maxHeap.size() > minHeap.size()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if (!maxHeap.empty() && !minHeap.empty()) {
            while (maxHeap.top() > minHeap.top()) {
                int temp = minHeap.top();
                minHeap.pop();
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(temp);
            }
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (((double)maxHeap.top() + (double)minHeap.top()) / 2);
        } else {
            return minHeap.top();
        }
    }
};
