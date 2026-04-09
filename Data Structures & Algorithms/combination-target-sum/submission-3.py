class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        path, res = [], []

        def dfs(idx, total): # no need to pass candidates as its in outer scope
            if total == target:
                res.append(path.copy())
                return
            if idx >= len(candidates) or total > target:
                return

            path.append(candidates[idx])
            total += candidates[idx]

            # keep epxloring this 
            dfs(idx, total)

            path.pop()
            total -= candidates[idx]

            dfs(idx + 1, total)
        
        dfs(0, 0)
        return res