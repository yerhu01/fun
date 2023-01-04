// one for loop to iterate over 2d array
// r = i&rows, c = i/rows
    for (int i = 0; i < boardSize*boardColSize[0]; ++i) {
        if (dfs(board, boardSize, boardColSize[0], word, i%boardSize, i/boardSize))
            return true;
    }

// binary manipulation to set visited / unvisited
bool precheck(char **board, int rows, int cols, char *word) {
    int counter[128] = {0};
    for (int i = 0; i < strlen(word); ++i) {
        counter[word[i]] += 1;
    }
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j) {
            if (counter[board[i][j]])
                counter[board[i][j]] -= 1;
        }
    }
    for (int i = 0; i < 128; ++i) {
        if (counter[i] > 0)
            return false;
    }
    return true;
}

bool dfs(char **board, int rows, int cols, char *word, 
         int i, int j) {
    if (*word == 0)
        return true;
    if (!(0 <= i && i < rows && 0 <= j && j < cols))
        return false;
    
    if (board[i][j] == *word) {
        board[i][j] |= 0x80; // visited
        if (dfs(board, rows, cols, word+1, i+1, j))
            return true;
        if (dfs(board, rows, cols, word+1, i-1, j))
            return true;
        if (dfs(board, rows, cols, word+1, i, j+1))
            return true;
        if (dfs(board, rows, cols, word+1, i, j-1))
            return true;
        board[i][j] &= ~0x80; // unvisited
    }
    return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    if (!precheck(board, boardSize, boardColSize[0], word))
        return false;
        
    for (int r = 0; r < boardSize; ++r) {
        for (int c = 0; c < boardColSize[r]; ++c) {
            if (dfs(board, boardSize, boardColSize[0], word, r, c))
                return true;
        }
    }
    
    return false;
}

// visited array
bool precheck(char **board, int rows, int cols, char *word) {
    int counter[128] = {0};
    for (int i = 0; i < strlen(word); ++i) {
        counter[word[i]] += 1;
    }
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j) {
            if (counter[board[i][j]])
                counter[board[i][j]] -= 1;
        }
    }
    for (int i = 0; i < 128; ++i) {
        if (counter[i] > 0)
            return false;
    }
    return true;
}

bool dfs(char **board, int rows, int cols, char *word, 
         int i, int j, int pos, int visited[rows][cols]) {
    if (pos == strlen(word)){
        return true;
    }
    if (!(0 <= i && i < rows && 0 <= j && j < cols) || visited[i][j]){
        return false;
    }
    if (board[i][j] == word[pos]) {
        visited[i][j] = 1;
        if (dfs(board, rows, cols, word, i+1, j, pos+1, visited))
            return true;
        if (dfs(board, rows, cols, word, i-1, j, pos+1, visited))
            return true;
        if (dfs(board, rows, cols, word, i, j+1, pos+1, visited))
            return true;
        if (dfs(board, rows, cols, word, i, j-1, pos+1, visited))
            return true;
        visited[i][j] = 0;
    }
    return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    if (!precheck(board, boardSize, boardColSize[0], word))
        return false;
    
    int visited[boardSize][boardColSize[0]];
    memset(visited, 0, boardSize*boardColSize[0]*sizeof(int));
        
    for (int r = 0; r < boardSize; ++r) {
        for (int c = 0; c < boardColSize[r]; ++c) {
            if (dfs(board, boardSize, boardColSize[0], word, r, c, 0, visited))
                return true;
        }
    }
    
    return false;
}

// malloc visited
bool precheck(char **board, int rows, int cols, char *word) {
    int counter[128] = {0};
    for (int i = 0; i < strlen(word); ++i) {
        counter[word[i]] += 1;
    }
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j) {
            if (counter[board[i][j]])
                counter[board[i][j]] -= 1;
        }
    }
    for (int i = 0; i < 128; ++i) {
        if (counter[i] > 0)
            return false;
    }
    return true;
}

bool dfs(char **board, int rows, int cols, char *word, 
         int i, int j, int pos, int **visited) {
    if (pos == strlen(word)){
        return true;
    }
    if (!(0 <= i && i < rows && 0 <= j && j < cols) || visited[i][j]){
        return false;
    }
    if (board[i][j] == word[pos]) {
        visited[i][j] = 1;
        if (dfs(board, rows, cols, word, i+1, j, pos+1, visited))
            return true;
        if (dfs(board, rows, cols, word, i-1, j, pos+1, visited))
            return true;
        if (dfs(board, rows, cols, word, i, j+1, pos+1, visited))
            return true;
        if (dfs(board, rows, cols, word, i, j-1, pos+1, visited))
            return true;
        visited[i][j] = 0;
    }
    return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    if (!precheck(board, boardSize, boardColSize[0], word))
        return false;

    int **visited = malloc(boardSize * sizeof(int*));
    for (int i = 0; i < boardSize; ++i) {
        visited[i] = calloc(boardColSize[0], sizeof(int));
    }
    for (int r = 0; r < boardSize; ++r) {
        for (int c = 0; c < boardColSize[r]; ++c) {
            if (dfs(board, boardSize, boardColSize[0], word, r, c, 0, visited))
                return true;
        }
    }

    for (int i = 0; i < boardSize; ++i) {
        free(visited[i]);
    }
    free(visited);
    return false;
}
