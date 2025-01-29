class Solution {
    int[][] grid;
    int rows, cols;

    private int dfs(int row, int col){
        if(row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] == 0) return 0;

        int val = grid[row][col];
        grid[row][col] = 0;
        val += dfs(row + 1, col) + dfs(row - 1, col) + dfs(row, col + 1) + dfs(row, col - 1);

        return val;
    }

    public int findMaxFish(int[][] grid) {
        int ans = 0;
        rows = grid.length;
        cols = grid[0].length;
        this.grid = grid;

        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                ans = Math.max(ans, dfs(row, col));
            }
        }

        return ans;
    }
}