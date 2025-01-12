class Solution {
    public boolean canBeValid(String s, String locked) {
        int bt = -1, dt = -1;
        int n = s.length();
        int dbit[] = new int[n], bracket[] = new int[n];

        for (int i = 0; i<n; i++) {
            if (locked.charAt(i) == '0')
                dbit[++dt] = i;

            else if (s.charAt(i) == '(')
                bracket[++bt] = i;

            else {
                if (bt >= 0)
                    bt--;
                else if (dt >= 0)
                    dt--;
                else
                    return false;
            }
        }

        while (bt >= 0 && dt >= 0 && bracket[bt] < dbit[dt]){
            bt--; dt--;
        }

        if (bt >= 0)
            return false;

        return (dt + 1) % 2 == 0;
    }
}