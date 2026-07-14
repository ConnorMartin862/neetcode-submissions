class Solution {
public:
    int numDecodings(string s) {
        if (s[0] =='0') {return 0;}
        int n = s.size();
        vector<int> memo(n + 1, 0);
        memo[0] = 1;
        memo[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            // Single Digit Numbers
            if (s[i - 1] != '0') {
                memo[i] += memo[i - 1];
            }
            // Multi Digit Numbers
            int two = stoi(s.substr(i - 2, 2));
            if (two >= 10 && two <= 26) {
                memo[i] += memo[i - 2];
            }
        }

        return memo[n];
    }
};
