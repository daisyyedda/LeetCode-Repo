// use two pointers to aid search
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; i++) {
            if (nums[i] > 0) {
                break;      // smallest int is already > 0
            }
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;   // skip duplicate a
            }
            int b = i + 1;
            int c = nums.size() - 1;
            while (b < c) {
                int sum = nums[i] + nums[b] + nums[c];
                if (sum == 0) {
                    vector<int> triplet = {nums[i], nums[b], nums[c]};
                    result.emplace_back(triplet);
                    while (b < c && nums[b] == nums[b+1]) b++; // skip duplicate b
                    while (b < c && nums[c] == nums[c-1]) c--; // skip duplicate c
                    b++;
                    c--;
                } else if (sum < 0) {
                    b++;
                } else {
                    c--;
                }
            }
        }
        return result;
    }
};