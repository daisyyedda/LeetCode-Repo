class Solution {
public:
    // O(n^2) run time
    void threeSum(vector<int>& nums, int i, vector<vector<int>>& res) {
        int lo = i + 1;
        int hi = nums.size() - 1;
        while (lo < hi) {
            if (nums[lo] + nums[hi] + nums[i] == 0) {
                res.push_back({nums[i], nums[lo], nums[hi]});
                hi--;
                lo++;
                // skip duplicates
                while (lo < hi && nums[lo] == nums[lo-1]) lo++;
            } else if (nums[lo] + nums[hi] + nums[i] > 0) {
                hi--;
            } else {
                lo++;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            threeSum(nums, i, res);
        }
        return res;
    }
};
