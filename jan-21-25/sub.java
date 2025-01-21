class Solution {
    public long gridGame(int[][] grid) {
        long p1 = 0, p2 = 0, curr = Long.MAX_VALUE, ans = Long.MAX_VALUE;

        for(int i: grid[0]) p1 += i;

        int n = grid[0].length;

        for(int i = 0; i<n; i++){
            p1 -= grid[0][i];
            curr = Math.max(p1,p2);
            if(curr <= ans) ans = curr;
            else break;
            p2 += grid[1][i];
        }

        return ans;
    }
}