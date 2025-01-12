class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        
        dq = []
        stack = []

        for i in range(len(s)):

            if locked[i] == '1':

                if s[i] == '(':
                    stack.append(i)
                else :
                    if stack:
                        stack.pop()
                    else:
                        if dq:
                            dq.pop()
                        else :
                            return False

            else :
                dq.append(i)

        while stack and dq and stack[-1] < dq[-1]:
            stack.pop()
            dq.pop()

        if stack:
            return False

        return len(dq) % 2 == 0