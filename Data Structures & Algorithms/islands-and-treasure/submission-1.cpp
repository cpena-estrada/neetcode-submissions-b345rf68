class Solution {
private: 
    vector<pair<int,int>> coords = { {1, 0}, {-1, 0}, {0, 1}, {0,-1} };
    int INF = 2147483647;
public:

    bool is_valid(int ROWS, int COLS, int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        return r >= 0 && r < ROWS && c >= 0 && c < COLS &&
               !visited[r][c] && grid[r][c] != -1 && grid[r][c] != 0; // dont explore walls nor chests. explore INF and previously aciulcated sitances
    }

    void bfs(int row, int col, vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = true;

        int distance = 1;
        while (!q.empty()) {
            int size = q.size(); // get a copy of size
            for (int i = 0; i < size; i++) { // process cells/nodes at this level of bfs
                auto [r, c] = q.front(); q.pop();

                // try neighboring cells/nodes
                for (int j = 0; j < coords.size(); j++) {
                    int nr = r + coords[j].first;
                    int nc = c + coords[j].second;

                    // if position is valid
                    if (is_valid(ROWS, COLS, nr, nc, grid, visited)) {
                        grid[nr][nc] = min(distance, grid[nr][nc]);
                        q.push({nr, nc});
                        visited[nr][nc] = true;
                    }
                }
            }
            distance++;
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    bfs(i, j, grid);
                }
            }
        }    

        
    }
};

/*


instead of startong from land to chest,
start at chest and count how far away each cell is

bfs, either multisource or single source repeated

single source:
    - When you truly only have one source (or a handful) and want distances from that one source to all nodes.
    - one bfs per source

multi source:
    - This pattern generalizes to “nearest X” problems

original sol: (neetcodes ways)

    class Solution {
private: 
    vector<pair<int,int>> coords = { {1, 0}, {-1, 0}, {0, 1}, {0,-1} };
    int INF = 2147483647;
public:

    bool in_bounds(int nr, int nc, vector<vector<bool>>& visited, vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        return nr >= 0 && nr < rows && nc >= 0 && nc < cols && 
               !visited[nr][nc] && grid[nr][nc] == INF;
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int,int>> q;

        // start from gates, so find locations of them
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) { // 0 indicates gate
                    q.push({i,j});
                    visited[i][j] = true;
                }
            }
        }

        // queue has the gates
        int dist = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();

                // try new coordinates
                for (int i = 0; i < coords.size(); i++) {
                    int nr = r + coords[i].first;
                    int nc = c + coords[i].second;

                    // if in bounds, not visited, and not a wall/gate
                    if (in_bounds(nr, nc, visited, grid)) {
                        grid[nr][nc] = dist;
                        q.push({nr, nc});
                        visited[nr][nc] = true;
                    }
                }
            }
            dist++;
        }
    }
};

*/