class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        ROWS, COLS = len(grid), len(grid[0])
        max_area = 0

        def dfs(r, c):
            if (r < 0 or r >= ROWS or
                c < 0 or c >= COLS or
                grid[r][c] != 1):
                return 0
            grid[r][c] = 0
            return (1 +
                    dfs(r+1, c) +
                    dfs(r-1, c) +
                    dfs(r, c+1) +
                    dfs(r, c-1))

        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == 1:
                    max_area = max(max_area, dfs(i, j))

        return max_area

        
"""
dfs, total variable in each call. 

+ 1 initilaly

total += every adjacentr dir

return total
"""