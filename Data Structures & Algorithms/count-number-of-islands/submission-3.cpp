class Solution {
private:
    vector<pair<int,int>> directions = { {1,0}, {-1,0}, {0,1}, {0,-1} };
public:

    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
        queue<pair<int,int>> q;

        q.push({row, col}); 
        visited[row][col] = true; // mark as visited when enqueueing

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < directions.size(); i++) {
                int nr = r + directions[i].first;
                int nc = c + directions[i].second;

                // if new coordinates within bounds
                if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size()) {
                    // if its land as not yet visited
                    if (grid[nr][nc] == '1' && !visited[nr][nc]) {
                        q.push({nr,nc});
                        visited[nr][nc] = true;
                    }  
                }
            }
        }
    }


    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    bfs(grid, visited, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};


/*

iterate over grid
    if you encounter a "1" (land), explore it until you cant anymore
        being able to epxlore means there is a 1 and in bounds
    
    mark land as visited as you explore
        - mark visited by changing input grid of keep a visited grid

DFS:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
        // out of bounds check
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) { return; }

        // is it water or been visited?
        if (grid[row][col] == '0' || visited[row][col]) { return; }
        //if (grid[row][col] == '0') { return; } in place


        // mark land as visited
        visited[row][col] = true;
        //grid[row][col] = '0'; mark as visited in place^

        // explore adjecent lands
        dfs(grid, visited, row + 1, col); 
        dfs(grid, visited, row - 1, col);
        dfs(grid, visited, row, col + 1);
        dfs(grid, visited, row, col - 1);
    }


    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, visited, i, j);
                    count++;
                }
            }
        }
        return count;
    }
*/
