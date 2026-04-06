class Solution {
public:

    void dfs(int row, int col, vector<vector<bool>>& visited, vector<vector<char>>& grid){
        //check if in bounds
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()){
            return;
        }

        //check if its a int 1 in row,col
        if(grid[row][col] == '0' || visited[row][col] == true){
            return;
        }
        
        //mark it as visited
        visited[row][col] = true;

        dfs(row-1, col, visited, grid);
        dfs(row+1, col, visited, grid);
        dfs(row, col-1, visited, grid);
        dfs(row, col+1, visited, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size(); 
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        int count = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == '1' && visited[i][j] == 0){
                    dfs(i, j, visited, grid);
                    count++;
                }
            }
        }        
        return count;
    }
};


/*
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

    */