class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {
    }
    
    void addNum(int num) {
        if (minHeap.empty()) {
            minHeap.emplace(num);
            return;
        }

        maxHeap.emplace(num);
        if (maxHeap.top() > minHeap.top()) {
            minHeap.emplace(maxHeap.top());
            maxHeap.pop();
        }

        if (abs(static_cast<int>(maxHeap.size()) - static_cast<int>(minHeap.size())) > 1) {
            if (maxHeap.size() > minHeap.size()) {
                minHeap.emplace(maxHeap.top());
                maxHeap.pop();
            }
            else {
                maxHeap.emplace(minHeap.top());
                minHeap.pop();
            }
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (static_cast<double>(maxHeap.top()) + static_cast<double>(minHeap.top())) / 2.0;
        } else if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else {
            return minHeap.top();
        }
    }
};
