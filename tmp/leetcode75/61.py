'''
0 0000 = 0
1 0001 = 1
2 0010 = 1
3 0011 = 2
4 0100 = 1
5 0101 = 2
6 0110 = 2
7 0111 = 3
8 1000 = 1  => 0+1
9 1001 = 2  => 1+1
10 1010 = 2 => 1+1
11 1011 = 3 => 2+1
12 1100 = 2 => 1+1
13 1101 = 3 => 2+1
14 1110 = 3 => 2+1
15 1111 = 4 => 3+1
'''

class Solution:
    # DP solution
    def countBits(self, num: int) -> List[int]:
        ret = [ 0 for _ in range(num+1)]
        i = 0
        for n in range(1, len(ret)):
            if n&(n-1) == 0: # n is power of 2
                i = 0
            ret[n] = ret[i] + 1
            i += 1
        return ret

    # Trivial solution
    def countBits(self, num: int) -> List[int]:
        def bits(n):
            count = 0
            while n:
                count += 1
                n &= n-1
            return count
        
        ret = []
        for n in range(num+1):
            ret.append(bits(n))
        return ret
