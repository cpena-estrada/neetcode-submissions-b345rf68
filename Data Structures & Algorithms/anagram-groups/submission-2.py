from typing import List # for type hints
from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hash_map = defaultdict(list) # [str, list[str]]
        # hash_map: [str, list[str]] = defaultdict(list) # [str, list[str]]

        res = []

        for word in strs:
            sorted_word = ''.join(sorted(word))        
            hash_map[sorted_word].append(word)

            # with a regualr dict?
            # if sorted_word in hash_map:
            #     hash_map[sorted_word].append(word)
            # else:
            #     hash_map[sorted_word] = [word]

        for _, words in hash_map.items():
            res.append(words)
        
        return res

"""
map of string list of strings




having a mapping of sorted word : anagrams list

for each word in strs
    an = sort the word 

    if anagram in map
        append to the list
    else
        insert anagram into map as a key and word as value

    iterate over values of mapping and append to a result list

"""