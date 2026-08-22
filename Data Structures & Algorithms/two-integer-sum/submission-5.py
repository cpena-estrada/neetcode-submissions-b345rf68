class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        for i in range(len(nums) - 1):
            for j in range(i+1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]
        return []

# class Solution:
#     def twoSum(self, nums: List[int], target: int) -> List[int]:
#         the_map = {}
        
#         for i, num in enumerate(nums):
#             difference = target - num
#             if difference in the_map:
#                 return [the_map[difference], i]
#             else:
#                 the_map[num] = i
#         return [] 

"""
mapping <num : index >

iterate over nums
    if the difference is in the map, return i and map[difference]

    else insert num : index into map to keep track of seen 

brute force:

        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):  #start one ahead
                if (nums[i] + nums[j] == target):
                    return [i,j]
        return []

my own weird way (brute force):

        # for i, _ in enumerate(nums):
        #     j = i + 1
        #     for j,_ in enumerate(nums):
        #         if (nums[i] + nums[j] == target):
        #             return [i,j]

"""