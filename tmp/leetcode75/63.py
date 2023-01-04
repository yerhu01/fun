'''

BASIC ADD:
0100 = 4
0111 = 7
1011 = 11
carry = 1000


SUBTRACT
1011 = 11
0111 = 7
0100 = 4


Both neg: ADD, negate

one is neg: => neg + pos => subtract
pos > neg
5 + -2 = subtract
-5 + 2 = 

0011 = 3
1110 = -2
0001 = 1

neg > pos = 
11111011 = -5
00000011 = 3
00000110 = carry
11111000 = a
11111110 = a
~00000001 = 11111110 = -2
11111110 = -2

11111101 = -3
11111011 = -5
11111000 = -8

CASE: -7 + 11
(256-7) + 11 = 256+4 => need to get the +4 part => 256 taken from carry
11111111 = MASK 0xFF , max int 0x7F = 01111111 = 127
11111001 = -7 = 0xF9 = 249 = 256-7
00001011 = 11 = 0x0B = 11
00010010 = carry = b
11110010 = a
00100100 = carry = b
11100000 = a
01000000 = carry = b
11000100 = a
10000000 = carry = b
10000100 = a
100000000 = carry = b
00000100 = a
00000000 = carry
00000100 = a = 4
100000100 = 256+4 = 260 (if the carry wasn't taken)

CASE:-12 + -8
Treat as adding positives, after mask...
(256-12) + (256-8) = (2*256-20) => need to get the -20 part
11111111 = MASK , max int = 01111111 = 127
11110100 = -12 = 0xF4 = 244 = 256 - 12 => means -12 in mask
11111000 = -8 = 0xF8 = 248 = 256 - 8   => means -8 in mask
11100000 = carry = b
00001100 = a
00000000 = carry
11101100 = a = 0xEC = 236  NOTE: 256-20 = 236 => (means -20 in mask, need to get -20 from 236)
    => make it back into an actual neg number by flipping all bits ahead of mask
111101100 = 0x1EC = 492 (if carry wasn't taken, so got rid of 1*256)
since 236 > 126
11101100 = a = 0xEC = 236  (means -20 in our mask)
00010011 = a^mask (behaves like ~, flip bits only in mask) = 0x13 = 19
   if we did ~a would get -237, flips bits ahead of mask as well, don't want this.
11101100 = ~(a^mask) (flip everything, since flipped stuff in mask before, cancelled out) 
    = ~(0x13) = ~19 = -20 (means -20 on our platform)
'''
class Solution:
    def getSum(self, a: int, b: int) -> int:
        mask = 0xFFFFFFFF
        while b:
            carry = ((a & b) << 1) & mask
            a  = (a ^ b) & mask
            b = carry
        max_int = 0x7FFFFFFF
        return a if a <= max_int else ~(a ^ mask)
    
    def getSum(self, a: int, b: int) -> int:
        def getDifference(a,b):
            mask = 0xFFFFFFFF
            while b:
                borrow = ((~a & b) << 1) & mask
                a  = (a ^ b) & mask
                b = borrow
            max_int = 0x7FFFFFFF
            return a if a <= max_int else ~(a ^ mask)
        return getDifference(a,-b)

    def getSum1(self, a: int, b: int) -> int:
        def add(a, b):
            # repeat until no carry
            while b:
                carry = a & b  # common set bits
                a ^= b         # add where one bit not set
                b = carry << 1 # carry to be added next round
            return a
        
        def subtract(a, b):
            while b:
                borrow = ~a & b # bits where a is not set but b is set
                a ^= b          
                b = borrow << 1
            return a
        
        print(add(7,11))
        #print(add(-7, 11)) #can't do
        print(add(-11, 7))
        print(add(7,-11))
        print(add(-7,-11))
        print(subtract(11,7))
        #print(subtract(7,11)) # can't do
        #print(subtract(-11,-7)) # can't do
        print(subtract(-11,7))
        print(subtract(7, -11))
        
        if a > 0 and b > 0:
            return add(a,b)
        elif a < 0 and b < 0:
            return -add(-a,-b)
        
        if abs(a) == abs(b) and a < b: # -1 , 1
            a, b = b, a
            return subtract(a,-b)
            
        if abs(b) > abs(a):
            a, b = b, a
            
        if a < 0:
            return -subtract(-a,b)
        else:
            return subtract(a,-b)
