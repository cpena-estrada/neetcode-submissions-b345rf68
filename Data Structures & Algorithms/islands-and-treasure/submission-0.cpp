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

/*



*/