/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int q[1000000];

int** highestPeak(int** isWater, int rows, int* isWaterColSize, int* returnSize, int** returnColumnSizes) {
    int cols = *isWaterColSize;
    int fetch = 0, put = 0;
    int drow[] = {-1,1,0,0};
    int dcol[] = {0,0,-1,1};

    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            if(isWater[i][j] == 1) q[put++] = i * cols + j;
            isWater[i][j]--;
        }
    }

    int pos, row, col, val, nrow, ncol;

    while(put > fetch){
        pos = q[fetch++];
        row = pos / cols;
        col = pos % cols;
        val = isWater[row][col];

        for(int i = 0; i<4; i++){
            nrow = row + drow[i];
            ncol = col + dcol[i];

            if(nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols && isWater[nrow][ncol] == -1){
                isWater[nrow][ncol] = val + 1;
                q[put++] = nrow * cols + ncol;
            }
        }
    }

    *returnSize = rows;
    *returnColumnSizes = isWaterColSize;
    return isWater;
}