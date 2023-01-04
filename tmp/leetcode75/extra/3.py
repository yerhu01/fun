'''
break down into 2's and 3's
10 = 3 x 3 x 2 x 2 = 36
12 = 3 x 3 x 3 x 3 = 81
9 = 3 x 3 x 3 = 27
6 = 3 x 3 = 9
5 = 3 x 2 = 10
4 = 2 x 2 = 4
8 = 3 x 3 x 2 = 18
2 = 1 x 1 = 1
3 = 1 2 = 2

algorithm:
repeatedly mult by 3 until left over is 4, 3 or 2
    if 4, mult by 4 (2x2)
    if 3, mult by 3
    if 2, mult by 2

if n = 2 or 3, return 1 and 2
'''

class Solution:
    def integerBreak(self, n: int) -> int:
        if n == 2 or n == 3:
            return n-1

        exp, remainder = divmod(n, 3)
        if remainder == 0:
            return 3**exp
        if remainder == 1: # can end with 4
            exp -= 1
            remainder = 4
        return 3**exp * remainder

    def integerBreak(self, n: int) -> int:
        if n == 2 or n == 3:
            return n-1

        ret = 1
        while n > 4:
            ret *= 3
            n -= 3
        ret *= n
        return ret
