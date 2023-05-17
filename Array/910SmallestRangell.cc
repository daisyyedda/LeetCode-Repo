class Solution 
{
public:
    int smallestRangeII(vector<int>& nums, int k) { 
        sort(nums.begin(), nums.end());
        int res = nums[nums.size() - 1] - nums[0];
        int left = nums[0] + k;
        int right = nums[nums.size() - 1] - k;
        for (int i = 0; i < nums.size() - 1; i++) {
            int maxi = max(nums[i] + k, right);
            int mini = min(left, nums[i + 1] - k);
            res = min(res, maxi - mini);
        }
        return res;
    }
};