// the recurrence relation is dp[n] = dp[n-1] + dp[n-2]
// so we define base cases and use a loop to iterate
class Solution {
public:
    int climbStairs(int n) {
        // base cases
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        int res = 0, first = 1, second = 2;
        for (int i = 2; i < n; i++) {
            res = first + second;
            first = second;
            second = res;
        }
        return res;
    }
};
