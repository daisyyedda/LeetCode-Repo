// for greedy algorithm, the key is to traverse all possible solutions to find the optimal
// time O(n), space O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = nums[0], result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            curr = max(nums[i] + curr, nums[i]);
            result = max(curr, result);
        }
        return result;
    }
};
