/*
this is 2-D Dynamic Programming
recurrence relation is grid[m][n] = grid[m-1][n] + grid[m][n-1]
define base cases, since we can only move down or right, the topmost and leftmost rows/columns all have a value of 1.
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        // initialize a grid of 1 to handle the base cases implicitly
        vector<vector<int>> matrix(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
            }
        }
        return matrix[m-1][n-1];
    }
};
