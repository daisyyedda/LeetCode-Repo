/* 
The square of a number is positively correlated with its absolute value, so we use two pointers to keep track of the leftmost and rightmost integers.
Runtime: O(n)
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // empty vector of the same size, pre-filled with 0s
        vector<int> result(nums.size(), 0);
        int k = nums.size() - 1;
        for (int i = 0, j = nums.size() - 1; i <= j;) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                result[k--] = nums[i] * nums[i];
                i++;        
            } else {
                result[k--] = nums[j] * nums[j];
                j--;           
            }
        }
        return result;    
    }
};