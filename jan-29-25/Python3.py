from typing import List

class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        
        n = len(edges) + 1
        parent = [i for i in range(n)]

        def findParent(n):
            if n != parent[n]:
                parent[n] = findParent(parent[n])
            return parent[n]

        
        for a,b in edges:
            pa, pb = findParent(a), findParent(b)
            if pa == pb:
                return [a,b]
            if pa < pb:
                parent[pb] = pa
            else:
                parent[pa] = pb

        return None