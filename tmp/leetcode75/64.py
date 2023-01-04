class Solution:
    # LC BFS solution
    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
        def bfs(queue):
            reachable = set()
            while queue:
                i, j = queue.popleft()
                reachable.add((i,j))
                for x, y in ((0,-1),(0,1),(1,0),(-1,0)):
                    new_i, new_j = i+x, j+y
                    if new_i < 0 or new_i >= len(matrix) or new_j < 0 or new_j >= len(matrix[0]):
                        continue
                    if (new_i, new_j) in reachable:
                        continue
                    if matrix[new_i][new_j] < matrix[i][j]:
                        continue
                    queue.append((new_i, new_j))
            return reachable
        
        pacific_queue = deque()
        atlantic_queue = deque()
        for r in range(len(matrix)):
            pacific_queue.append((r, 0))
            atlantic_queue.append((r, len(matrix[0])-1))
        for c in range(len(matrix[0])):
            pacific_queue.append((0, c))
            atlantic_queue.append((len(matrix)-1, c))
            
        pacific_reachable = bfs(pacific_queue)
        atlantic_reachable = bfs(atlantic_queue)
        return list(pacific_reachable & atlantic_reachable)

    # LC DFS solution
    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
        def dfs(i, j, reachable):
            reachable.add((i,j))
            for x, y in ((0,-1),(0,1),(1,0),(-1,0)):
                new_i, new_j = i+x, j+y
                if new_i < 0 or new_i >= len(matrix) or new_j < 0 or new_j >= len(matrix[0]):
                    continue
                if (new_i, new_j) in reachable:
                    continue
                if matrix[new_i][new_j] < matrix[i][j]:
                    continue
                dfs(new_i, new_j, reachable)
                
        pacific_reachable = set()
        atlantic_reachable = set()
        for r in range(len(matrix)):
            dfs(r, 0, pacific_reachable)
            dfs(r, len(matrix[0])-1, atlantic_reachable)
        for c in range(len(matrix[0])):
            dfs(0, c, pacific_reachable)
            dfs(len(matrix)-1, c, atlantic_reachable)
        return [ [i,j] for i, j in (pacific_reachable & atlantic_reachable) ]
