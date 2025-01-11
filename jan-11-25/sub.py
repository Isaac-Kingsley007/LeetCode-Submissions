from collections import Counter

class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        if len(s) < k:
            return False
        if len(s) == k:
            return True

        odd = sum([cnt & 1 for k,cnt in Counter(s).items()])

        return odd <= k

        