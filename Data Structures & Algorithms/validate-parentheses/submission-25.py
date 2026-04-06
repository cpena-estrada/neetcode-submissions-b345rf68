"""
for a stack, just use a list (last in, first out)
access top (aka last index) with list_name[-1]

dont confuse with reversing list_name[::-1]

chehcking if NOT empty list/dict:
    if var_name:

    if stack and stack[-1] < x

checking if empty:
    if not my_list:
        print("list is empty")
"""

class Solution:
    close_to_open = {
        ')' : '(',
        '}' : '{',
        ']' : '['
    }

    def isValid(self, s: str) -> bool:
        stk = []

        for c in s:
            if c == '(' or c == '{' or c == '[':
                stk.append(c)
                continue
            # else it's a closing bracket
            if stk and self.close_to_open[c] == stk[-1]:
                stk.pop()
                continue
            # else its a closing bracket but stk was empty or it didnt match
            return False

        # if its not empty brackets left (like a single opening bracket)
        if stk: return False
        
        return True



"""
stack has to be empty after done iterating over str
"""