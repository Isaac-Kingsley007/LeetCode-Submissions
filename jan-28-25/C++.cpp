#include <vector>
using namespace std;

class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid, int rows, int cols){
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

    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        int rows = grid.size(), cols = grid[0].size();
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                ans = max(ans, dfs(row, col, grid, rows, cols));
            }
        }

        return ans;
    }
};