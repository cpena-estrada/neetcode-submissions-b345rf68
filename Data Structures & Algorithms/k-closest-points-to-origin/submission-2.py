import heapq
import math 
"""
math.sqrt(x)      # square root
math.pow(a, b)    # float power
math.floor(x)
math.ceil(x)
math.pi
math.e
math.sqrt(x*x + y*y) pytagorean

* = multiplication
** = exponentiation
"""

class Solution:
    #                   [x1, y1]      [x2, y2]
    def euclidean(self, a: list[int], b: list[int]):
        n1 = (a[0] - b[0]) * (a[0] - b[0])
        n2 = (a[1] - b[1]) * (a[1] - b[1])
        return math.sqrt(n1 + n2)

    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        h = []
        res = []

        # populate heap
        for point in points:
            dist = self.euclidean(point, [0,0])
            heapq.heappush(h, (-dist, point)) # max heap behavior

        while len(h) > k:
            heapq.heappop(h)
        
        # extract K closest point
        while h:
            res.append(h[0][1])
            heapq.heappop(h)
        
        return res


"""

you want the k SHORTEST distances -> max heap (neagte dist)

prob need a somewthing so that it knows how to deal w tiebreakers

either an incremental tie breaker variable

or a wrapper (no need to negate because we can establish the max heap behavior)

class Wrapper:
    def __init__(self, dist, point):
        self.dist = dist
        self.point = point

    def __lt__(self, other):
        if self.dist != other.dist:
            return self.dist > other.dist # max_heap behavior
        elif self.point[0] != other.point[0]:
            return self.point[0] < other.point[0]
        return self.point[1 ] < other.point[1] #just arbitraty. 

    either way you need a proper tuie breaker var
"""