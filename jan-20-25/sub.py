from typing import List

class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        
        m, n = len(mat), len(mat[0])

        mp = [0] *(m * n + 1)

        for i in range(m):
            for j in range(n):

                mp[mat[i][j]] = i * n + j

        rows = [0] * m
        cols = [0] * n

        for i, val in enumerate(arr):
            hs = mp[val]
            rows[hs//n] += 1
            if rows[hs//n] == n:
                return i
            cols[hs % n] += 1
            if cols[hs % n] == m:
                return i

        return m * n - 1
