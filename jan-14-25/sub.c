/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findThePrefixCommonArray(int* A, int n, int* B, int BSize, int* returnSize) {
    int mp[51] = {};

    int comm = 0;
    int* ans = malloc(sizeof(int) * n);

    for(int i = 0; i<n; i++){
        mp[A[i]]++;
        if(mp[A[i]] == 2) comm++;
        mp[B[i]]++;
        if(mp[B[i]] == 2) comm++;

        ans[i] = comm;
    }

    *returnSize = n;
    return ans;
}