class Solution:

    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        coords = [(1,0), (-1,0), (0,1), (0,-1)]
        ROWS, COLS = len(heights), len(heights[0])
        reach_atlantic, reach_pacific = set(), set()
        ans = []

        def dfs(r, c, reach):
            if (r < 0 or r >= ROWS or
                c < 0 or c >= COLS or
                (r, c) in reach):
                return

            reach.add((r, c))

            for coord in coords:
                nr = r + coord[0]
                nc = c + coord[1]

                if (0 <= nr < ROWS and 
                    0 <= nc < COLS and
                    (nr, nc) not in reach and
                    heights[nr][nc] >= heights[r][c]):  # reversed condition
                    dfs(nr, nc, reach)


        # top and bottom
        for i in range(COLS):
            dfs(0, i, reach_pacific) # top row
            dfs(ROWS - 1, i, reach_atlantic) # bottom row

        # left and right
        for j in range(ROWS):
            dfs(j, 0, reach_pacific) # left column
            dfs(j, COLS - 1, reach_atlantic) # right column

        for i in range(ROWS):
            for j in range(COLS):
                if (i, j) in reach_atlantic and (i, j) in reach_pacific:
                    ans.append([i, j])

        return ans
"""
sets for whichever coords reach corresponding ocean

only explore if next cell <= source cell

build ans based on which coords of grid are in both sets
"""