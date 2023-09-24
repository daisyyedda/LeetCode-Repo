class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto &i : stones) pq.push(i);
        while (pq.size() >= 2) {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if (x == y) continue;
            y = y - x;
            pq.push(y);
        }
        if (pq.size() == 0) return 0;
        return pq.top();
    }
};
