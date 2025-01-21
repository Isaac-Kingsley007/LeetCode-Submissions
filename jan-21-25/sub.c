#include <limits.h>
#define max(a,b) (((a) > (b)) ? (a) : (b))

long long gridGame(int** grid, int bliyat, int* gridColSize) {
    long long p1 = 0, p2 = 0, curr = LLONG_MAX, ans = LLONG_MAX;
    int n = *gridColSize;

    for(int i = 0; i<n; i++) p1 += grid[0][i];


    for(int i = 0; i<n; i++){
        p1 -= grid[0][i];
        curr = max(p1,p2);
        if(curr <= ans) ans = curr;
        else break;
        p2 += grid[1][i];
    }

    return ans;
}