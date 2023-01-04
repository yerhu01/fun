class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        def dfs(root):
            if not root:
                return 0
            n = root.val
            l = dfs(root.left)
            r = dfs(root.right)
            max_single = max(n, n+max(l,r)) # for parent
            max_top = max(max_single, n+l+r)
            
            max_result[0] = max(max_result[0], max_top)
            return max_single
        
        max_result = [float('-inf')]
        dfs(root)
        return max_result[0]
