// the recurrence relation is dp[n] = max(dp[n-1], val[n] + dp[n-2])
class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0, curr = 0, next = 0;
        for (int i = 0; i < nums.size(); i++) {
            next = max(prev + nums[i], curr);
            prev = curr;
            curr = next;
        }
        return curr;
    }
};
