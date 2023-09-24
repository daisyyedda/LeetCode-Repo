// trigger DFS everytime finding a "1"
// in DFS mark all visited "1" neighbour to "0"
// return the total number of triggers
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, int r, int c) {
        if (i < 0 || i >= r || j < 0 || j >= c || grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid, i-1, j, r, c);
        dfs(grid, i+1, j, r, c);
        dfs(grid, i, j-1, r, c);
        dfs(grid, i, j+1, r, c);
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0, r = grid.size(), c = grid[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, r, c);
                    res++;
                }
            }
        }
        return res;
    }
};
