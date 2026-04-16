class UnionFind():
    def __init__(self, n: int):
        self.parent = [i for i in range(n)]

    def find(self, node: int):
        if self.parent[node] == node:
            return self.parent[node]
        self.parent[node] = self.find(self.parent[node])
        return self.parent[node]
    
    def union(self, a: int, b:int):
        a_parent = self.find(a)
        b_parent = self.find(b)

        if a_parent != b_parent:
            self.parent[b_parent] = a_parent
            return True
        
        return False # cycle

class Solution:
    def manhattan(self, p1: List[int], p2: List[int]):
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        edges = [] # (u, v, w)
        n = len(points) # also our number of different nodes/points
        UF = UnionFind(n)

        # build a fully connected graph as an edge list
        for i in range(n - 1):
            for j in range(i + 1, n):
                p1, p2 = points[i], points[j]
                dist = self.manhattan(p1, p2)
                edges.append((i, j, dist))

        # sort edges by weight in increasing order
        edges.sort(key=lambda x: x[2])

        num_edges = len(edges)
        edges_used = 0
        total = 0

        for u, v, w in edges:

            if UF.union(u, v): # if they dont form a cycle, unite and incrment
                total += w
                edges_used += 1

            if edges_used == n - 1: # MST property
                break

        return total