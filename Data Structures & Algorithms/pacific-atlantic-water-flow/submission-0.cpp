class Solution {
private:                          // down,  up,     right,  left 
    vector<pair<int,int>> coords = {{1,0}, {-1,0}, {0,1}, {0, -1}};
public:

    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& seen) {
        int ROWS = heights.size(), COLS = heights[0].size();
        seen[r][c] = true; //edges of island are instanly valid for corresponding oceans.
                           // if it maks it to next recursive call, it'll be marked as seen/vaid
        
        // try neighbronig cells 
        for (const auto& coord : coords) {
            int nr = r + coord.first;
            int nc = c + coord.second;

            // dont explore OOB (no need to becuase we are doing reverse flow)
            if (nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS) { continue; } // skip this coord

            if (!seen[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, heights, seen);
            }
        }
    } 

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size(), COLS = heights[0].size();
        vector<vector<bool>> pacific_valid(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atlantic_valid(ROWS, vector<bool>(COLS, false));

        // pacific: top row and left column
        for (int i = 0; i < COLS; i++) { dfs(0, i, heights, pacific_valid); }
        for (int j = 0; j < ROWS; j++) { dfs(j, 0, heights, pacific_valid); }

        // atlantic bottom row and roght column
        for (int i = 0; i < COLS; i++) { dfs(ROWS-1, i, heights, atlantic_valid); }
        for (int j = 0; j < ROWS; j++) { dfs(j, COLS-1, heights, atlantic_valid); }

        vector<vector<int>> result;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (pacific_valid[i][j] && atlantic_valid[i][j]) {
                    result.push_back({i,j}); 
                }
            }
        }
        return result;
    }
};
/*

res is a list of lists. we append sublists of size 2, representing coordinates that satisfy

instead of water flowing from cell to ocean, think from ocean to cells.

entire top row and left column an reach pacific (beucase its its border)
entire bottom row and right column can reach atlantic

for pacific row and column,
    - check if neighboring cells are >= source cell
        - means water can flow from neighboring cell to source cell
        - therefore it reaches/connects the atlantic (keep track with a pacific seen/reachble matrix)
        - mark it as visited so you dont attempt to traverse it again (infinite ping pong)

same idea for pacific

at the end, check each cell where they are both valid 



original idea
reached pacific means:
    - landed c < 0 || r < 0

reached atlantic means:
    - landed r >= grid.size() || c >= grid[0].size()

valid value
    - if curr value <= prev value

DFS:
    two dfs calls, one from top left, one from bottom right

    call on each cell has a pair<bool,bool> indicating if you can reach pacific, atlantic

    if [r][c] within bounds
        

*/
