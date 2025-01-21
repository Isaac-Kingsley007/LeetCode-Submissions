class Solution {
    public int firstCompleteIndex(int[] arr, int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int mp[] = new int[m * n + 1];

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mp[mat[i][j]] = i * n + j;
            }
        }

        int rows[] = new int[m], cols[] = new int[n];

        int len = arr.length, hs;
        for(int i = 0; i<len; i++){
            hs = mp[arr[i]];
            rows[hs/n]++;
            if(rows[hs/n] == n) return i;
            cols[hs % n]++;
            if(cols[hs % n] == m) return i;
        }

        return m * n - 1;
    }
}