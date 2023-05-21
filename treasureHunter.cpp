#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = INT_MAX;

struct Cell {
    int row;
    int col;
    int steps;
    int health;

    Cell(int r, int c, int s, int h) : row(r), col(c), steps(s), health(h) {}
};

pair<int, int> dungeonTreasureHunt(vector<vector<char> > & dungeon) {
    int rows = dungeon.size(); // # of rows in the dungeon
    int cols = dungeon[0].size(); // # of columns in the dungeon

    // keep track of visited cells
    vector<vector<bool> > visited(rows, vector<bool>(cols, false));

    // define possible movements: up, down, left, right
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    queue<Cell> q;
    q.push(Cell(0, 0, 0, 5));

    int minSteps = INF;
    int maxHealth = 0;

    while (!q.empty()) {
        // keep track of the current cell
        Cell curr = q.front();
        q.pop();

        int currRow = curr.row;
        int currCol = curr.col;
        int currSteps = curr.steps;
        int currHealth = curr.health;

        // check if current cell is the treasure
        if (dungeon[currRow][currCol] == 'T') {
            // update the minimum steps and maximum health if it's a better path
            if (currSteps < minSteps) {
                minSteps = currSteps;
                if (currHealth > maxHealth)) {
                    maxHealth = currHealth;
                }
            }
            continue;
        }

        // check the 4 neighbors
        for (int i = 0; i < 4; i++) {
            int newRow = currRow + dx[i];
            int newCol = currCol + dy[i];

            // check if the new position is within the dungeon bounds
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                // check if the new position is not a wall and hasn't been visited
                if (dungeon[newRow][newCol] != 'X' && !visited[newRow][newCol]) {
                    visited[newRow][newCol] = true;

                    // calculate new health after stepping on the new position
                    int newHealth = currHealth;
                    if (isdigit(dungeon[newRow][newCol])) {
                        newHealth -= dungeon[newRow][newCol] - '0';
                        dungeon[newRow][newCol] = ' '; // become an empty cell
                        if (newHealth <= 0) {
                            continue;
                        }
                    } else if (dungeon[newRow][newCol] == 'H') {
                        newHealth += 10;
                    }
                    q.push(Cell(newRow, newCol, currSteps + 1, newHealth));
                }
            }
        }
    }

    if (minSteps == INF) {
        return make_pair(-1, 5);
    } else {
        return make_pair(minSteps, maxHealth);
    }
}

int main() {
    vector<vector<char>> dungeon = {
            {'0', 'X', ' ', 'X', ' ', 'X', 'T'},
            {' ', 'X', ' ', 'X', ' ', 'X', ' '},
            {' ', ' ', 'H', ' ', ' ', ' ', ' '},
            {'X', 'X', 'X', 'X', 'X', 'X', '0'},
            {' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };

    pair<int, int> result = dungeonTreasureHunt(dungeon);
    return 0;
}