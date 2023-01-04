
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        def dfs(root):
            if root:
                depth[CURR] +=1
                depth[MAX] = max(depth[MAX], depth[CURR])
                if root.left:
                    dfs(root.left)
                    depth[CURR] -=1
                if root.right:
                    dfs(root.right)
                    depth[CURR] -=1
        
        CURR = 0
        MAX = 1
        depth = [0, 0]
        dfs(root)
        return depth[MAX]
