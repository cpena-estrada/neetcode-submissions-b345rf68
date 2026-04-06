# union solution
class UnionFind:
    def __init__(self, n: int):
        self.parent = [i for i in range(n)]
        #self.parent = {i : i for i in range(n)}
        self.num_components = n

    def find(self, node: int) -> int:
        if self.parent[node] == node:
            return self.parent[node]
        self.parent[node] = self.find(self.parent[node])
        return self.parent[node]  

    def union(self, a: int, b: int) -> bool:
        a_parent = self.find(a)
        b_parent = self.find(b)

        if a_parent != b_parent:
            self.parent[b_parent] = a_parent
            self.num_components -= 1 # decrement
            return True

        return False

class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        UF = UnionFind(n)

        # check cycles
        for a, b in edges:
            if not UF.union(a, b):
                return False
        
        # check all connected
        return UF.num_components == 1

"""
parent table

0123
0123

"""