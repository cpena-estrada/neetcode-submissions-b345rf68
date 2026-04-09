class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        path, res = [], []

        def dfs(idx: int, total: int) -> None:
            if total == target:
                res.append(path.copy())
                return
            if idx >= len(candidates) or total > target:
                return

            # pick
            path.append(candidates[idx])
            dfs(idx + 1, total + candidates[idx]) # explore

            # unpick
            path.pop()
            
            # skip duplicate to not explore the same recursive tree
            while idx + 1 < len(candidates) and candidates[idx] == candidates[idx + 1]:
                idx += 1
            
            dfs(idx + 1, total) # explore unpicked path
        
        dfs(0, 0)
        return res

"""
1, 1, 2, 5, 6, 7, 10


           []
           /\
          1  []
         / \
       1,1  1
       /
    1,1,2
"""