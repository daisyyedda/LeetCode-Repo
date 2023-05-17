class Solution {
public:
    vector<int> prefixSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> pre(n);
        pre[0] = arr[0];
        for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + arr[i];
        return pre;
    }

    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> pre = prefixSum(nums);
        vector<int> subarr(k);
        subarr[0] = 1;
        int ans = 0;
        for (auto& x : pre) {
            if (x < 0) x = (x % k + k) % k;
            subarr[x % k]++;
        }
        for (auto& x : subarr) ans += x * (x - 1) / 2;
        return ans;
    }
};