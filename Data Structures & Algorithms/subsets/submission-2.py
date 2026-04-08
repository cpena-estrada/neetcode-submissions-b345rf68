class Solution:
    def dfs(self, idx: int, nums: List[int]) -> None:
        if idx >= len(nums):
            self.res.append(self.path.copy()) # append snapshot of self.path onto self.res
            return
        
        # pick it 
        self.path.append(nums[idx])
        self.dfs(idx + 1, nums)

        # unpick it
        self.path.pop()
        self.dfs(idx + 1, nums)

    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.res = [] # these behave as globals if you acces them with self
        self.path = []
        self.dfs(0, nums)
        return self.res

"""
i would want a global result variable
i would also need a list to leep track of the numbers collected
in a recursive path

               []
            /       \
           1        []
          /   \
        1,2    1
        / \   13 1
    1,2,3  12

func insde func pythonic way

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        path = []

        def dfs(i: int) -> None:
            if i == len(nums):
                res.append(path.copy())
                return
            path.append(nums[i])
            dfs(i + 1)
            path.pop()
            dfs(i + 1)

        dfs(0)
        return res
"""     