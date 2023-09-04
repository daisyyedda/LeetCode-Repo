class Solution {
public:
    // runtime O(nlog(max(piles))) using binary search
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int lo = 1, hi = piles[piles.size() - 1];
        while (lo < hi) {
            int count = 0;
            int speed = (lo + hi) / 2;
            for (int i : piles) {
                count += i / speed + (i % speed != 0);
            }
            // exceed time limit, increase lo
            if (count > h) {
                lo = speed + 1;
            } else {
                hi = speed;
            }
        }
        return hi;
    }
};
