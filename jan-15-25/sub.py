class Solution:
    def minimizeXor(self, num1: int, num2: int) -> int:
        
        setBits = bin(num2).count('1')

        b1 = bin(num1)
        n = len(b1)

        ans = 0
        i = 0

        while i < n:
            if n - i <= setBits or setBits == 0:
                break

            if b1[i] == '1':
                ans = (ans << 1) + 1
                setBits -= 1
            else:
                ans = (ans << 1)

            i += 1

        while setBits > 0:
            ans = (ans << 1) + 1
            setBits -= 1
            i += 1

        if i < n:
            ans = ans << (n - i)

        return ans
            