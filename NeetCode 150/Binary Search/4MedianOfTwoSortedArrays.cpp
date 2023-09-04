class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int total = m + n, low = 0, high = m;
        double result = 0.0;
        int i, j, left1, right1, left2, right2;

        while (low <= high) {
            i = low + (high - low) / 2;
            j = (total + 1) / 2 - i;

            left1 = (i > 0) ? nums1[i - 1] : INT_MIN;
            right1 = (i < m) ? nums1[i] : INT_MAX;
            left2 = (j > 0) ? nums2[j - 1] : INT_MIN;
            right2 = (j < n) ? nums2[j] : INT_MAX;

            if (left1 <= right2 && left2 <= right1) {
                if (total % 2 == 0) {
                    result = (max(left1, left2) + min(right1, right2)) / 2.0;
                } else {
                    result = max(left1, left2);
                }
                break;
            } else if (left1 > right2) {
                high = i - 1;
            } else {
                low = i + 1;
            }
        }
        return result;
    }
};