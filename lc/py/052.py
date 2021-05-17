# Recursive Inorder: O(h+k) time, O(h) space
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        def inorder(node):
            if not node:
                return None

            ret = inorder(node.left)
            if ret:
                return ret

            nonlocal k
            k -= 1
            if k == 0:
                return node

            ret = inorder(node.right)
            if ret:
                return ret

        return inorder(root).val;

# Recursive Inorder: O(h+k) time, O(h+k) space
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        def inorder(root):
            if root and len(ret) < k:
                inorder(root.left)
                if len(ret) < k:
                    ret.append(root.val)
                    inorder(root.right)

        ret = []
        inorder(root)
        return ret[k-1]

# Recursive Inorder: O(n) time, O(n) space
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        def inorder(root):
            if root:
                inorder(root.left)
                ret.append(root.val)
                inorder(root.right)

        ret = []
        inorder(root)
        return ret[k-1]
