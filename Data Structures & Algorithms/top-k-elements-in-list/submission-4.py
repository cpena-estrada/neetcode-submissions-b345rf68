""" 
.items() returns a view object that behaves 
like a list of key–value pairs.

num_freq = {1: 3, 2: 2, 3: 1}
print(num_freq.items())
it prints : dict_items([(1, 3), (2, 2), (3, 1)])

ech element is a tuple
"""
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        num_freq = {}
        res = []

        for num in nums:
            if num in num_freq:
                num_freq[num] += 1
            else:
                num_freq[num] = 1

        sorted_list = sorted(num_freq.items(), key=lambda x : x[1], reverse=True)

        # for i in range(k):
        #     res.append(sorted_list.ke)
        sorted_list = sorted_list[:k]

        for key in sorted_list:
            res.append(key[0])

        return res



        
"""
keep track of number frequencies 
{1 : 1, 2 : 2, 3: 3}

turn into list and sort by value (frequency) in decreasing order

iterate over sorted list k times
    push back key into result array 


"""