class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = defaultdict(set)  # key: int, value: set[str]
        cols = defaultdict(set)  # key: int, value: set[str]

        # rows and cols
        for i in range(9):
            for j in range(9):
                val = board[i][j]
                if val != '.':
                    # check if val already in row i or col j
                    if val in rows[i] or val in cols[j]:
                        return False
                    rows[i].add(val)
                    cols[j].add(val)

        # 3x3 boxes
        for i in range(0, 9, 3):
            for j in range(0, 9, 3):
                window = set()
                for x in range(3):
                    for y in range(3):
                        cell = board[i + x][j + y]
                        if cell != '.':
                            if cell in window:
                                return False
                            window.add(cell)

        return True