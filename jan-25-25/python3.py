from typing import List

class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        
        pairs = [(n,i) for i,n in enumerate(nums)]
        pairs.sort()

        indices = [pairs[0][1]]
        lastStoped = 0

        for i in range(len(nums) - 1):

            if pairs[i+1][0] - pairs[i][0] > limit:

                indices.sort()

                for j in range(len(indices)):

                    nums[indices[j]] = pairs[j + lastStoped][0]

                indices.clear()
                lastStoped = i + 1
            
            indices.append(pairs[i+1][1])

        if indices:
            indices.sort()

            for j in range(len(indices)):
                nums[indices[j]] = pairs[j + lastStoped][0]
            

        return nums
