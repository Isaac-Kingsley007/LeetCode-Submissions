from typing import List
from collections import deque

class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        
        rows = len(isWater)
        cols = len(isWater[0])

        q = deque()

        dirs = [(-1,0), (1,0), (0,-1), (0,1)]

        for i in range(rows):
            for j in range(cols):
                if isWater[i][j] == 1:
                    isWater[i][j] = 0
                    q.append(i * cols + j)
                else:
                    isWater[i][j] = -1


        while q:
            
            pos = q.popleft()
            row = pos//cols
            col = pos % cols
            val = isWater[row][col]

            for drow, dcol in dirs:

                nrow, ncol = row + drow, col + dcol

                if 0 <= nrow < rows and 0 <= ncol < cols and isWater[nrow][ncol] == -1:

                    isWater[nrow][ncol] = val + 1

                    q.append(nrow * cols + ncol)

        return isWater

