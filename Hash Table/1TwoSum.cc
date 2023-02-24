class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
      // use unordered_map to store the complement and its index
        unordered_map<int, int> twoNum;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            int one = nums[i];          
            int two = target - one;         // complement
            if (twoNum.count(two)) {        // if complement exists already
                return {twoNum[two], i};    // we found the pair
            }
            twoNum[one] = i; 
        }
        return {};
    }
};