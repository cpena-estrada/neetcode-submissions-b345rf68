class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        path, res = [], []
        used = [0] * len(nums)

        def dfs(path: list):
            if len(path) == len(nums):
                res.append(path.copy())
                return

            for i in range(len(nums)):
                if used[i]:
                    continue
                    
                path.append(nums[i])
                used[i] = 1 # mark as used
                dfs(path)
                
                used[i] = 0 # mark as unused
                path.pop()

        dfs(path) # an empty list
        return res

            