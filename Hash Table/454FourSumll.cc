class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> tuple;
        int count = 0;
        for (int a : nums1) {
            for (int b : nums2) {
                tuple[a+b]++;
            }
        }
        for (int c : nums3) {
            for (int d : nums4) {
              // when a + b + c + d = 0, a + b = 0 - (c + d)
                if (tuple.find(0 - (c + d)) != tuple.end()) {
                    count += tuple[0 - (c + d)];
                }
            }
        }
        return count;
    }
};