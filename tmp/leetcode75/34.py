# recursive DFS (iterative not possible?)
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        def dfs(n):
            for neighbor in n.neighbors:
                if not neighbor in d:
                    d[neighbor] = Node(neighbor.val)
                    dfs(neighbor)
                d[n].neighbors.append(d[neighbor])
        
        if not node:
            return None
        
        d = {}
        d[node] = Node(node.val)
        dfs(node)
        return d[node]

# BFS
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return None
        
        queue = []
        d = {}
        d[node] = Node(node.val)
        queue.append(node)
        while queue:
            n = queue.pop()
            for neighbor in n.neighbors:
                if not neighbor in d:
                    d[neighbor] = Node(neighbor.val)
                    queue.append(neighbor)
                d[n].neighbors.append(d[neighbor])
        return d[node]
