class Solution {
public:
    // runtime: O(2^n) since recursion tree has 2^n nodes
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(0, 0, n, "", res);
        return res;
    }
private:
    void generate(int open, int close, int n, string s, vector<string> &res) {
        if (open == n && close == n) {
            res.emplace_back(s);
        }
        if (open < n) {
            generate(open+1, close, n, s+"(", res);
        }
        if (close < open) {
            generate(open, close+1, n, s+")", res);
        }
    }
};
