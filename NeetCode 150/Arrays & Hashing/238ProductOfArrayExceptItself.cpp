class Solution {
public:
    // O(n) time, O(1) space
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        int idx = n - 1;
        left[0] = 1;
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] * nums[i - 1];
        }
        int product = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            left[i] *= product;
            product *= nums[i];
        }
        return left;
    }
};