'''
catsandog [cat, cats, sand, an, dog]
can use multiple times

c,a,t,s,a,n,d,o,g => s
0,1,2,3,4,5,6,7,8 => index

 0,1,2,3,4,5,6,7,8,9  => index
[1,0,0,1,1,0,1,1,0,1] => dp Track reachable
'''

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        dp = [0 for _ in range(len(s)+1)]
        dp[0] = 1
        
        for i in range(len(s)):
            if dp[i]:
                for w in wordDict:
                    # slicing outside of bounds doesn't cause error
                    if s[i:i+len(w)] == w:
                        dp[i+len(w)] += 1
                        
        return True if dp[-1] else False
