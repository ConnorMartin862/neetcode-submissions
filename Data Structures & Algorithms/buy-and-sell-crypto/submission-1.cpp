class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 0;
        int result = 0;
        while (right < prices.size()) {
            if (prices[right] < prices[left]) {
                left = right;
            }
            result = max(result, prices[right] - prices[left]);
            right++;
        }
        return result;
    }
};
