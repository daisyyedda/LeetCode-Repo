class Solution {
public:
    // using a one-pass hash table, runs in O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        // maps number to index
        unordered_map<int, int> hash;
        for (int i = 0; i <= nums.size(); i++) {
            int comp = target - nums[i];
            // check if the complement exists in hash, if so return
            if (hash.find(comp) != hash.end()) {
                return {hash[comp], i};
            }
            // else add the number to hash
            hash[nums[i]] = i;
        }
        return {0, 0};
    }
};
