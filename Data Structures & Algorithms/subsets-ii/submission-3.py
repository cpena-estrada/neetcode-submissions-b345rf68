class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        path, res = [], []
        nums.sort()

        def dfs(idx) -> None:
            if idx >= len(nums):
                res.append(path.copy())
                return
            
            path.append(nums[idx])
            dfs(idx + 1)

            path.pop()

            while idx + 1 < len(nums) and nums[idx] == nums[idx + 1]:
                idx += 1
            
            dfs(idx + 1)
    
        dfs(0)
        return res
        
"""
	•	Pick current element (always allowed)
	•	Unpick it
	•	Then, before exploring the “don’t pick” branch, skip over all duplicates of that value so you don’t generate the same subset multiple times starting from the same decision point.
            /                   \ 
            1                   []
        /       \               / \
     1,2         1            2     []
     / \         / \        /  \     / \
 1,2,2  1,2    1,2  1     2,2   2   2  []
"""