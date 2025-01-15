class Solution {
    public int minimizeXor(int num1, int num2) {
        int setBits = 0;
        for(;num2 > 0;num2 >>= 1) setBits += num2 & 1;

        int temp = 0;
        int n = 0;
        int ans = 0;

        for(;num1 > 0; num1 >>= 1, n++) temp = (temp << 1) + (num1 & 1);

        while(n > 0){
            if(n <= setBits || setBits == 0) break;

            if((temp & 1) == 1){
                ans = (ans << 1) + 1;
                setBits--;
            }
            else ans = ans << 1;

            temp >>= 1;
            n--;
        }

        if(setBits > 0){
            ans <<= setBits;
            ans += (1 << setBits) - 1;
            n -= setBits;
        }

        if(n > 0) ans = ans << n;

        return ans;
    }
}