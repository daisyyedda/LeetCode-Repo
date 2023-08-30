class Solution {
public:
    // O(n) time, O(n) space
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        stk.push(-1);
        int res = 0;
        for (size_t i = 0; i < heights.size(); i++) {
            // maintaining a monotonic stack
            while (stk.top() != -1 && heights[stk.top()] >= heights[i]) {
                int curr_height = heights[stk.top()];
                stk.pop();
                int curr_width = i - stk.top() - 1;
                res = max(res, curr_height * curr_width);
            }
            stk.push(i);
        }
        while (stk.top() != -1) {
            int curr_height = heights[stk.top()];
            stk.pop();
            int curr_width = heights.size() - stk.top() - 1;
            res = max(res, curr_height * curr_width);
        }
        return res;
    }
};
