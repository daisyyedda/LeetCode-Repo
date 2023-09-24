// the recurrence relation is dp[n] = max(dp[n-1], val[n] + dp[n-2])
// we use two loops that ignore the two endpoints respectively to prevent cycles
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int prev = 0, curr = 0, next = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            next = max(prev + nums[i], curr);
            prev = curr;
            curr = next;
        }
        int prev2 = 0, curr2 = 0, next2 = 0;
        for (int i = 1; i < nums.size(); i++) {
            next2 = max(prev2 + nums[i], curr2);
            prev2 = curr2;
            curr2 = next2;
        }
        return max(curr, curr2);
    }
};