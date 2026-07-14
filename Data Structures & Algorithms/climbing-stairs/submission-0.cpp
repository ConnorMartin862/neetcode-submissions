class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {return 1;}
        int neg2 = 1;
        int neg1 = 2;
        for (int i = 3; i <= n; i++) {
            int temp = neg1;
            neg1 = neg1 + neg2;
            neg2 = temp;
        }
        return neg1;
    }
};
