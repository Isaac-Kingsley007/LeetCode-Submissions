from typing import List
from collections import defaultdict,Counter

class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        
        w2_count = defaultdict(int)
        a = ord('a')

        for word in words2:
            count_mp = Counter(word)
            
            for l,cnt in count_mp.items():
                w2_count[l] = max(w2_count[l],cnt)

        ans = []
        w2_count = w2_count.items()

        for word in words1:
            isValid = True
            count_mp = Counter(word)
            
            for l,cnt in w2_count:
                if count_mp[l] < cnt:
                    isValid = False
                    break
            
            if isValid:
                ans.append(word)

        return ans