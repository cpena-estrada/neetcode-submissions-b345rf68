from collections import defaultdict
import heapq

class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        adj_list = defaultdict(list) # airpoirt : min heap of destination airpoirts
                                     # an entry represents an edge
        res = []

        for u, v in tickets:
            h = adj_list[u]
            heapq.heappush(h, v) # push onto the heap for this src
                                 # min heap means we go lexographically smaller 

        def dfs(airport):
            # res.append(airport) not here. read why below
            h = adj_list[airport] #when its a defualtdict, if the key dont exists, it auto creates a defualt entry
            while h:
                nei = heapq.heappop(h) # get lexicogrpahically smaller nei, pop it so its not explored again
                dfs(nei)
            res.append(airport)

        
        dfs('JFK')
        
        return res[::-1]




"""
min heap allows us to travel to the lexographically smaller dst airport 
(so we want our answer to be i nincreasing order)

but dfs goes allllll the way until the end first, meaning airports are pushed in
reverse lexographically (increasing) order

rverse the result
"""
