# BFS
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def bfs(x, y):  
            queue = [(x,y)] # use deque if want actual queue
            while queue:
                x, y = queue.pop()
                if x+1 < len(grid) and grid[x+1][y] == "1": # down
                    grid[x+1][y] = "0" # visited
                    queue.append((x+1, y))
                if x-1 >= 0 and grid[x-1][y] == "1": # up
                    grid[x-1][y] = "0" # visited
                    queue.append((x-1, y))
                if y+1 < len(grid[0]) and grid[x][y+1] == "1": # right
                    grid[x][y+1] = "0" # visited
                    queue.append((x, y+1))
                if y-1 >= 0 and grid[x][y-1] == "1": # left
                    grid[x][y-1] = "0" # visited   
                    queue.append((x, y-1))
        
        total = 0
        rows = len(grid)
        cols = len(grid[0])
        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == "1":
                    bfs(row, col)
                    total += 1
        return total

# DFS recursive
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def dfs(x, y):  
            grid[x][y] = "0" # visited
            if x+1 < len(grid) and grid[x+1][y] == "1": # down
                dfs(x+1, y)
            if x-1 >= 0 and grid[x-1][y] == "1": # up
                dfs(x-1, y)
            if y+1 < len(grid[0]) and grid[x][y+1] == "1": # right
                dfs(x, y+1)
            if y-1 >= 0 and grid[x][y-1] == "1": # left
                dfs(x, y-1)    
        
        total = 0
        rows = len(grid)
        cols = len(grid[0])
        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == "1":
                    dfs(row, col)
                    total += 1
        return total
