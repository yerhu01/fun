'''
SOLUTION:
DP
iterate, keep track of # of ways for
    i-1 (if no new separable component)
    i-2 (if new separable component)
    
2222922
1
2 = 1
22 = 1+1 = 2
222 = 1+2 = 3
2222 = 2+3 = 5
22229 = 5
222292 = 5
2222922 = 10

13913913
1
1 = 1
13 = 1+1 = 2
139 = 2 => 1 3 9 and 13 9 ways
1391 = 2
13913 = 2+2 = 4  => 2 (consider as 3 only) + 2 (1 3 9 | 13 and 13 9 | 13, consider as  13)
139139 = 4
1391391 = 4
13913913 = 4+4 = 8
'''
class Solution:
    def numDecodings(self, s: str) -> int:
        prev = 0
        ret = 1

        for i in range(len(s)):
            cur = 0  # ways up to i
            if s[i] != '0':
                cur += ret  # ways up to i-1
            if i > 0 and 10 <= int(s[i-1:i+1]) <= 26:
                cur += prev  # add ways up to i-2
            if cur == 0:
                return 0  # invalid mapping ex. start with 0 or 90
            prev, ret = ret, cur # update for the next
        return ret

'''
FAILED ATTEMPT:
11122
1 1 1 2 2 = + 1  = 2, 2, 2, 2, 0
11 1 2 2
1 11 2 2
1 1 12 2
1 1 1 22 = 4 joined splits = can only have 2 = 7
11 12 2
1 11 22
11 1 22 = 8 ways

11922
1 1 9 2 2
11 9 2 2
1 19 2 2
1 1 9 22 = 3 splits = 2 joined + 1 sep
11 9 22 = 5 ways

13913913  
1 3 9 1 3 9 1 3 
13 9 1 3 9 1 3
1 3 9 13 9 1 3
1 3 9 1 3 9 13
13 9 13 9 1 3
1 3 9 13 9 13
13 9 1 3 9 13
13 9 13 9 13 =  6 + 1 = 8 ways

ret = 1, +1, 0, 0, +1+1sep, 0,0, +1+3C2 (2)+ 3C3 (1) = 8 ways

13913913913
1 3 9 1 3 9 1 3 9 1 3 = nC0 = 1
13 9 1 3 9 1 3 9 1 3 = 1C1 = 1
1 3 9 13 9 1 3 9 1 3 = 2C1 - 1C1 = 1
1 3 9 1 3 9 13 9 1 3 = 3C1 - 2C1 - 1C1 = 1
1 3 9 1 3 9 1 3 9 13 = 4C1 - 3C1 - 2C1 - 1C1 = 1
13 13       = 1 = 2C2
13    13    = 3 = 3C2 + 3C3 = 2 + 1
   13 13
13 13 13
13       13 = 7 = 4C2 - 3C2 -2C2 + 4C3 - 3C3 + 4C4 = 6 - 2 - 1 + 4 - 1 + 1 = 7
   13    13
      13 13
13 13    13
13    13 13
   13 13 13
13 13 13 13 = 16 ways

ret= 1, +1,0,0, +1+1,0,0, +1+3,0,0, +1+7 = 16

total # of combinations: nCr
4C0 + 4C1 + 4C2 + 4C3 + 4C4
1 + 4 + 6 + 4 + 1 = 16
'''

