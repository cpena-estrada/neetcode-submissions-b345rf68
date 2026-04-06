class UnionFind():
    def __init__(self, n: int):
        self.parent = [i for i in range(n)]
        self.num_components = n
    
    def find(self, node: int) -> int:
        if self.parent[node] == node:
            return self.parent[node]
        self.parent[node] = self.find(self.parent[node])
        return self.parent[node]

    def union(self, a: int, b: int) -> None:
        a_parent = self.find(a)
        b_parent = self.find(b)

        if a_parent != b_parent:
            self.parent[b_parent] = a_parent
            self.num_components -= 1


class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        UF = UnionFind(n)

        # unite the nodes 
        for a, b in edges:
            UF.union(a, b)

        return UF.num_components
