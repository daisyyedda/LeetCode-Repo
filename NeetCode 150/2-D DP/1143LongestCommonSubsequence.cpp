/*
use 2-D DP
if text1[m] == text2[n], grid[m][n] = 1 + grid[m-1][n-1]
otherwise, grid[m][n] = max(grid[m-1][n], grid[m][n-1])
base case is when one string has a length of 0, common subsequence is 0
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        // initialize a grid of 0 to handle base cases implicitly
        vector<vector<int>> grid(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i-1] == text2[j-1]) {
                    grid[i][j] = 1 + grid[i-1][j-1];
                } else {
                    grid[i][j] = max(grid[i-1][j], grid[i][j-1]);
                }
            }
        }
        return grid[m][n];
    }
};
