class Solution:
    def findMin(self, nums: List[int]) -> int:
        ans = float("inf")
        left, right = 0, len(nums) - 1

        while left <= right:

            mid = (left + right) // 2

            ans = min(ans, nums[mid])


            if nums[mid] > nums[right]:
                # min has to be to the right
                left = mid + 1
            else:
                right = mid - 1

        return ans 


