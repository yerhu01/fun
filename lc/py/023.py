class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def precheck():
            counter = collections.Counter(word)
            for row in board:
                for ch in row:
                    if ch in counter:
                        counter[ch] -= 1

            for count in counter.values():
                if count > 0:
                    return False
            return True

        def dfs(r, c, pos):
            if pos == len(word):
                return True
            elif r < 0 or c < 0 or r >= len(board) or c >= len(board[r]):
                return False
            elif (r, c) in visited:
                return False
            elif board[r][c] != word[pos]:
                return False

            visited.add((r, c))
            for x, y in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                if dfs(r+x, c+y, pos+1):
                    return True
            visited.remove((r,c))
            return False

        if not precheck():
            return False

        visited = set()
        for r in range(len(board)):
            for c in range(len(board[r])):
                if dfs(r, c, 0):
                    return True
        return False
