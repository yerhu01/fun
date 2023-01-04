# Hash
import collections
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        x, y = Counter(s), Counter(t)
        return True if x == y else False

#  my Hash
import collections
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        c = collections.Counter()
        for i in range(len(s)):
            c[s[i]] += 1
            c[t[i]] -= 1
            
        for i in c.values():
            if i != 0:
                return False
        return True

# Sorting
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        return ''.join(sorted(s)) == ''.join(sorted(t))
