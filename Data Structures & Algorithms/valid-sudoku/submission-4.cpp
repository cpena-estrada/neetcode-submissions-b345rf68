class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;

        // row and cells
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char val = board[i][j];
                if (val != '.') {
                    if (rows[i].count(val) || cols[j].count(val)) { // check if val in set for row/col i/j
                        return false;
                    }
                    rows[i].insert(val);
                    cols[j].insert(val);
                }
            }
        }

        // 3x3 boxes
        for (int i = 0; i < 9; i += 3) {
            for (int j=0; j < 9; j += 3) {
                unordered_set<char> window;
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        char cell = board[x+i][y+j];
                        if (cell != '.') {
                            if (window.count(cell)) {
                                return false;
                            }
                            window.insert(cell);
                        }
                    }
                }
            }
        }
        return true;
    }
};

/*

ATROCIOUS SOLUTION:

check if each row is valid
check if each col is vaid
    - iterate over row/col and build a set.
    - if its not a "." and its already in the set, return false

check if 3x3 are valid w sliding window approach and a set
    

            // Chek all rows and cols
        for (int i = 0; i < 9; i++) {
            unordered_set<char> row, col;
            for (int j = 0; j < 9; j++) {

                char row_cell = board[i][j];
                if (row_cell != '.') {
                    if (row.count(row_cell)) {
                        return false;
                    } else {
                        row.insert(row_cell);
                    }
                }

                char col_cell = board[j][i];
                if (col_cell != '.') {
                    if (col.count(col_cell)) {
                        return false;
                    } else {
                        col.insert(col_cell);
                    }
                }
            }
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j=0; j < 9; j += 3) {
                unordered_set<char> window;
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        char cell = board[x+i][y+j];
                        if (cell != '.') {
                            if (window.count(cell)) {
                                return false;
                            }
                            window.insert(cell);
                        }
                    }
                }
            }
        }
        return true;
*/