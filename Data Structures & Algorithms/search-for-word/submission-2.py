class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        ROWS, COLS = len(board), len(board[0])
        visited = set()

        def dfs(r, c, idx):
            if idx == len(word):
                return True
            if (r < 0 or r >= ROWS or
                c < 0 or c >= COLS or
                board[r][c] != word[idx] or
                (r, c) in visited):
                return False

            visited.add((r, c))
            res = (dfs(r+1, c, idx+1) or
                   dfs(r-1, c, idx+1) or
                   dfs(r, c+1, idx+1) or
                   dfs(r, c-1, idx+1))
            visited.discard((r, c))
            return res

        for i in range(ROWS):
            for j in range(COLS):
                if dfs(i, j, 0):
                    return True
        return False
"""
iterate over board
    if board[i][j] == word[0]:
        if dfs(i, j, curr_idx_in_word):
            return true

dfs(i, j, curr_idx_in_word):
    check OOB, an if board[i][j] != word[curr_idx_in_word], and not visited
        cant be, return False dont explore

    # meaning board[i][j] matches word[curr_idx_in_word]

    visited.add((i, j))

    if len of accumulated word matches len of word:
        return True 

    curr_idx_in_word += 1

    explore all directions

    visitted.discard((i, j))



original solution, unessecary path to check len(accumulated word) = len(word)

class Solution:
    def in_bounds(self, i, j, board):
        return (i >= 0 and i < len(board) and
                j >= 0 and j < len(board[0]))

    def exist(self, board: List[List[str]], word: str) -> bool:
        path = []
        seen = set() # (i, j)
        idx = 0

        def dfs(i: int, j: int, idx):
            if len(path) == len(word):
                return True
            
            if not self.in_bounds(i, j, board) or (i, j) in seen or board[i][j] != word[idx]:
                return False

            path.append(board[i][j])
            seen.add((i, j))

            ok = (dfs(i + 1, j, idx + 1) or
                 dfs(i - 1, j, idx + 1) or
                 dfs(i, j + 1, idx + 1) or
                 dfs(i, j - 1, idx + 1))

            path.pop()
            seen.discard((i, j))

            return ok
            
        for i in range(len(board)):
            for j in range (len(board[0])):
                if board[i][j] == word[0]:
                    if dfs(i, j, 0):
                        return True
        
        return False
"""