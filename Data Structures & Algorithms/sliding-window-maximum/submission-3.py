"""
var = float('inf')      # +∞
var = float('-inf')     # -∞

index 0 of the heap list is your "top"
"""
import heapq # min heap by default


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        res, h = [], [] # (negated value, index of val)
        left = 0
        for right, val in enumerate(nums):
            #push right onto heap (negate so its a 'max' heap)
            heapq.heappush(h, (-val, right))

            if right - left + 1 == k:
                while h[0][1] < left or h[0][1] > right:  # top num is not within left and right:
                    heapq.heappop(h) # pass h

                res.append(-h[0][0])

                left += 1
        
        return res
            



"""
       7
0123456

for (int i = 0; i <= nums.size() - 1; i ++) 
    for (int j = i; j < i + k; j++)


brute force:

    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        res = []

        for i in range(len(nums) - k + 1): # +1? so i can be <= len(nums) - k 
            window_max = float('-inf')
            for j in range(i, i + k):
                window_max = max(window_max, nums[j])
            res.append(window_max)
        
        return res
"""