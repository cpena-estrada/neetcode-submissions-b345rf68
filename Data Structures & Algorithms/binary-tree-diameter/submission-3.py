# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def dfs(self, root: Optional[TreeNode]):
        if not root:
            return 0

        left = self.dfs(root.left)
        right = self.dfs(root.right)

        self.best = max(self.best, left + right)
        
        return 1 + max(left, right)

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.best = 0 # "global"
        self.dfs(root)
        return self.best


"""
dfs

at eeach node caulacte left + right height

"""