class Solution {
public:

    int dfs(int row, int col, vector<vector<int>>& grid){

        //check if in bounds
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()){
            return 0;
        }

        //check if its a int 1 in row,col
        if(grid[row][col] == 0){
            return 0;
        }
        
        //mark it as visited
        grid[row][col] = 0;

        int total = 1;
        total += dfs(row-1, col, grid);
        total += dfs(row+1, col, grid);
        total += dfs(row, col-1, grid);
        total += dfs(row, col+1, grid);

        return total;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int max = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 1){
                    int temp = dfs(i,j,grid);
                    if(temp > max){
                        max = temp;
                    }
                }
            }
        }
        return max;
    }
};
