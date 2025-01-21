int firstCompleteIndex(int* arr, int len, int** mat, int m, int* matColSize) {
    int n = *matColSize;
    int mp[m * n + 1];

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            mp[mat[i][j]] = i * n + j;
        }
    }

    int rows[m], cols[n];
    memset(rows, 0, sizeof(int) * m);
    memset(cols, 0, sizeof(int) * n);

    int hs;
    for(int i = 0; i<len; i++){
        hs = mp[arr[i]];
        rows[hs/n]++;
        if(rows[hs/n] == n) return i;
        cols[hs % n]++;
        if(cols[hs % n] == m) return i;
    }

    return m * n - 1;
}