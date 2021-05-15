class Solution:
    def longestPalindrome(self, s: str) -> str:
        def expand(l, r):
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l -= 1; r += 1
            return r-l-1

        if not s:
            return ""

        l, r = 0, 0
        for i in range(len(s)):
            len1 = expand(i, i)
            len2 = expand(i, i+1)
            length = max(len1, len2)
            if length > r-l+1:
                l =  i - (length-1)//2
                r = i + length//2
        return s[l:r+1]
