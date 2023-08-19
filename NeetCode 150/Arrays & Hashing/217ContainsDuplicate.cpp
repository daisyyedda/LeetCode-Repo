class Solution {
public:
    // runs in O(n)
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> res;
        for (auto &i : nums) res[i]++;
        for (auto &i : res) {
            if (i.second >= 2) return true;
        }
        return false;
    }
};
