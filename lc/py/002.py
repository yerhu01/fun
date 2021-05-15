class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ret = 0
        start = 0
        prev = {}
        for i, c in enumerate(s):
            if c in prev and prev[c] >= start:
                start = prev[c]+1
            prev[c] = i
            ret = max(ret, i-start+1)
        return ret
