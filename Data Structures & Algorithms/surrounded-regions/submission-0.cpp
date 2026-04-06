class Solution {
private:
    vector<pair<int, int>> directions = { {1,0}, {-1,0}, {0,1}, {0,-1} };
public:

    bool is_valid(int r, int c, vector<vector<char>>& board, vector<vector<bool>>& visited ) {
        return r >= 0 && r < board.size() &&
               c >= 0 && c < board[0].size() &&
               !visited[r][c] && board[r][c] == 'O';
    }

    bool is_border(int r, int c, vector<vector<char>>& board) {
        return r == 0 || c == 0 || r == board.size() - 1 || c == board[0].size() - 1;
    }

    void bfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& visited) {
        int ROWS = board.size(), COLS = board[0].size();
        bool reached_border = false;
        vector<pair<int, int>> coords;
        queue<pair<int, int>> q;

        q.push({i, j});
        visited[i][j] = true;
        coords.push_back({i, j}); // handle coordinate you started from

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front(); q.pop();

                for (const auto& direct : directions) {
                    int nr = r + direct.first;
                    int nc = c + direct.second;

                    if (is_valid(nr, nc, board, visited)) {
                        // push onot q to explore
                        q.push({nr, nc});
                        visited[nr][nc] = true;

                        // if its valid but its a border, flag it
                        if (is_border(nr, nc, board)) { reached_border = true; }

                        // track coordinates to modify
                        coords.push_back({nr, nc});
                    }
                }
            }
        }

        // bfs is over. only modify if you did not reach a border
        if (!reached_border) {
            for (const auto& [r, c] : coords) {
                board[r][c] = 'X';
            }
        }
    }

    
    void solve(vector<vector<char>>& board) {
        int ROWS = board.size(), COLS = board[0].size();
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        
        // for each 'O'
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (!visited[i][j] && board[i][j] == 'O' && !is_border(i, j, board)) {
                    bfs(i, j, board, visited);
                }
            }
        }
    }
};

/*

bfs each 'O'
    if you ever reach a border during the bfs, it is not surrounded (dont modify)

in the dfs
    after you are done exploring, if flag is ok, modify the grid in place
    elese just exit func

*/