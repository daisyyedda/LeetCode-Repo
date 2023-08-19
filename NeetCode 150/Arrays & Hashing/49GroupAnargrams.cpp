class Solution {
public:
    // if they are anagrams, they will be the same after sorting
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (auto &i : strs) {
            string tmp = i;
            sort(i.begin(), i.end());
            hash[i].emplace_back(tmp);
        }
        vector<vector<string>> res;
        for (auto &i : hash) {
            res.emplace_back(i.second);
        }
        return res;
    }
};
