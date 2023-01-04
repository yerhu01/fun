# check this
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        n = numCourses
        graph = [[] for _ in range(n)]
        g = [0] * n
        for v, u in prerequisites:
            graph[u].append(v)
            g[v] += 1
        S = [ v for v in range(n) if g[v] == 0]
        while S:
            u = S.pop()
            for v in graph[u]:
                g[v] -= 1
                if g[v] == 0:
                    S.append(v)
        return not any(g)
"""
Very nice! For anyone else who may be wondering, the array S is the stack of all courses you can take. g[v] is the number of prerequisites needed to clear before we can take course v. When g[v] == 0, we took all of v's prerequisites already and therefore we can take course v now, by adding it to the stack S. At the end, we must have taken every course, so that g[i] for all i must be 0. Then, any(g) will be False, and not any(g) is True.
"""
# my solution
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        def dfs(c, visited):
            if d[c] == []: # no requirements
                return True
            elif c in visited: # cycle
                return False
            # check prereq completable
            visited.add(c)
            for r in d[c]:
                if not dfs(r, visited):
                    return False
            d[c] = []
            return True
        
        d = {i:[] for i in range(numCourses)}
        for c, r in prerequisites:
            d[c].append(r)
            
        for c in range(numCourses):
            if not dfs(c, set()):
                return False
        return True

# note on visited=set() behavior. changing visited changes for recursive calls
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        def dfs(c, visited=set()):
            if d[c] == []: # no requirements
                return True
            elif c in visited: # cycle
                return False
            # check prereq completable
            visited.add(c)
            for r in d[c]:
                if not dfs(r):
                    return False
            d[c] = []
            return True
        
        d = {i:[] for i in range(numCourses)}
        for c, r in prerequisites:
            d[c].append(r)
            
        for c in range(numCourses):
            if not dfs(c):
                return False
        return True
