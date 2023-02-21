/*
Use two pointers to keep track of the subarray.
Runtime: O(n)
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0; // left pointer
        int result = INT_MAX; 
        int sum = 0;
        for (int j = 0; j < nums.size(); j++) { // right pointer
            sum += nums[j]; // add the rightmost element
            while (sum >= target) {
                int len = j - i + 1; 
                result = min(result, len);
                sum -= nums[i]; // remove the leftmost element
                i++; // increment the left pointer
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};