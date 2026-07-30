class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for (int stone : stones) {
            maxHeap.push(stone);
        }

        while (maxHeap.size() > 1) {
            int stoneA = maxHeap.top();
            maxHeap.pop();
            int stoneB = maxHeap.top();
            maxHeap.pop();
            stoneA = abs(stoneA - stoneB);
            maxHeap.push(stoneA);
        }

        return maxHeap.top();
    }
};
