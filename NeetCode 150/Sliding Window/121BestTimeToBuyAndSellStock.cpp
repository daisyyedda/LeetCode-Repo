class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, lo = 0, hi = 0;
        while (hi < prices.size()) {
            if (prices[hi] > prices[lo]) {
                profit = max(profit, prices[hi] - prices[lo]);
            } else {
                // prices[hi] <= prices[lo], so hi is a new lo
                lo = hi;
            }
            hi++;
        }
        return profit;
    }
};
