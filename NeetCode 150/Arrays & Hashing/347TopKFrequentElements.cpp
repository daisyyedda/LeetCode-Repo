class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();
        // populate the frequency map
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }
        // store the elements in buckets based on their frequency
        vector<vector<int>> bucket(n+1);
        for (auto it = freq.begin(); it != freq.end(); it++) {
            bucket[it->second].push_back(it->first);
        }
        vector<int> res;
        for (int i = n; i >= 0; i--) {
            // if we have k elements, break
            if (res.size() >= k) {
                break;
            }
            // if the bucket is not empty, add the elements to res
            if (!bucket[i].empty()) {
                res.insert(res.end(), bucket[i].begin(), bucket[i].end());
            }
        }
        return res;
    }
};