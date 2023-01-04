'''
OLD NOTES:
      3
     /
    2
   /
  1
Preorder = 321  Inorder = 123 => reverse (no right child)

  3
   \
    2
     \
      1
Preorder = 321 Inorder = 321 => same (no left child)

     4
    /
   2
  / \
 1   3
Preorder = 421 3 Inorder = 12 3 4  => single right child
421 => 12 (right subtree of 2) 4

     6
    /
   2
  / \
 1   3
    / \
   4   5
Preorder = 621 345  Inorder = 12 435 6 => subtree right child
621 => 12 (right sub tree) 6

   2
    \
     3
    / \
   4   5
Preorder = 2345 Inorder = 2435

         6
        /
       2
      / \
     1   3
    /   / \
   7   4   5
  / \
 8   9
Preorder = 621789345 Inorder = 879124356

Algorithm:
push preorder nodes on stack until reach 1st inorder
    pop, curr is left child
    if next same index is equal...  right child.
    if next is not reversed: => right subtree.
        add (recurse / repeat) right tree
'''
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        def create_tree(left, right):
            if left > right:
                return None

            nonlocal preorder_idx
            root = TreeNode(preorder[preorder_idx])
            preorder_idx += 1
            root.left = create_tree(left, inorder_idx[root.val]-1)
            root.right = create_tree(inorder_idx[root.val]+1, right)
            return root

        preorder_idx = 0
        inorder_idx = {n:i for i, n in enumerate(inorder)}
        return create_tree(0, len(inorder)-1)
