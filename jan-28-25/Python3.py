from typing import List

class Solution:
    def findMaxFish(self, grid: List[List[int]]) -> int:

        rows, cols = len(grid), len(grid[0])

        def dfs(row, col):

            if row < 0 or col < 0 or row >= rows or col >= cols or grid[row][col] == 0:
                return 0

            val = grid[row][col]
            grid[row][col] = 0
            val += dfs(row + 1, col) + dfs(row - 1, col) + dfs(row, col + 1) + dfs(row, col - 1)

            return val

        ans = 0

        for row in range(rows):
            for col in range(cols):

                if grid[row][col]:
                    ans = max(ans, dfs(row, col))

        return ans
