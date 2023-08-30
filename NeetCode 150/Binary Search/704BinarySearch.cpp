class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = -1, left = 0, right = nums.size() - 1;
        while (left <= right) {
            int res = (left + right) / 2;
            if (nums[res] == target) {
                return res;
            } else if (nums[res] > target) {
                right = res - 1;
            } else {
                left = res + 1;
            }
        }
        return -1;
    }
};
