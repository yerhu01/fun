# Mask and shift
class Solution:
    def reverseBits(self, n: int) -> int:
        n = (n >> 16) | (n << 16)
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8)
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4)
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2)
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1)
        return n

# Bit shifting
class Solution:
    def reverseBits(self, n: int) -> int:
        # 32 bit unsigned integer
        ret, power = 0, 31
        while n:
            ret |= (n & 1) << power
            n >>= 1
            power -= 1
        return ret
