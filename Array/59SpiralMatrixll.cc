/*
The idea is to deal with the leftmost boundary point only.
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // initialize an n * n matrix
        vector<vector<int>> result(n, vector<int>(n));
        int offset = 1, count = 1;
        int half = n / 2, center = n / 2;
        int corX = 0, corY = 0;   
        int i, j;
        while (half--) {
            i = corX;
            j = corY;
            for (j = corY; j < n-offset; j++) {
                result[corX][j] = count++;
            }
            for (i = corX; i < n-offset; i++) {
                result[i][j] = count++;
            }
            for (; j > corY; j--) {
                result[i][j] = count++;
            }
            for (; i > corX; i--) {
                result[i][j] = count++;
            }
            corX++;
            corY++;
            offset++;
        }
        if (n % 2) {
            result[center][center] = count;
        }
        return result;
    }
};