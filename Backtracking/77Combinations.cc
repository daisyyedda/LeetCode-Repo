class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int n, int k, int idx) {
        if (path.size() == k) {
            res.emplace_back(path);
            return;
        }
        for (int i = idx; i <= n; i++) {
            path.emplace_back(i); 
            backtracking(n, k, i + 1); 
            path.pop_back(); 
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return res;
    }
};