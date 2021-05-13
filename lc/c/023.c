bool precheck(char **board, int numRows, int numCols, char *word) {
    int cnt[128] = {0};
    for (int i = 0; i < strlen(word); ++i) {
        cnt[word[i]] += 1;
    }
    for (int i = 0; i < numRows; ++i){
        for (int j = 0; j < numCols; ++j) {
            if (cnt[board[i][j]])
                cnt[board[i][j]] -= 1;
        }
    }
    for (int i = 0; i < sizeof(cnt)/sizeof(*cnt); ++i) {
        if (cnt[i] > 0)
            return false;
    }
    return true;
}

bool dfs(char **board, int numRows, int numCols,
         int r, int c, char *pos) {
    if (*pos == 0)
        return true;
    else if (r < 0 || c < 0 || r >= numRows || c >= numCols)
        return false;
    else if (board[r][c] != *pos)
        return false;

    board[r][c] |= 0x80; // visited
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    for (int i = 0; i < sizeof(dir)/sizeof(*dir); ++i) {
        int x = dir[i][0], y = dir[i][1];
        if (dfs(board, numRows, numCols, r+x, c+y, pos+1))
            return true;
    }
    board[r][c] &= ~0x80; // unvisited
    return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    if (!precheck(board, boardSize, boardColSize[0], word))
        return false;

    for (int r = 0; r < boardSize; ++r) {
        for (int c = 0; c < boardColSize[r]; ++c) {
            if (dfs(board, boardSize, boardColSize[r], r, c, word))
                return true;
        }
    }
    return false;
}
