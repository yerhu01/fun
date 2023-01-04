void dfs(int **heights, int row_len, int col_len,
        int r, int c, int *reachable) {
    int new_r, new_c;
    int directions[8] = {0,-1, 0,1, 1,0, -1,0};
    
    reachable[r*col_len + c] = 1;
    for (int i = 0; i < 8; i += 2) {
        new_r = r + directions[i];
        new_c = c + directions[i+1];
        
        if (new_r < 0 || new_r >= row_len || new_c < 0 || new_c >= col_len)
            continue;
        if (reachable[new_r*col_len+new_c])
            continue;
        if (heights[new_r][new_c] < heights[r][c])
            continue;
        
        dfs(heights, row_len, col_len, new_r, new_c, reachable);    
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes){
    int p_reachable[heightsSize * heightsColSize[0]];
    memset(p_reachable, 0, heightsSize * heightsColSize[0] * sizeof(int) );
    int a_reachable[heightsSize * heightsColSize[0]];
    memset(a_reachable, 0, heightsSize * heightsColSize[0] * sizeof(int) );
    
    for (int r = 0; r < heightsSize; ++r) {
        dfs(heights, heightsSize, heightsColSize[0], r, 0, p_reachable);
        dfs(heights, heightsSize, heightsColSize[0], r, heightsColSize[0]-1, a_reachable);
    }
    for (int c = 0; c < heightsColSize[0]; ++c) {
        dfs(heights, heightsSize, heightsColSize[0], 0, c, p_reachable);
        dfs(heights, heightsSize, heightsColSize[0], heightsSize-1, c, a_reachable);
    }
    
    *returnSize = 0;
    for (int i = 0; i < heightsSize * heightsColSize[0]; ++i) {
        if (p_reachable[i] == 1 && a_reachable[i] == 1) {
            (*returnSize)++;
        }
    }
    int **ret = malloc(*returnSize * sizeof(int*));
    *returnColumnSizes = malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; ++i) {
        (*returnColumnSizes)[i] = 2;
    }
    int j = 0;
    for (int i = 0; i < heightsSize * heightsColSize[0]; ++i) {
        if (p_reachable[i] == 1 && a_reachable[i] == 1) {
            ret[j] = malloc(2 * sizeof(int));
            ret[j][0] = i / heightsColSize[0];
            ret[j][1] = i % heightsColSize[0];
            j++;
        }
    }
    return ret;
}
