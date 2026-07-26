class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, -1);
        memo[0] = 0;
        for (int i = 1; i <= amount; i++) {
            int value = INT_MAX;
            for (int coin : coins) {
                if (i - coin >= 0 && memo[i - coin] != -1) {
                    value = min(value, memo[i - coin]);
                }
            }
            if (value == INT_MAX) {continue;}
            else {memo[i] = value + 1;}
        }
        return memo[amount];
    }
};
