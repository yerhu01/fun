void tranpose(int **matrix, int matrixSize, int *matrixColSize) {
    for (int r = 0; r < matrixSize; ++r) {
        for (int c = r; c < matrixColSize[r]; ++c) {
            int temp = matrix[r][c];
            matrix[r][c] = matrix[c][r];
            matrix[c][r] = temp;
        }
    }
}

void reflect(int **matrix, int matrixSize, int *matrixColSize) {
    for (int r = 0; r < matrixSize; ++r) {
        for (int c = 0; c < matrixColSize[r]/2; ++c) {
            int temp = matrix[r][c];
            matrix[r][c] = matrix[r][matrixSize + ~c];
            matrix[r][matrixSize + ~c] = temp;
        }
    }
}

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    tranpose(matrix, matrixSize, matrixColSize);
    reflect(matrix, matrixSize, matrixColSize);
}
