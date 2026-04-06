from collections import Counter

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s2) < len(s1): return False

        s1_freqs, s2_freqs = {}, {}

        # populate s1
        for c in s1:
            s1_freqs[c] = 1 + s1_freqs.get(c, 0)

        # get the freq of the first len(s1) chars in s2
        for i in range(len(s1)):
            s2_freqs[s2[i]] = 1 + s2_freqs.get(s2[i], 0)

        if s1_freqs == s2_freqs: return True

        left, right = 0, len(s1) - 1
        while right < len(s2):
            s2_freqs[s2[left]] -= 1

            if s2_freqs[s2[left]] <= 0:
                #del s2_freq[s2[left]] only if key exists
                s2_freqs.pop(s2[left], None) # safe way

            left += 1
            right += 1

            if right >= len(s2): continue
            s2_freqs[s2[right]] = 1 + s2_freqs.get(s2[right], 0)

            if s1_freqs == s2_freqs: return True

        return False


"""   
        l r
        0123
        lecabee
        
        decrement left or remove it
        incrmeent right
        reflect right on map
        check if maps are equal
"""



