# Hash Table
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        x, y = Counter(s), Counter(t)
        return True if x == y else False

# Sorting
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        return ''.join(sorted(s)) == ''.join(sorted(t))
