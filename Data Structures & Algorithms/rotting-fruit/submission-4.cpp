class Solution {
private:
    vector<pair<int,int>> coords = {{1,0}, {-1,0}, {0,1}, {0,-1}};
public:

    bool is_valid(vector<vector<int>>& grid, int r, int c) {
        return r >= 0 && r < grid.size() &&
               c >= 0 && c < grid[0].size() &&
               grid[r][c] == 1; // gotta be fresh fruit
    }
    
    // each level of queue is one minute
    void bfs(vector<vector<int>>& grid, queue<pair<int,int>>& q, int& minutes, int& fresh) {
        while (fresh > 0 && !q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front(); q.pop();

                for (const auto& coord : coords) {
                    int nr = r + coord.first;
                    int nc = c + coord.second;

                    if (is_valid(grid, nr, nc)) {
                        q.push({nr,nc});
                        grid[nr][nc] = 2; // mark as rotten to keep track of visited
                        fresh--;
                        // minutes++; not here because multiple oragnes rot in the same minute
                    }
                }
            }
            minutes++;
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        queue<pair<int, int>> q;
        int minutes = 0;
        int fresh = 0;
        //vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));

        // get your sources;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                // if rotten, its a source
                if (grid[i][j] == 2) {
                    q.push({i,j});
                }
                // keep track of number of fresh;
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        // no fruit to rot
        if (fresh == 0) { return 0; }
        // no sources
        if (q.size() == 0) { return -1; }

        bfs(grid, q, minutes, fresh);

        // if bfs finished and there are still fresh fruits, state is impossible
        if (fresh > 0) {
            return -1;
        } else {
            return minutes;
        }

    }
};

/*

bfs on each rotten fruit
    - multisource or single source it

    each bfs iteration is a minute
        incrmeent minute varible after each bfs round

global visited mat for multi source






*/