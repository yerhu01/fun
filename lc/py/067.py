class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        def sameTree(s, t):
            if not s and not t:
                return True
            elif not s or not t:
                return False
            elif s.val != t.val:
                return False
            return sameTree(s.left, t.left) and sameTree(s.right, t.right)

        def dfs(s):
            if not s:
                return False
            elif s.val == t.val and sameTree(s, t):
                return True
            return dfs(s.left) or dfs(s.right)

        return dfs(s)
