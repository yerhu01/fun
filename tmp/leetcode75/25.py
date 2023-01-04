# in_range
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def in_range(root, low=float('-inf'), high=float('inf')):
            if not root:
                return True
            elif low < root.val < high:
                return (in_range(root.left, low, root.val) and 
                        in_range(root.right, root.val, high))
            else:
                return False
            
        return in_range(root)

# inorder traversal
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def inorder(root):
            if not root:
                return True
            elif not inorder(root.left):
                return False
            elif prev[0] and prev[0].val >= root.val:
                return False
            prev[0] = root
            return inorder(root.right)
            
        prev = [None]
        return inorder(root)

# my inorder
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def inorder(root):
            if not root:
                return True
            elif not inorder(root.left):
                return False
            elif curr[0] >= root.val:
                return False
            curr[0] = root.val
            return inorder(root.right)
        
        curr = [float('-inf')]
        return inorder(root)
