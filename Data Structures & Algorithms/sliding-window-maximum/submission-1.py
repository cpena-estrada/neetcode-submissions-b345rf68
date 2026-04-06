"""
var = float('inf')      # +∞
var = float('-inf')     # -∞

"""

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        res = []

        for i in range(len(nums) - k + 1): # +1? so i can be <= len(nums) - k 
            window_max = float('-inf')
            for j in range(i, i + k):
                window_max = max(window_max, nums[j])
            res.append(window_max)
        
        return res



"""
       7
0123456

for (int i = 0; i <= nums.size() - 1; i ++) 
    for (int j = i; j < i + k; j++)
"""