class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        res = [0] * len(temperatures)
        stk = []

        stk.append((temperatures[0], 0)) # pair (temp, idx)


        for i in range(1, len(temperatures)):
            temp = temperatures[i]

            # curr temp is greater than a previous day
            while stk and temp > stk[-1][0]:
                days_passed = i - stk[-1][1]
                res[stk[-1][1]] = days_passed
                stk.pop()
            
            stk.append((temperatures[i], i))
            
        return res

            
"""
push first temperature onto stack
res = [0] * len(temperatures)
stk = [], []

stk.append((temperatures[0], 0)) # pair (temp, idx)

iterate temperatures from index 1
    if current temp is greater than previous temp (aka top of stack)
    calulcte number of days passed (curr_ix - stk[-1][1])
    res[previous_index] = num calculated^

return res 




        #for i, temp in enumerate()
        for i in range(i + 1, len(temperatures)):
            # i could index temperatures to extract val, but could I do it with enumerate? because I wany yo start from 1 not 0
"""