class Solution {
    public boolean canConstruct(String s, int k) {
        if(s.length() < k) return false;
        if(s.length() == k) return true;

        int mp[] = new int[26];

        for(char i: s.toCharArray()){
            mp[i - 'a'] ^= 1;
        }

        for(int i: mp) k -= i;

        return k > -1;
    }
}