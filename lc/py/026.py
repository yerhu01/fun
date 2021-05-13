# Recursive DFS
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        def same(p, q):
            if not p and not q:
                return True
            elif not p or not q:
                return False
            elif p.val != q.val:
                return False
            return same(p.left, q.left) and same(p.right, q.right)
        return same(p, q)

# BFS
import collections
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        def check(p, q):
            if not p and not q:
                return True
            elif not p or not q:
                return False
            elif p.val == q.val:
                return True
            else:
                return False

        dq = collections.deque([(p,q)])
        while dq:
            p, q = dq.popleft()
            if not check(p, q):
                return False
            if p:
                dq.extend([(p.left, q.left), (p.right, q.right)])

        return True
