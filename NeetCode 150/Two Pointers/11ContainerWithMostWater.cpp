class Solution {
public:
    // two pointers, O(n) time, O(1) space
    int maxArea(vector<int>& height) {
        int maxSize = 0;
        int lo = 0;
        int hi = height.size() - 1;
        while (lo < hi) {
            maxSize = max(maxSize, (hi - lo) * min(height[lo], height[hi]));
            if (height[lo] > height[hi]) {
                hi--;
            } else {
                lo++;
            }
        }
        return maxSize;
    }
};
