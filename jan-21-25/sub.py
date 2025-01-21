from typing import List
from math import inf

class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        
        p1 = sum(grid[0])
        p2 = 0
        ans = inf
        curr = ans

        for a,b in zip(grid[0], grid[1]):
            p1 -= a
            curr = max(p1,p2)
            if curr <= ans:
                ans = curr
            else:
                break 
            p2 += b

        return ans