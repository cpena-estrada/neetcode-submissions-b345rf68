class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        ROWS, COLS = len(grid), len(grid[0])
        count = 0

        def dfs(r, c):
            if (r >= ROWS or r < 0 or
                c >= COLS or c < 0 or 
                grid[r][c] != '1'):
                # out of bounds, not '1' (land) dont explore
                return

            # mark this piece of land as visited by changing in place
            grid[r][c] = '0'

            # explore adjecent 
            dfs(r - 1, c) # up
            dfs(r + 1, c) # down
            dfs(r, c - 1) # left
            dfs(r, c + 1) # right
            # return implicit return
            
        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == '1':
                    dfs(i, j)
                    count += 1

        return count


"""
dfs:

iterate over grid

if '1' -> explore

if dfs is over thats a whle island explored



---------------------------------------------------------------
bfs:

iterate over grid

if '1' -> explore

push adjacent neighbors onto queue if they are 1's

once bfs is over thats an island explored
"""