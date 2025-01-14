class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;
        int[] mp = new int[n+1];
        int[] ans = new int[n];

        int com = 0;

        for(int i = 0; i<n; i++){
            mp[A[i]]++;
            if(mp[A[i]] == 2) com++;
            mp[B[i]]++;
            if(mp[B[i]] == 2) com++;
            ans[i] = com;
        }

        return ans;
    }
}