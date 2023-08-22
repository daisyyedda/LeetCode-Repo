class Solution {
public:
    // DP solution, O(n) time, O(n) space
    int trap(vector<int>& height) {
        vector<int> minMax;
        int n = height.size();
        int total = 0, currMax = 0;
        for (int i = 0; i < n; i++) {
            if (height[i] > currMax) currMax = height[i];
            minMax.emplace_back(currMax);
        }
        currMax = 0;
        for (int i = n-1; i >= 0; i--) {
            if (height[i] > currMax) currMax = height[i];
            if (currMax < minMax[i]) minMax[i] = currMax;
        }
        // minMax stores the min of max height from left and right
        // for each index i, the water it can trap is minMax[i] - height[i]
        for (int i = 0; i < n; i++) {
            total += minMax[i] - height[i];
        }
        return total;
    }
};
