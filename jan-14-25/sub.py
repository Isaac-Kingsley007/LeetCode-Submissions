from typing import List

class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        n = len(A)
        mp = [0] * (n + 1)

        comm = 0
        ans = [0] * n

        for i in range(n):
            mp[A[i]] += 1
            if mp[A[i]] == 2:
                comm += 1
            mp[B[i]] += 1
            if mp[B[i]] == 2:
                comm += 1

            ans[i] = comm

        return ans