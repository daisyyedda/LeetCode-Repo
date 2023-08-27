class Solution {
public:
    // runtime: O(n), space: O(n)
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        stack<pair<int, int>> st;
        int currDay, currTemp, prevDay;
        for (int i = 0; i < n; i++) {
            currDay = i;
            currTemp = temperatures[i];
            // currDay has a warmer temperature than prevDay, update res for prevDay
            while (!st.empty() && st.top().second < currTemp) {
                prevDay = st.top().first;
                res[prevDay] = currDay - prevDay;
                st.pop();
            }
            st.push({currDay, currTemp});
        }
        return res;
    }
};