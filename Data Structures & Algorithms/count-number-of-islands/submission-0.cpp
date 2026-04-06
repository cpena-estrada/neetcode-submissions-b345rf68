class Solution {
public:

    void dfs(vector<vector<char>>& grid, int i, int j, set<pair<int,int>> &visited) {
        int rows = grid.size();
        int cols = grid[0].size();

        //if row col passed are out of bounds
        if(i < 0 || i > rows-1 || j < 0 || j > cols-1){
            return;
        }
        //if its water or already visited 
        //(check again because recursive calls can land on water or prev visited ones)
        if(grid[i][j] == '0' || visited.count({i,j}) == 1){
            return;
        }

        visited.insert({i,j});

        dfs(grid, i-1, j, visited);
        dfs(grid, i+1, j, visited);
        dfs(grid, i, j-1, visited);
        dfs(grid, i, j+1, visited);

    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int num_of_islands = 0;
        set<pair<int,int>> visited; 

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                //if its land and it hasnt been visited 
                // 0 false 1 true
                //                      visited.count({i, j}) == 0 )    
                if(grid[i][j]== '1' && visited.find({i,j}) == visited.end()) {
                    dfs(grid, i, j, visited);
                    num_of_islands++;
                }
            }
        }
        return num_of_islands;
    }
};
