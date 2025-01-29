int dfs(int row, int col, int** grid, int rows, int cols){

    if(row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] == 0) return 0;

    int val = grid[row][col];
    grid[row][col] = 0;
    val +=
    dfs(row + 1, col, grid, rows, cols) +
    dfs(row - 1, col, grid, rows, cols) +
    dfs(row, col + 1, grid, rows, cols) +
    dfs(row, col - 1, grid, rows, cols);

    return val;
}


int findMaxFish(int** grid, int rows, int* gridColSize) {
    int cols = *gridColSize, ans = 0, val;

    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            val = dfs(row, col, grid, rows, cols);
            if(val > ans) ans = val;
        }
    }

    return ans;
}