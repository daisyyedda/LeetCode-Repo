class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // unordered_set automatically excludes duplicates
        unordered_set<int> hash(nums.begin(), nums.end());
        int finalMax = 0;
        for (auto &i : nums) {
            int currMax = 1;
            // only check if its the smallest
            if (hash.find(i-1) == hash.end()) {
                // find in unordered_set costs O(1)
                while (hash.find(i+1) != hash.end()) {
                    currMax++;
                    i++;
                }
            }
            finalMax = max(currMax, finalMax);
        }
        return finalMax;
    }
};
