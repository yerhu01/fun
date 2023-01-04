class Solution:
    def countSubstrings(self, s: str) -> int:
        def expand(l, r):
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l -= 1; r += 1
                ret[0] += 1
                
        ret = [0]
        for i in range(len(s)):
            expand(i, i)
            expand(i, i+1)
        return ret[0]
