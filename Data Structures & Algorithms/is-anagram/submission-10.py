"""
for lists:
    .sort() sorts in place. parameter can be reverse=True
    sorted() return a new arr

for strings:
    sorted() returns list of chars ['a', 'b']

    if you want a sorted string
    sorted_str = "".join(sorted(s))

"""
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s = sorted(s)
        t = sorted(t)

        if s == t:
            return True

        return False

"""
sort and check for equality

make mappings of frquency for rach and compare maps

list of size 26 (# of letter in alphabet)
iterate over each string
one increments the other decrements

iterat over arr
if not zero false
retur true  
"""