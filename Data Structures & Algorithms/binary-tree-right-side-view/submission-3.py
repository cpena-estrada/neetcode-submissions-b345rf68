from collections import deque

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        q = deque()
        res = []

        if root:
            q.append(root)
        
        while q:
            res.append(q[-1].val) # q[-1] is the back

            for _ in range(len(q)):
                node = q[0] # q[0] is the front
                q.popleft()
                if node:
                    if node.left:
                        q.append(node.left)
                    if node.right:
                        q.append(node.right)
        return res
"""

push root (if non null?)

while q


from collections import deque

q = deque()

q.append(10)        # enqueue (push back)
q.append(20)

x = q.popleft()     # dequeue (pop front)  -> 10
front = q[0]        # peek front
back = q[-1]        # peek back

if not q:           # empty check
"""