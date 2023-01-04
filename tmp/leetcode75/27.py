class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        
        ret = []
        curr_depth = [root]
        while curr_depth:
            ret.append([node.val for node in curr_depth])
            curr_depth = [
                child for node in curr_depth for child in (node.left, node.right) if child
            ]
        return ret

# NOTE: we want list of lists for different levels.
# the following prints out the value of bfs traversal
    def bfs(root):
        if not root:
            return []
        
        ret = []
        q = collections.deque()
        q.append(root)
        while q:
            n = q.popleft()
            ret.append(n.val)
            if n.left:
                q.append(n.left)
            if n.right:
                q.append(n.right)
        return ret
