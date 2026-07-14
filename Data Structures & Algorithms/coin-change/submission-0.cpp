class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, -1);
        memo[0] = 0;
        for (int i = 1; i <= amount; i++) {
            int mini = INT_MAX;
            for (int j : coins) {
                if (i < j || memo[i - j] == -1) {
                    continue;
                } else {
                    mini = min(mini, memo[i - j]);
                }
            }
            if (mini != INT_MAX) {memo[i] = mini + 1;}
        }
        return memo[amount];
    }
};
