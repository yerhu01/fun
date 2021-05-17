class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        def dfs(node):
            if node:
                dfs(node.left)
                dfs(node.right)
                node.left, node.right = node.right, node.left

        dfs(root)
        return root
