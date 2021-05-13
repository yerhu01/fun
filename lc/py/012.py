class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        # Flip over diagonal
        def transpose():
            for r in range(len(matrix)):
                for c in range(r, len(matrix[r])):
                    matrix[r][c], matrix[c][r] = matrix[c][r], matrix[r][c]

        # Reflect over vertical
        def reflect():
            for r in range(len(matrix)):
                for c in range(len(matrix[r])//2):
                    matrix[r][c], matrix[r][~c] = matrix[r][~c], matrix[r][c]

        transpose()
        reflect()

# Alternative solution
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        for i in range(n//2): # for layers
            for j in range(i, n-i-1): # for column, -1 to exclude last corner
                (matrix[i][j], matrix[~j][i], matrix[~i][~j], matrix[j][~i]) = (matrix[~j][i], matrix[~i][~j], matrix[j][~i], matrix[i][j])
