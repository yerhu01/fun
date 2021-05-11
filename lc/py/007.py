class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        lookup = {'(':')', '{':'}', '[':']'}
        for c in s:
            if c in lookup:
                stack.append(c)
            elif not stack or lookup[stack.pop()] != c:
                return False
        return not stack
