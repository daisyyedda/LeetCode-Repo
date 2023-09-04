class Solution {
public:
    // using binary search, runtime O(log(n)), space O(1)
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1, mid;
        if (nums.size() == 1) {
            return (nums[0] == target) - 1;
        }
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < nums[hi]) {
                if (nums[mid] > target || nums[hi] < target) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else {
                if ((nums[mid] > target && nums[hi] < target) ||
                    (nums[mid] <= target && nums[mid + 1] <= nums[mid])) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
        }
        return -1;
    }
};
