# O(1) space


# O(m+n) space
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        rows, cols = set(), set()
        
        for row in range(len(matrix)):
            for col in range(len(matrix[0])):
                if matrix[row][col] == 0:
                    rows.add(row)
                    cols.add(col)
                    
        for row in range(len(matrix)):
            for col in range(len(matrix[0])):
                if row in rows or col in cols:
                    matrix[row][col] = 0
