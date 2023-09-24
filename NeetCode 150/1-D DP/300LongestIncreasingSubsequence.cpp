// recurrence relation: dp[i] = max(dp[i], 1 + dp[i-1])
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), result = 1;
        vector<int> vec(n, 1);
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    vec[i] = max(vec[j] + 1, vec[i]);
                }
            }
            result = max(vec[i], result);
        }
        return result;
    }
};
